/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_commands.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalvez- <mgalvez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 14:58:14 by mgalvez-          #+#    #+#             */
/*   Updated: 2025/06/24 14:58:15 by mgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief Attempts to execute a command directly using its path.
 *
 * If the file exists at the given path, tries to execute it using execve.
 * Returns -1 if execution fails or the file does not exist.
 *
 * @param command_list Pointer to the command list node.
 * @param shell_data Pointer to the main shell data structure.
 * @return -1 if execution fails.
 */
static int	ft_try_direct_exec(t_command_list *command_list,
	t_shell_data *shell_data)
{
	if (!access(command_list->str[0], F_OK))
		execve(command_list->str[0], command_list->str, shell_data->envp);
	return (-1);
}

/**
 * @brief Attempts to execute a command by searching through the PATH
 * directories.
 *
 * Iterates through all directories in shell_data->paths, constructs
 * the full path, and tries to execute the command using execve.
 * Frees the constructed path after each attempt.
 *
 * @param command_list Pointer to the command list node.
 * @param shell_data Pointer to the main shell data structure.
 * @return -1 if execution fails for all paths.
 */
static int	ft_try_path_exec(t_command_list *command_list,
	t_shell_data *shell_data)
{
	int		index;
	char	*full_command;

	index = 0;
	while (shell_data->paths[index] != NULL)
	{
		full_command = ft_strjoin(shell_data->paths[index],
				command_list->str[0]);
		if (full_command)
		{
			if (!access(full_command, F_OK))
				execve(full_command, command_list->str, shell_data->envp);
			free(full_command);
		}
		index++;
	}
	return (-1);
}

int	ft_find_command(t_command_list *command_list, t_shell_data *shell_data)
{
	command_list->str = ft_resplit_str(command_list->str);
	if (!command_list->str || !command_list->str[0])
		return (ft_error_print_command_not_found(""));
	ft_try_direct_exec(command_list, shell_data);
	if (!shell_data->paths)
		return (ft_error_print_command_not_found(command_list->str[0]));
	ft_try_path_exec(command_list, shell_data);
	return (ft_error_print_command_not_found(command_list->str[0]));
}

int	ft_execute_command(t_command_list *command_list, t_shell_data *shell_data)
{
	int	exit_code;

	exit_code = 0;
	if (command_list->redirections)
	{
		if (ft_handle_redirections(command_list))
			exit(EXIT_FAILURE);
	}
	if (command_list->builtin != NULL)
		exit_code = command_list->builtin(shell_data, command_list);
	else if (command_list->str
		&& command_list->str[0]
		&& command_list->str[0][0] != '\0')
		exit_code = ft_find_command(command_list, shell_data);
	else
		exit_code = 0;
	return (exit_code);
}

void	ft_dup_command(t_command_list *command_list, t_shell_data *shell_data,
	int pipe_fd[2], int fd_in)
{
	if (command_list->prev && (dup2(fd_in, STDIN_FILENO) < 0))
		ft_error_handle_msg(ERR_PIPE, shell_data);
	if (pipe_fd[0] != -1)
		close(pipe_fd[0]);
	if (command_list->next && dup2(pipe_fd[1], STDOUT_FILENO) < 0)
		ft_error_handle_msg(ERR_PIPE, shell_data);
	if (pipe_fd[1] != -1)
		close(pipe_fd[1]);
	if (command_list->prev && fd_in != STDIN_FILENO)
		close(fd_in);
	exit(ft_execute_command(command_list, shell_data));
}
