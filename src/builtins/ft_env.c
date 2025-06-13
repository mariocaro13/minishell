#include "minishell.h"

int	ft_env(t_shell_data *shell_data, t_command_list *command_list)
{
	int		index;

	(void) command_list;
	if (!shell_data || !shell_data->envp)
		return (EXIT_FAILURE);
	index = 0;
	while (shell_data->envp[index])
	{
		ft_putendl_fd(shell_data->envp[index], STDOUT_FILENO);
		index++;
	}
	return (EXIT_SUCCESS);
}
