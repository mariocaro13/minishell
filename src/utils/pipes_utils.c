/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalvez- <mgalvez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 15:09:40 by mgalvez-          #+#    #+#             */
/*   Updated: 2025/06/24 15:09:41 by mgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "minishell.h"

/**
 * @brief Waits for a single child process and updates the last status and
 * interruption flag.
 *
 * Calls waitpid for the given pid, checks if the process was interrupted
 * by SIGINT, and updates the is_interrupted flag and last_status accordingly.
 *
 * @param pid Process ID to wait for.
 * @param last_status Pointer to store the exit status.
 * @param is_interrupted Pointer to a flag set to true if SIGINT was received.
 */
static void	ft_wait_for_child(int pid, int *last_status, bool *is_interrupted)
{
	int	status;

	status = 0;
	waitpid(pid, &status, 0);
	if (WIFSIGNALED(status) && WTERMSIG(status) == SIGINT)
		*is_interrupted = true;
	*last_status = status;
}

/**
 * @brief Waits for all child processes in a pipeline and updates
 * status/interruption.
 *
 * Iterates over all pids, waits for each child, and updates the
 * last_status and is_interrupted flag.
 *
 * @param pid Array of process IDs.
 * @param amount Number of processes to wait for.
 * @param last_status Pointer to store the last exit status.
 * @param is_interrupted Pointer to a flag set to true if any child was
 * interrupted by SIGINT.
 */
static void	ft_wait_for_all_children(int *pid, int amount,
	int *last_status, bool *is_interrupted)
{
	int	index;

	index = 0;
	*is_interrupted = false;
	while (index < amount)
	{
		ft_wait_for_child(pid[index], last_status, is_interrupted);
		index++;
	}
}

void	ft_remove_leading_pipe(t_shell_data *shell_data)
{
	if (shell_data->lexer_list && shell_data->lexer_list->token == PIPE)
		ft_lexer_del_by_index(&shell_data->lexer_list,
			shell_data->lexer_list->index);
}

int	ft_count_pipes_in_lexer(t_lexer_list *lexer_list)
{
	int	count;

	count = 0;
	while (lexer_list)
	{
		if (lexer_list->token == PIPE)
			count++;
		lexer_list = lexer_list->next;
	}
	return (count);
}

int	ft_pipe_wait(t_shell_data *shell_data, int *pid, int amount)
{
	bool	is_interrupted;
	int		last_status;

	last_status = 0;
	is_interrupted = false;
	signal(SIGINT, SIG_IGN);
	ft_wait_for_all_children(pid, amount, &last_status, &is_interrupted);
	if (is_interrupted)
		ft_putstr_fd("\n", STDERR_FILENO);
	waitpid(pid[amount], &last_status, 0);
	if (WIFEXITED(last_status))
		shell_data->state.error_num = WEXITSTATUS(last_status);
	else if (WIFSIGNALED(last_status))
		shell_data->state.error_num = 128 + WTERMSIG(last_status);
	else
		shell_data->state.error_num = EXIT_FAILURE;
	signal(SIGINT, ft_sigint_handler);
	return (EXIT_SUCCESS);
}
