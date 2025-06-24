/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalvez- <mgalvez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 14:58:12 by mgalvez-          #+#    #+#             */
/*   Updated: 2025/06/24 14:58:13 by mgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief Handles the execution of a pipeline of commands.
 *
 * Allocates memory for the array of process IDs (pid) needed for the pipeline,
 * calls the pipeline execution routine, and returns EXIT_SUCCESS on success.
 * If memory allocation fails, prints an error and returns EXIT_FAILURE.
 *
 * @param shell_data Pointer to the main shell data structure.
 * @return EXIT_SUCCESS on success, EXIT_FAILURE on memory allocation error.
 */
static int	ft_handle_pipeline_command(t_shell_data *shell_data)
{
	shell_data->pid = ft_calloc(sizeof(int), shell_data->pipes + 2);
	if (!shell_data->pid)
		return (ft_error_handle_msg(ERR_MEMORY, shell_data));
	ft_execute_pipeline_command(shell_data);
	return (EXIT_SUCCESS);
}

int	ft_execute_commands(t_shell_data *shell_data)
{
	signal(SIGQUIT, ft_sigquit_handler);
	shell_data->state.is_in_cmd = true;
	if (shell_data->pipes == 0)
		ft_handle_command(shell_data->command_list, shell_data);
	else
	{
		if (ft_handle_pipeline_command(shell_data) != EXIT_SUCCESS)
			return (EXIT_FAILURE);
	}
	shell_data->state.is_in_cmd = false;
	return (EXIT_SUCCESS);
}
