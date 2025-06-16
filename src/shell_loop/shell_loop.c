#include "minishell.h"

/**
 * @brief Reads and processes a line of input from the user.
 *
 * This function:
 *   - Prompts the user and reads a line.
 *   - Trims whitespace from the input.
 *   - If the input is NULL (EOF), prints an exit message and exits the shell.
 *   - If the input is empty, resets the shell loop.
 *
 * @param shell_data Pointer to the main shell data structure.
 * @return EXIT_SUCCESS on valid input, or the result of resetting the shell
 * loop.
 */
static int	ft_handle_input_line(t_shell_data *shell_data)
{
	shell_data->args = ft_get_trimmed_line(shell_data);
	if (!shell_data->args)
	{
		ft_putendl_fd(COLOR_YELLOW MSG_DEFAULT_PROMPT COLOR_RESET
			MSG_EXIT, STDOUT_FILENO);
		exit(EXIT_SUCCESS);
	}
	if (shell_data->args[0] == '\0')
		return (ft_reset_shell_loop(shell_data));
	return (EXIT_SUCCESS);
}

/**
 * @brief Validates the user input for syntax correctness.
 *
 * This function:
 *   - Checks if all quotes in the input are closed.
 *   - Builds the token list from the input.
 *   - Handles errors if quotes are not closed or memory allocation fails.
 *
 * @param shell_data Pointer to the main shell data structure.
 * @return EXIT_SUCCESS if input is valid, otherwise an error handler result.
 */
static int	ft_validate_input(t_shell_data *shell_data)
{
	if (!ft_are_quotes_closed(shell_data->args))
		return (ft_error_handle_msg(ERR_QUOTE, shell_data));
	if (!ft_build_token_list(shell_data))
		return (ft_error_handle_msg(ERR_MEMORY, shell_data));
	return (EXIT_SUCCESS);
}

int	ft_shell_loop(t_shell_data *shell_data)
{
	ft_handle_input_line(shell_data);
	ft_add_to_history(shell_data->args, shell_data);
	ft_validate_input(shell_data);
	ft_parse_lexer_list(shell_data);
	ft_execute_commands(shell_data);
	ft_reset_shell_loop(shell_data);
	return (EXIT_SUCCESS);
}
