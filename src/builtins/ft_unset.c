#include "minishell.h"

char	**whileloop_del_var(char **arr, char **rtn, char *str)
{
	int	index;
	int	j;

	index = 0;
	j = 0;
	while (arr[index] != NULL)
	{
		if (!(ft_strncmp(arr[index], str, ft_get_equal_sign_index(arr[index]) - 1) == 0
				&& str[ft_get_equal_sign_index(arr[index])] == '\0'
				&& arr[index][ft_strlen(str)] == '='))
		{
			rtn[j] = ft_strdup(arr[index]);
			if (rtn[j] == NULL)
			{
				ft_free_array(rtn);
				return (rtn);
			}
			j++;
		}
		index++;
	}
	return (rtn);
}

char	**del_var(char **arr, char *str)
{
	char	**rtn;
	size_t	index;

	index = 0;
	while (arr[index] != NULL)
		index++;
	rtn = ft_calloc(sizeof(char *), index + 1);
	if (!rtn)
		return (NULL);
	rtn = whileloop_del_var(arr, rtn, str);
	return (rtn);
}

int	unset_error(t_command_list *simple_cmd)
{
	int		index;

	index = 0;
	if (!simple_cmd->str[1])
	{
		ft_putendl_fd("minishell: unset: not enough arguments", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	while (simple_cmd->str[1][index])
	{
		if (simple_cmd->str[1][index++] == '/')
		{
			ft_putstr_fd(COLOR_RED_BOLD MSG_DEFAULT_PROMPT COLOR_RESET "unset: `",
				STDERR_FILENO);
			ft_putstr_fd(simple_cmd->str[1], STDERR_FILENO);
			ft_putendl_fd("': not a valid identifier", STDERR_FILENO);
			return (EXIT_FAILURE);
		}
	}
	if (ft_get_equal_sign_index(simple_cmd->str[1]) != 0)
	{
		ft_putendl_fd("minishell: unset: not a valid identifier",
			STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	ft_unset(t_shell_data *shell_data, t_command_list *simple_cmd)
{
	char	**tmp;

	if (unset_error(simple_cmd) == 1)
		return (EXIT_FAILURE);
	else
	{
		tmp = del_var(shell_data->envp, simple_cmd->str[1]);
		ft_free_array(shell_data->envp);
		shell_data->envp = tmp;
	}
	return (EXIT_SUCCESS);
}
