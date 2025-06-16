#include "minishell.h"

/**
 * @brief Updates the PWD and OLDPWD variables in the environment array.
 *
 * This function:
 *   - Searches for PWD and OLDPWD in the environment.
 *   - Updates their values to match the shell's current and previous
 * directories.
 *
 * @param shell_data Pointer to the main shell data structure.
 */
static void	ft_add_path_to_env(t_shell_data *shell_data)
{
	int		index;
	char	*tmp;

	index = 0;
	while (shell_data->envp[index])
	{
		if (!ft_strncmp(shell_data->envp[index], PWD_PREFIX, PWD_PREFIX_LEN))
		{
			tmp = ft_strjoin(PWD_PREFIX, shell_data->pwd);
			free(shell_data->envp[index]);
			shell_data->envp[index] = tmp;
		}
		else if (!ft_strncmp(shell_data->envp[index], OLDPWD_PREFIX,
				OLDPWD_PREFIX_LEN)
			&& shell_data->old_pwd)
		{
			tmp = ft_strjoin(OLDPWD_PREFIX, shell_data->old_pwd);
			free(shell_data->envp[index]);
			shell_data->envp[index] = tmp;
		}
		index++;
	}
}

int	ft_cd(t_shell_data *shell_data, t_command_list *command_list)
{
	int		exit_code;

	if (!command_list->str[1] || ft_strncmp(command_list->str[1], "-", 1) == 0)
	{
		ft_putendl_fd(COLOR_RED_BOLD MSG_DEFAULT_PROMPT COLOR_RESET
			MSG_ERR_CD_ARGS, STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	else
	{
		exit_code = chdir(command_list->str[1]);
		if (exit_code != 0)
		{
			ft_putstr_fd(COLOR_RED_BOLD MSG_DEFAULT_PROMPT COLOR_RESET
				MSG_ERR_CD_FILE, STDERR_FILENO);
			ft_putendl_fd(command_list->str[1], STDERR_FILENO);
			return (EXIT_FAILURE);
		}
	}
	if (exit_code == 0)
	{
		ft_change_path(shell_data);
		ft_add_path_to_env(shell_data);
	}
	return (EXIT_SUCCESS);
}
