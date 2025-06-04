#include "minishell.h"

static int	ft_handle_input_line(t_shell_data *shell_data)
{
	shell_data->args = ft_get_trimmed_line();
	if (!shell_data->args)
	{
		ft_putendl_fd(COLOR_YELLOW MSG_EXIT COLOR_RESET, STDOUT_FILENO);
		exit(EXIT_SUCCESS);
	}
	if (shell_data->args[0] == '\0')
		return (ft_reset_shell_loop(shell_data));
	return (EXIT_SUCCESS);
}

static int	ft_validate_input(t_shell_data *t_shell_data)
{
	if (!ft_are_quotes_closed(t_shell_data->args))
		return (ft_error_handle_msg(ERR_QUOTE, t_shell_data));
	if (!ft_build_token_list(t_shell_data))
		return (ft_error_handle_msg(ERR_MEMORY, t_shell_data));
	return (EXIT_SUCCESS);
}

int	ft_shell_loop(t_shell_data *shell_data)
{
	ft_handle_input_line(shell_data);
	add_history(shell_data->args);
	ft_validate_input(shell_data);
	ft_parse_lexer_list(shell_data);
	ft_execute_commands(shell_data);
	ft_reset_shell_loop(shell_data);
	return (EXIT_SUCCESS);
}
