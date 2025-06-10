#include "minishell.h"

void	ft_append_regular_char(const char *str, int *index, char **result)
{
	char	*char_str;
	char	*tmp_result;

	char_str = ft_char_to_str(str[*index]);
	(*index)++;
	tmp_result = ft_strjoin(*result, char_str);
	free(*result);
	*result = tmp_result;
	free(char_str);
}

bool	ft_should_process_env(char *str, int index)
{
	return (str[index + 1] != ' '
		&& str[index + 1] != '\0'
		&& (str[index + 1] != SYMBOL_QUOTE_DOUBLE || str[index + 2] != '\0'));
}

int	ft_process_env(t_shell_data *shell_data,
	char *str, int index, char **result)
{
	int		i;
	int		end;
	int		eq;
	char	*env;

	i = 0;
	end = ft_get_after_dollar_len(str, index);
	while (shell_data->envp[i])
	{
		eq = (int)ft_get_equal_sign_index(shell_data->envp[i]);
		if (ft_strncmp(str + index + 1, shell_data->envp[i], eq - 1) == 0
			&& (end - index) == eq)
		{
			env = ft_strdup(shell_data->envp[i] + eq);
			*result = ft_strjoin_free(*result, env);
			free(env);
			return (eq);
		}
		i++;
	}
	if ((end - index) < 1)
		return (1);
	return (ft_get_after_dollar_len(str, index) - index);
}
