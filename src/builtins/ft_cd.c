#include "minishell.h"

char	*find_path_ret(char *str, t_shell_data *shell_data)
{
	int	index;

	index = 0;
	while (shell_data->envp[index])
	{
		if (!ft_strncmp(shell_data->envp[index], str, ft_strlen(str)))
			return (ft_substr(shell_data->envp[index], ft_strlen(str),
					ft_strlen(shell_data->envp[index]) - ft_strlen(str)));
		index++;
	}
	return (NULL);
}

int	specific_path(t_shell_data *shell_data, char *str)
{
	char	*tmp;
	int		ret;

	tmp = find_path_ret(str, shell_data);
	ret = chdir(tmp);
	free(tmp);
	if (ret != 0)
	{
		str = ft_substr(str, 0, ft_strlen(str) - 1);
		ft_putstr_fd(str, STDERR_FILENO);
		free(str);
		ft_putendl_fd(" not set", STDERR_FILENO);
	}
	return (ret);
}

void	add_path_to_env(t_shell_data *shell_data)
{
	int		index;
	char	*tmp;

	index = 0;
	while (shell_data->envp[index])
	{
		if (!ft_strncmp(shell_data->envp[index], "PWD=", 4))
		{
			tmp = ft_strjoin("PWD=", shell_data->pwd);
			free(shell_data->envp[index]);
			shell_data->envp[index] = tmp;
		}
		else if (!ft_strncmp(shell_data->envp[index], "OLDPWD=", 7) && shell_data->old_pwd)
		{
			tmp = ft_strjoin("OLDPWD=", shell_data->old_pwd);
			free(shell_data->envp[index]);
			shell_data->envp[index] = tmp;
		}
		index++;
	}
}

int	ft_cd(t_shell_data *shell_data, t_commands_list *simple_cmd)
{
	int		ret;

	if (!simple_cmd->str[1])
		ret = specific_path(shell_data, "HOME=");
	else if (ft_strncmp(simple_cmd->str[1], "-", 1) == 0)
		ret = specific_path(shell_data, "OLDPWD=");
	else
	{
		ret = chdir(simple_cmd->str[1]);
		if (ret != 0)
		{
			ft_putstr_fd(COLOR_RED_BOLD MSG_PROMPT COLOR_RESET, STDERR_FILENO);
			ft_putstr_fd(simple_cmd->str[1], STDERR_FILENO);
			perror(" ");
		}
	}
	if (ret != 0)
		return (EXIT_FAILURE);
	change_path(shell_data);
	add_path_to_env(shell_data);
	return (EXIT_SUCCESS);
}
