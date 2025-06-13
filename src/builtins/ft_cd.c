#include "minishell.h"

char	*ft_get_path_ret(const char *env_var, t_shell_data *shell_data)
{
	int		index;
	size_t	var_len;
	char	*result;

	index = 0;
	var_len = ft_strlen(env_var);
	while (shell_data->envp[index])
	{
		if (!ft_strncmp(shell_data->envp[index], env_var, var_len))
		{
			if (ft_strip_env_prefix(&result, shell_data->envp[index], var_len)
				== EXIT_SUCCESS)
				return (result);
			else
				return (NULL);
		}
		index++;
	}
	return (NULL);
}

int	ft_get_specific_path(t_shell_data *shell_data, char *env_var)
{
	char	*env_value;
	char	*env_var_print;
	int		exit_code;

	env_value = ft_get_path_ret(env_var, shell_data);
	if (!env_value)
	{
		env_var_print = ft_substr(env_var, 0, ft_strlen(env_var) - 1);
		ft_putstr_fd(env_var_print, STDERR_FILENO);
		ft_putendl_fd(" not set", STDERR_FILENO);
		free(env_var_print);
		return (-1);
	}
	exit_code = chdir(env_value);
	free(env_value);
	if (exit_code != 0)
	{
		env_var_print = ft_substr(env_var, 0, ft_strlen(env_var) - 1);
		ft_putstr_fd(env_var_print, STDERR_FILENO);
		ft_putendl_fd(" not set", STDERR_FILENO);
		free(env_var_print);
	}
	return (exit_code);
}

void	ft_add_path_to_env(t_shell_data *shell_data)
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

int	ft_cd(t_shell_data *shell_data, t_command_list *simple_cmd)
{
	int		exit_code;

	if (!simple_cmd->str[1] || ft_strncmp(simple_cmd->str[1], "-", 1) == 0)
	{
		ft_putendl_fd(COLOR_RED_BOLD MSG_DEFAULT_PROMPT COLOR_RESET
			MSG_ERR_CD_ARGS, STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	else
	{
		exit_code = chdir(simple_cmd->str[1]);
		if (exit_code != 0)
		{
			ft_putstr_fd(COLOR_RED_BOLD MSG_DEFAULT_PROMPT COLOR_RESET
				MSG_ERR_CD_FILE, STDERR_FILENO);
			ft_putendl_fd(simple_cmd->str[1], STDERR_FILENO);
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
