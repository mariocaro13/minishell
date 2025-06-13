#include "minishell.h"

void	ft_error_parser(int error, t_shell_data *shell_data,
	t_lexer_list *lexer_list)
{
	ft_lexer_clear(&lexer_list);
	if (shell_data->command_list)
	{
		ft_command_list_clear(&shell_data->command_list);
		shell_data->command_list = NULL;
	}
	ft_error_handle_msg(error, shell_data);
}

int	ft_error_parser_token(t_shell_data *shell_data, t_lexer_list *lexer_list,
	t_token token)
{
	ft_error_print_msg_token(token);
	ft_lexer_clear(&lexer_list);
	ft_reset_shell_loop(shell_data);
	return (EXIT_FAILURE);
}

int	ft_error_pipe_handler(t_shell_data *shell_data, t_token token)
{
	if (token == PIPE)
	{
		ft_error_parser_token(shell_data, shell_data->lexer_list,
			shell_data->lexer_list->token);
		return (EXIT_FAILURE);
	}
	if (!shell_data->lexer_list)
	{
		ft_error_parser(ERR_SYNTAX, shell_data, shell_data->lexer_list);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
