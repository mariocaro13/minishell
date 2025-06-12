#include "minishell.h"

int	ft_check_append_outfile(t_lexer_list *redirections)
{
	int	flags;

	if (!redirections || !redirections->str)
		return (-1);
	flags = O_CREAT | O_WRONLY;
	if (redirections->token == REDIRECT_OUT_APPEND)
		flags |= O_APPEND;
	else
		flags |= O_TRUNC;
	return (open(redirections->str, flags, 0644));
}

int	ft_handle_infile(char *file_name)
{
	int	fd;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd(COLOR_RED_BOLD MSG_PROMPT COLOR_RESET MSG_ERR_REDIRECT_IN,
			STDERR_FILENO);
		ft_putstr_fd(file_name, STDERR_FILENO);
		ft_putstr_fd("\n", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	if (fd != STDIN_FILENO)
	{
		if (dup2(fd, STDIN_FILENO) < 0)
		{
			ft_putstr_fd(COLOR_RED_BOLD MSG_PROMPT COLOR_RESET MSG_ERR_PIPE,
				STDERR_FILENO);
			close(fd);
			return (EXIT_FAILURE);
		}
		close(fd);
	}
	return (EXIT_SUCCESS);
}

int	ft_handle_outfile(t_lexer_list *redirection)
{
	int	fd;

	fd = ft_check_append_outfile(redirection);
	if (fd < 0)
	{
		ft_putstr_fd(COLOR_RED_BOLD MSG_PROMPT COLOR_RESET MSG_ERR_REDIRECT_OUT,
			STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	if (fd != STDOUT_FILENO)
	{
		if (dup2(fd, STDOUT_FILENO) < 0)
		{
			ft_putstr_fd(COLOR_RED_BOLD MSG_PROMPT COLOR_RESET MSG_ERR_PIPE,
				STDERR_FILENO);
			close(fd);
			return (EXIT_FAILURE);
		}
		close(fd);
	}
	return (EXIT_SUCCESS);
}

int	ft_handle_redirections(t_commands_list *cmd)
{
	t_lexer_list	*current;

	current = cmd->redirections;
	while (current)
	{
		if (current->token == REDIRECT_IN)
		{
			if (ft_handle_infile(current->str))
				return (EXIT_FAILURE);
		}
		else if (current->token == REDIRECT_OUT
			|| current->token == REDIRECT_OUT_APPEND)
		{
			if (ft_handle_outfile(current))
				return (EXIT_FAILURE);
		}
		else if (current->token == REDIRECT_HEREDOC)
		{
			if (ft_handle_infile(cmd->hd_file_name))
				return (EXIT_FAILURE);
			unlink(cmd->hd_file_name);
		}
		current = current->next;
	}
	return (EXIT_SUCCESS);
}
