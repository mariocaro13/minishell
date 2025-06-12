#include "minishell.h"

int	ft_reset_shell_state(t_shell_data *shell_data)
{
	if (!shell_data)
		return (EXIT_FAILURE);
	ft_init_shell_data(shell_data);
	ft_init_global_shell_state(shell_data);
	ft_init_env_paths(shell_data);
	ft_init_signals();
	return (EXIT_SUCCESS);
}

int	ft_reset_shell_loop(t_shell_data *shell_data)
{
	ft_command_list_clear(&shell_data->command_list);
	if (shell_data->args)
	{
		free(shell_data->args);
		shell_data->args = NULL;
	}
	if (shell_data->pid)
	{
		free(shell_data->pid);
		shell_data->pid = NULL;
	}
	if (shell_data->paths)
	{
		ft_free_array(shell_data->paths);
		shell_data->paths = NULL;
	}
	ft_reset_shell_state(shell_data);
	shell_data->reset = true;
	ft_shell_loop(shell_data);
	return (1);
}
