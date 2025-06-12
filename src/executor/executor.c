#include "minishell.h"

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
