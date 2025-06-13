#include "minishell.h"

int	ft_pwd(t_shell_data *shell_data, t_command_list *command_list)
{
	(void) command_list;
	if (!shell_data->pwd)
		return (EXIT_FAILURE);
	ft_putendl_fd(shell_data->pwd, STDOUT_FILENO);
	return (EXIT_SUCCESS);
}
