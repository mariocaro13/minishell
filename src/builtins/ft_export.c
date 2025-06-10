#include "minishell.h"

int	variable_exist(t_shell_data *shell_data, char *str)
{
	int	index;

	index = 0;
	if (str[ft_get_equal_sign_index(str)] == '\"')
		ft_del_quotes(str, '\"');
	if (str[ft_get_equal_sign_index(str)] == '\'')
		ft_del_quotes(str, '\'');
	while (shell_data->envp[index])
	{
		if (ft_strncmp(shell_data->envp[index],
				str, ft_get_equal_sign_index(shell_data->envp[index])) == 0)
		{
			free(shell_data->envp[index]);
			shell_data->envp[index] = ft_strdup(str);
			return (1);
		}
		index++;
	}
	return (0);
}

int	check_parameter(char *str)
{
	int	index;

	index = 0;
	if (ft_isdigit(str[0]))
		return (ft_error_print_export(str));
	if (ft_get_equal_sign_index(str) == 0)
		return (EXIT_FAILURE);
	if (str[0] == '=')
		return (ft_error_print_export(str));
	while (str[index] != '=')
	{
		if (ft_check_valid_identifier(str[index]))
			return (ft_error_print_export(str));
		index++;
	}
	return (EXIT_SUCCESS);
}

char	**whileloop_add_var(char **arr, char **rtn, char *str)
{
	int	index;

	index = 0;
	while (arr[index] != NULL)
	{
		if (arr[index + 1] == NULL)
		{
			rtn[index] = ft_strdup(str);
			rtn[index + 1] = ft_strdup(arr[index]);
		}
		else
			rtn[index] = ft_strdup(arr[index]);
		if (rtn[index] == NULL)
		{
			ft_free_array(rtn);
			return (rtn);
		}
		index++;
	}
	return (rtn);
}

char	**add_var(char **arr, char *str)
{
	char	**rtn;
	size_t	index;

	index = 0;
	if (str[ft_get_equal_sign_index(str)] == '\"')
		ft_del_quotes(str, '\"');
	if (str[ft_get_equal_sign_index(str)] == '\'')
		ft_del_quotes(str, '\'');
	while (arr[index] != NULL)
		index++;
	rtn = ft_calloc(sizeof(char *), index + 2);
	if (!rtn)
		return (NULL);
	index = 0;
	whileloop_add_var(arr, rtn, str);
	return (rtn);
}

int	ft_export(t_shell_data *shell_data, t_commands_list *simple_cmd)
{
	char	**tmp;
	int		index;

	index = 1;
	if (!simple_cmd->str[1] || simple_cmd->str[1][0] == '\0')
		ft_env(shell_data, simple_cmd);
	else
	{
		while (simple_cmd->str[index])
		{
			if (check_parameter(simple_cmd->str[index]) == 0
				&& variable_exist(shell_data, simple_cmd->str[index]) == 0)
			{
				if (simple_cmd->str[index])
				{
					tmp = add_var(shell_data->envp, simple_cmd->str[index]);
					ft_free_array(shell_data->envp);
					shell_data->envp = tmp;
				}
			}
			index++;
		}
	}
	return (EXIT_SUCCESS);
}
