/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalvez- <mgalvez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 14:57:27 by mgalvez-          #+#    #+#             */
/*   Updated: 2025/06/24 14:57:28 by mgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	g_is_in_heredoc;

/**
 * @brief Entry point for the minishell program.
 *
 * This function:
 *   - Checks for correct usage (no extra arguments).
 *   - Initializes the shell data and environment.
 *   - Sets up the history file path and loads previous history.
 *   - Prints a welcome message.
 *   - Starts the main shell loop.
 *   - On exit, clears the readline history and frees resources.
 *
 * @param argc Argument count (should be 1 for correct usage).
 * @param argv Argument vector.
 * @param envp Environment variables.
 * @return EXIT_SUCCESS on normal exit, EXIT_FAILURE on initialization error.
 */
int	main(int argc, char **argv, char **envp)
{
	t_shell_data	shell_data;

	if (argc != 1 || argv[1])
	{
		printf(MSG_USAGE);
		exit(0);
	}
	if (ft_init_shell(&shell_data, envp) != EXIT_SUCCESS)
	{
		ft_putstr_fd(COLOR_RED MSG_DEFAULT_PROMPT COLOR_RESET MSG_ERR_INIT,
			STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	shell_data.history_path = ft_make_history_path(shell_data.pwd);
	if (!shell_data.history_path)
		shell_data.history_path = ft_strdup(HISTORY_FILE);
	ft_load_history_from_file(shell_data.history_path);
	printf(MSG_WELCOME);
	ft_shell_loop(&shell_data);
	rl_clear_history();
	free(shell_data.history_path);
	return (EXIT_SUCCESS);
}
