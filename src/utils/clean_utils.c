#include "minishell.h"

void	ft_clean_str(char **str)
{
	if (str && *str)
	{
		free(*str);
		*str = NULL;
	}
}

void	ft_clean_shell_resources(t_shell_data *shell_data)
{
	if (!shell_data)
		return ;
	if (shell_data->envp)
	{
		ft_free_array(shell_data->envp);
		shell_data->envp = NULL;
	}
	if (shell_data->paths)
	{
		ft_free_array(shell_data->paths);
		shell_data->paths = NULL;
	}
}
