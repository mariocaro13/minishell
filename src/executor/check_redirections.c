#include "minishell.h"

int	check_append_outfile(t_lexer_list *redirections)
{
	int	fd;

	if (redirections->token == REDIRECT_OUT_APPEND)
		fd = open(redirections->str,
				O_CREAT | O_RDWR | O_APPEND, 0644);
	else
		fd = open(redirections->str,
				O_CREAT | O_RDWR | O_TRUNC, 0644);
	return (fd);
}

int	handle_infile(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd(COLOR_RED_BOLD MSG_PROMPT COLOR_RESET "infile: No such file or directory\n",
			STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	if (fd > 0 && dup2(fd, STDIN_FILENO) < 0)
	{
		ft_putstr_fd(COLOR_RED_BOLD MSG_PROMPT COLOR_RESET "pipe error\n", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	if (fd > 0)
		close(fd);
	return (EXIT_SUCCESS);
}

int	handle_outfile(t_lexer_list *redirection)
{
	int	fd;

	fd = check_append_outfile(redirection);
	if (fd < 0)
	{
		ft_putstr_fd(COLOR_RED_BOLD MSG_PROMPT COLOR_RESET "outfile: Error\n", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	if (fd > 0 && dup2(fd, STDOUT_FILENO) < 0)
	{
		ft_putstr_fd(COLOR_RED_BOLD MSG_PROMPT COLOR_RESET "pipe error\n", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	if (fd > 0)
		close(fd);
	return (EXIT_SUCCESS);
}

int	check_redirections(t_commands_list *cmd)
{
	t_lexer_list	*start;

	start = cmd->redirections;
	while (cmd->redirections)
	{
		if (cmd->redirections->token == REDIRECT_IN)
		{
			if (handle_infile(cmd->redirections->str))
				return (EXIT_FAILURE);
		}
		else if (cmd->redirections->token == REDIRECT_OUT
			|| cmd->redirections->token == REDIRECT_OUT_APPEND)
		{
			if (handle_outfile(cmd->redirections))
				return (EXIT_FAILURE);
		}
		else if (cmd->redirections->token == REDIRECT_HEREDOC)
		{
			if (handle_infile(cmd->hd_file_name))
				return (EXIT_FAILURE);
		}
		cmd->redirections = cmd->redirections->next;
	}
	cmd->redirections = start;
	return (EXIT_SUCCESS);
}
