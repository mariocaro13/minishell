#include "minishell.h"

int	ft_pipe_wait(t_shell_data *shell_data, int *pid, int amount)
{
	int		index;
	int		status;
	bool	is_interrupted;
	int		last_status;

	index = 0;
	is_interrupted = false;
	signal(SIGINT, SIG_IGN);
	while (index < amount)
	{
		waitpid(pid[index], &status, 0);
		if (WIFSIGNALED(status) && WTERMSIG(status) == SIGINT)
			is_interrupted = true;
		last_status = status;
		index++;
	}
	if (is_interrupted)
		ft_putstr_fd("\n", STDERR_FILENO);
	waitpid(pid[index], &status, 0);
	if (WIFEXITED(last_status))
		shell_data->state.error_num = WEXITSTATUS(last_status);
	return (EXIT_SUCCESS);
}

int	ft_fork(t_shell_data *shell_data, int end[2], int fd_in, t_commands_list *command)
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
		dup_cmd(command, shell_data, end, fd_in);
	}
	index++;
	return (EXIT_SUCCESS);
}

int	ft_execute_pipeline_command(t_shell_data *shell_data)
{
	int		end[2];
	int		fd_in;
	
	fd_in = STDIN_FILENO;
	while (shell_data->commands_list)
	{
		ft_expander_caller(shell_data, &shell_data->commands_list);
		if (shell_data->commands_list->next)
			pipe(end);
		ft_send_heredoc(shell_data, shell_data->commands_list);
		ft_fork(shell_data, end, fd_in, shell_data->commands_list);
		close(end[1]);
		if (shell_data->commands_list->prev)
			close(fd_in);
		fd_in = check_fd_heredoc(shell_data, end, shell_data->commands_list);
		if (shell_data->commands_list->next)
			shell_data->commands_list = shell_data->commands_list->next;
		else
			break ;
	}
	ft_pipe_wait(shell_data, shell_data->pid, shell_data->pipes);
	shell_data->commands_list = ft_command_list_get_first(shell_data->commands_list);
	return (0);
}

static bool ft_is_builtin_command(t_commands_list *command)
{
	return (command->builtin == ft_cd
		|| command->builtin == ft_exit
		|| command->builtin == ft_export
		|| command->builtin == ft_unset);
}

static int	ft_run_builtin(t_commands_list *command,t_shell_data *shell_data)
{
	return (command->builtin(shell_data, command));
}

static int	ft_run_command(t_commands_list *command, t_shell_data *shell_data)
{
	int	pid;
	int	status;

	ft_send_heredoc(shell_data, command);
	pid = fork();
	if (pid < 0)
		return (ft_error_handle_msg(ERR_FORK, shell_data));
	if (pid == 0)
	{
		signal(SIGINT, SIG_DFL);
		handle_cmd(command, shell_data);
		exit(EXIT_SUCCESS);
	}
	signal(SIGINT, SIG_IGN);
	waitpid(pid, &status, 0);
	signal(SIGINT, ft_sigint_handler);
	if (WIFSIGNALED(status) && WTERMSIG(status) == SIGINT)
		ft_putstr_fd("\n", STDERR_FILENO);
	if (WIFEXITED(status))
	{
		shell_data->state.error_num = WEXITSTATUS(status);
		return (WEXITSTATUS(status));
	}
	return (EXIT_FAILURE);
}

void	ft_handle_command(t_commands_list *command, t_shell_data *shell_data)
{
	ft_expander_caller(shell_data, &shell_data->commands_list);
	if (ft_is_builtin_command(command))
		shell_data->state.error_num = ft_run_builtin(command, shell_data);
	else
		shell_data->state.error_num = ft_run_command(command, shell_data);
}

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
		ft_handle_command(shell_data->commands_list, shell_data);
	else
	{
		if (ft_handle_pipeline_command(shell_data) != EXIT_SUCCESS)
			return (EXIT_FAILURE);
	}
	shell_data->state.is_in_cmd = false;
	return (EXIT_SUCCESS);
}
