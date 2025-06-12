#include "minishell.h"

static int	ft_process_heredoc_line(t_lexer_list *heredoc, bool is_quoted,
	t_shell_data *shell_data, int fd)
{
	char	*line;

	line = readline(COLOR_BLUE MSG_HEREDOC COLOR_RESET);
	if (!line)
		return (false);
	if (ft_strncmp(line, heredoc->str, ft_strlen(heredoc->str) + 1) == 0)
	{
		free(line);
		return (false);
	}
	if (!is_quoted)
		line = ft_expand_str(shell_data, line);
	write(fd, line, ft_strlen(line));
	write(fd, "\n", 1);
	free(line);
	return (true);
}

int	ft_create_heredoc(t_lexer_list *heredoc, bool is_quoted,
	t_shell_data *shell_data, char *file_name)
{
	int		fd;

	fd = open(file_name, O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (fd < 0)
		return (EXIT_FAILURE);
	while (ft_process_heredoc_line(heredoc, is_quoted, shell_data, fd))
		;
	close(fd);
	if (shell_data->state.should_stop_heredoc)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static bool	ft_is_quoted(const char *str)
{
	size_t	len;

	len = ft_strlen(str);
	if (len < 2)
		return (false);
	if ((str[0] == SYMBOL_QUOTE_DOUBLE && str[len - 1] == SYMBOL_QUOTE_DOUBLE)
		|| (str[0] == SYMBOL_QUOTE && str[len - 1] == SYMBOL_QUOTE))
		return (true);
	return (false);
}

int	ft_process_heredoc(t_shell_data *shell_data, t_lexer_list *heredoc,
	char *file_name)
{
	bool	is_quoted;
	int		result;

	result = EXIT_SUCCESS;
	is_quoted = ft_is_quoted(heredoc->str);
	ft_del_quotes(heredoc->str, SYMBOL_QUOTE_DOUBLE);
	ft_del_quotes(heredoc->str, SYMBOL_QUOTE);
	shell_data->state.should_stop_heredoc = false;
	g_is_in_heredoc = true;
	result = ft_create_heredoc(heredoc, is_quoted, shell_data, file_name);
	g_is_in_heredoc = false;
	shell_data->heredoc = true;
	return (result);
}

int	ft_handle_heredoc(t_shell_data *shell_data, t_commands_list *cmd)
{
	t_lexer_list	*redir;
	int				result;

	redir = cmd->redirections;
	result = EXIT_SUCCESS;
	while (redir)
	{
		if (redir->token == REDIRECT_HEREDOC)
		{
			if (cmd->hd_file_name)
				free(cmd->hd_file_name);
			cmd->hd_file_name = ft_create_heredoc_filename();
			result = ft_process_heredoc(shell_data, redir, cmd->hd_file_name);
			if (result != EXIT_SUCCESS)
			{
				shell_data->state.error_num = 1;
				return (ft_reset_shell_loop(shell_data));
			}
		}
		redir = redir->next;
	}
	return (EXIT_SUCCESS);
}
