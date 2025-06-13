#include "minishell.h"

void	ft_error_print_msg_token(t_token token)
{
	ft_putstr_fd(COLOR_RED_BOLD MSG_DEFAULT_PROMPT COLOR_RESET
		MSG_ERR_SYNTAX_TOKEN, STDERR_FILENO);
	if (token == REDIRECT_OUT)
		ft_putstr_fd(SYMBOL_CHAR_GREATER_THAN, STDERR_FILENO);
	else if (token == REDIRECT_OUT_APPEND)
		ft_putstr_fd(SYMBOL_CHAR_DOUBLE_GREATER_THAN, STDERR_FILENO);
	else if (token == REDIRECT_IN)
		ft_putstr_fd(SYMBOL_CHAR_LESS_THAN, STDERR_FILENO);
	else if (token == REDIRECT_HEREDOC)
		ft_putstr_fd(SYMBOL_CHAR_DOUBLE_LESS_THAN, STDERR_FILENO);
	else if (token == PIPE)
		ft_putstr_fd(SYMBOL_CHAR_PIPE, STDERR_FILENO);
	else
		ft_putstr_fd("", STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
}

int	ft_error_handle_msg(int error_type, t_shell_data *shell_data)
{
	ft_putstr_fd(COLOR_RED_BOLD MSG_DEFAULT_PROMPT COLOR_RESET,
		STDERR_FILENO);
	if (error_type == ERR_OPEN_FD)
		ft_putstr_fd(MSG_ERR_OPEN_FD, STDERR_FILENO);
	if (error_type == ERR_SYNTAX)
		ft_putstr_fd(MSG_ERR_SYNTAX, STDERR_FILENO);
	else if (error_type == ERR_MEMORY)
		ft_putstr_fd(MSG_ERR_MEMORY, STDERR_FILENO);
	else if (error_type == ERR_QUOTE)
		ft_putstr_fd(MSG_ERR_QUOTE, STDERR_FILENO);
	else if (error_type == ERR_PARSER)
		ft_putstr_fd(MSG_ERR_PARSER, STDERR_FILENO);
	else if (error_type == ERR_PIPE)
		ft_putstr_fd(MSG_ERR_PIPE, STDERR_FILENO);
	else if (error_type == ERR_FORK)
		ft_putstr_fd(MSG_ERR_FORK, STDERR_FILENO);
	else if (error_type == ERR_REDIRECT_OUT)
		ft_putstr_fd(MSG_ERR_REDIRECT_OUT, STDERR_FILENO);
	else if (error_type == ERR_REDIRECT_IN)
		ft_putstr_fd(MSG_ERR_REDIRECT_IN, STDERR_FILENO);
	else if (error_type == ERR_PATH)
		ft_putendl_fd(MSG_ERR_PATH, STDERR_FILENO);
	ft_reset_shell_loop(shell_data);
	return (EXIT_FAILURE);
}

int	ft_error_print_command_not_found(char *str)
{
	ft_putstr_fd(COLOR_RED_BOLD MSG_DEFAULT_PROMPT COLOR_RESET,
		STDERR_FILENO);
	ft_putstr_fd(str, STDERR_FILENO);
	ft_putstr_fd(MSG_ERR_CMD_NOT_FOUND, STDERR_FILENO);
	return (127);
}

int	ft_error_print_export(char *c)
{
	ft_putstr_fd(COLOR_RED_BOLD MSG_DEFAULT_PROMPT COLOR_RESET "export: ",
		STDERR_FILENO);
	if (c)
	{
		ft_putchar_fd('\'', STDERR_FILENO);
		ft_putstr_fd(c, STDERR_FILENO);
		ft_putstr_fd("\': is ", STDERR_FILENO);
	}
	ft_putendl_fd("not a valid identifier", STDERR_FILENO);
	return (EXIT_FAILURE);
}

void	ft_error_print_unset_slash_error(t_command_list *command_list)
{
	ft_putstr_fd(COLOR_RED_BOLD MSG_DEFAULT_PROMPT COLOR_RESET,
		STDERR_FILENO);
	ft_putstr_fd("unset: '", STDERR_FILENO);
	ft_putstr_fd(command_list->str[1], STDERR_FILENO);
	ft_putendl_fd("': " MSG_ERR_UNSET_INVALID_ID, STDERR_FILENO);
}
