#include "minishell.h"

int	ft_env(t_shell_data *shell_data, t_commands_list *simple_cmd)
{
	int		index;

	(void) simple_cmd;
	index = 0;
	while (shell_data->envp[index])
	{
		ft_putendl_fd(shell_data->envp[index], STDOUT_FILENO);
		index++;
	}
	return (EXIT_SUCCESS);
}
