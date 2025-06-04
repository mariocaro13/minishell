#include "minishell.h"

char	*ft_join_heredoc(char *str_1, char *str_2)
{
	char	*with_space;
	char	*result;

	if (!str_2)
		return (ft_strdup(str_1));
	with_space = ft_strjoin(str_1, " ");
	result = ft_strjoin(with_space, str_2);
	free(with_space);
	free(str_2);
	return (result);
}

int	create_heredoc(t_lexer_list *heredoc, bool quotes,
	t_shell_data *shell_data, char *file_name)
{
	int		fd;
	char	*line;

	fd = open(file_name, O_CREAT | O_RDWR | O_TRUNC, 0644);
	line = readline(MSG_HEREDOC);
	while (line && ft_strncmp(heredoc->str, line, ft_strlen(heredoc->str))
		&& !g_shell_state.should_stop_heredoc)
	{
		if (quotes == false)
			line = expander_str(shell_data, line);
		write(fd, line, ft_strlen(line));
		write(fd, "\n", 1);
		free(line);
		line = readline(MSG_HEREDOC);
	}
	free(line);
	if (g_shell_state.should_stop_heredoc || !line)
		return (EXIT_FAILURE);
	close(fd);
	return (EXIT_SUCCESS);
}

int	ft_heredoc(t_shell_data *shell_data, t_lexer_list *heredoc, char *file_name)
{
	bool	quotes;
	int		sl;

	sl = EXIT_SUCCESS;
	if ((heredoc->str[0] == '\"'
			&& heredoc->str[ft_strlen(heredoc->str) - 1] == '\"')
		|| (heredoc->str[0] == '\''
			&& heredoc->str[ft_strlen(heredoc->str) - 1] == '\''))
		quotes = true;
	else
		quotes = false;
	ft_del_quotes(heredoc->str, '\"');
	ft_del_quotes(heredoc->str, '\'');
	g_shell_state.should_stop_heredoc = false;
	g_shell_state.is_in_heredoc = true;
	sl = create_heredoc(heredoc, quotes, shell_data, file_name);
	g_shell_state.is_in_heredoc = false;
	shell_data->heredoc = true;
	return (sl);
}

char	*generate_heredoc_filename(void)
{
	static int	index = 0;
	char		*num;
	char		*file_name;

	num = ft_itoa(index++);
	file_name = ft_strjoin("build/.tmp_heredoc_file_", num);
	free(num);
	return (file_name);
}

int	send_heredoc(t_shell_data *shell_data, t_commands_list *cmd)
{
	t_lexer_list	*start;
	int		sl;

	start = cmd->redirections;
	sl = EXIT_SUCCESS;
	while (cmd->redirections)
	{
		if (cmd->redirections->token == REDIRECT_HEREDOC)
		{
			if (cmd->hd_file_name)
				free(cmd->hd_file_name);
			cmd->hd_file_name = generate_heredoc_filename();
			sl = ft_heredoc(shell_data, cmd->redirections, cmd->hd_file_name);
			if (sl)
			{
				g_shell_state.error_num = 1;
				return (ft_reset_shell_loop(shell_data));
			}
		}
		cmd->redirections = cmd->redirections->next;
	}
	cmd->redirections = start;
	return (EXIT_SUCCESS);
}

int	check_fd_heredoc(t_shell_data *shell_data, int end[2], t_commands_list *cmd)
{
	int	fd_in;

	if (shell_data->heredoc)
	{
		close(end[0]);
		fd_in = open(cmd->hd_file_name, O_RDONLY);
	}
	else
		fd_in = end[0];
	return (fd_in);
}
