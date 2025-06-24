/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_pipeline_command.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalvez- <mgalvez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 14:58:09 by mgalvez-          #+#    #+#             */
/*   Updated: 2025/06/24 14:58:10 by mgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief Forks a new process for a command in the pipeline.
 *
 * Stores the child PID in shell_data->pid. In the child process,
 * sets default SIGINT handling and calls ft_dup_command to set up file
 * descriptors and execute the command.
 * Resets the static index if shell_data->reset is true.
 *
 * @param shell_data Pointer to the main shell data structure.
 * @param pipe_fd Array with the pipe file descriptors for this command.
 * @param fd_in File descriptor for input (previous pipe or STDIN).
 * @param command Pointer to the command list node to execute.
 * @return EXIT_SUCCESS always.
 */
static int	ft_fork(t_shell_data *shell_data, int pipe_fd[2],
	int fd_in, t_command_list *command)
{
	static int	index = 0;

	if (shell_data->reset == true)
	{
		index = 0;
		shell_data->reset = false;
	}
	shell_data->pid[index] = fork();
	if (shell_data->pid[index] < 0)
		ft_error_handle_msg(ERR_FORK, shell_data);
	if (shell_data->pid[index] == 0)
	{
		signal(SIGINT, SIG_DFL);
		ft_dup_command(command, shell_data, pipe_fd, fd_in);
	}
	index++;
	return (EXIT_SUCCESS);
}

/**
 * @brief Sets up the pipe file descriptors for the current command in the
 * pipeline.
 *
 * If the current command has a next command, creates a new pipe and stores
 * its file descriptors in pipe_fd. If it is the last command, sets pipe_fd[0]
 * and pipe_fd[1] to -1.
 *
 * @param shell_data Pointer to the main shell data structure.
 * @param pipe_fd Array to store the pipe file descriptors.
 */
static void	ft_setup_pipe_for_command(t_shell_data *shell_data, int pipe_fd[2])
{
	if (shell_data->command_list->next)
		pipe(pipe_fd);
	else
	{
		pipe_fd[0] = -1;
		pipe_fd[1] = -1;
	}
}

int	ft_execute_pipeline_command(t_shell_data *shell_data)
{
	int		pipe_fd[2];
	int		fd_in;

	fd_in = STDIN_FILENO;
	while (shell_data->command_list)
	{
		ft_expander_caller(shell_data, &shell_data->command_list);
		ft_setup_pipe_for_command(shell_data, pipe_fd);
		ft_handle_heredoc(shell_data, shell_data->command_list);
		ft_fork(shell_data, pipe_fd, fd_in, shell_data->command_list);
		if (pipe_fd[1] != -1)
			close(pipe_fd[1]);
		if (shell_data->command_list->prev)
			close(fd_in);
		fd_in = ft_get_fd_heredoc(shell_data, pipe_fd,
				shell_data->command_list);
		if (shell_data->command_list->next)
			shell_data->command_list = shell_data->command_list->next;
		else
			break ;
	}
	ft_pipe_wait(shell_data, shell_data->pid, shell_data->pipes);
	shell_data->command_list = ft_command_list_get_first(
			shell_data->command_list);
	return (EXIT_SUCCESS);
}
