#include "minishell.h"

/**
 * @brief Checks if the given command is a shell builtin that should be executed
 * in the parent process.
 *
 * Builtins like cd, exit, export, and unset are handled in the parent shell
 * process because they modify the shell state or environment.
 *
 * @param command Pointer to the command list node.
 * @return true if the command is a parent-process builtin, false otherwise.
 */
static bool	ft_is_builtin_command(t_command_list *command)
{
	return (command->builtin == ft_cd
		|| command->builtin == ft_exit
		|| command->builtin == ft_export
		|| command->builtin == ft_unset);
}

/**
 * @brief Executes a builtin command in the parent process.
 *
 * Calls the builtin function pointer stored in the command node.
 *
 * @param command Pointer to the command list node.
 * @param shell_data Pointer to the main shell data structure.
 * @return The exit code returned by the builtin.
 */
static int	ft_run_builtin(t_command_list *command, t_shell_data *shell_data)
{
	return (command->builtin(shell_data, command));
}

/**
 * @brief Processes the exit status of a child process and updates the shell
 * error number.
 *
 * Handles both normal exit and termination by signal, printing a newline for
 * SIGINT.
 *
 * @param status Status value returned by waitpid.
 * @param shell_data Pointer to the main shell data structure.
 * @return The exit code or signal code as the shell should report it.
 */
static int	ft_process_exit_status(int status, t_shell_data *shell_data)
{
	int	signum;

	if (WIFSIGNALED(status))
	{
		signum = WTERMSIG(status);
		if (signum == SIGINT)
			ft_putstr_fd("\n", STDERR_FILENO);
		shell_data->state.error_num = 128 + signum;
		return (128 + signum);
	}
	else if (WIFEXITED(status))
	{
		shell_data->state.error_num = WEXITSTATUS(status);
		return (WEXITSTATUS(status));
	}
	return (EXIT_FAILURE);
}

/**
 * @brief Executes an external (non-builtin) command in a child process.
 *
 * Forks a new process, executes the command, and waits for it to finish.
 * Updates the shell error number based on the exit status.
 *
 * @param command Pointer to the command list node.
 * @param shell_data Pointer to the main shell data structure.
 * @return The exit code or signal code as the shell should report it.
 */
static int	ft_run_command(t_command_list *command, t_shell_data *shell_data)
{
	int	pid;
	int	status;

	ft_handle_heredoc(shell_data, command);
	pid = fork();
	if (pid < 0)
		return (ft_error_handle_msg(ERR_FORK, shell_data));
	if (pid == 0)
	{
		signal(SIGINT, SIG_DFL);
		exit(ft_execute_command(command, shell_data));
	}
	signal(SIGINT, SIG_IGN);
	waitpid(pid, &status, 0);
	signal(SIGINT, ft_sigint_handler);
	return (ft_process_exit_status(status, shell_data));
}

void	ft_handle_command(t_command_list *command, t_shell_data *shell_data)
{
	ft_expander_caller(shell_data, &shell_data->command_list);
	if (ft_is_builtin_command(command))
		shell_data->state.error_num = ft_run_builtin(command, shell_data);
	else
		shell_data->state.error_num = ft_run_command(command, shell_data);
}
