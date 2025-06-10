#include "minishell.h"

int	ft_pwd(t_shell_data *shell_data, t_commands_list *simple_cmd)
{
	(void) simple_cmd;
	ft_putendl_fd(shell_data->pwd, STDOUT_FILENO);
	return (EXIT_SUCCESS);
}
