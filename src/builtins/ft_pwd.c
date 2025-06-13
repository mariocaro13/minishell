#include "minishell.h"

int	ft_pwd(t_shell_data *shell_data, t_command_list *simple_cmd)
{
	(void) simple_cmd;
	if (!shell_data->pwd)
		return (EXIT_FAILURE);
	ft_putendl_fd(shell_data->pwd, STDOUT_FILENO);
	return (EXIT_SUCCESS);
}
