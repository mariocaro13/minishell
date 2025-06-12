#include "minishell.h"

int	ft_fork(t_shell_data *shell_data, int pipe_fd[2],
	int fd_in, t_commands_list *command)
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
