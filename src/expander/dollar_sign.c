#include "minishell.h"

static int	ft_loop_if_dollar_sign(t_shell_data *shell_data, char *str, char **tmp, int index)
{
	int		i;
	int		result;
	char	*env_value;
	char	*tmp_join;

	i = 0;
	result = 0;
	while (shell_data->envp[i])
	{
		if (ft_strncmp(str + index + 1, shell_data->envp[i],
				ft_equal_sign(shell_data->envp[i]) - 1) == 0
			&& after_dol_lenght(str, index) - index == (int)ft_equal_sign(shell_data->envp[i]))
		{
			env_value = ft_strdup(shell_data->envp[i] + ft_equal_sign(shell_data->envp[i]));
			tmp_join = ft_strjoin(*tmp, env_value);
			free(*tmp);
			*tmp = tmp_join;
			free(env_value);
			result = ft_equal_sign(shell_data->envp[i]);
			break ;
		}
		i++;
	}
	if (result == 0)
		result = after_dol_lenght(str, index) - index;
	return (result);
}

static int	ft_handle_digit_after_dollar(int index, char *str)
{
	int	start;

	start = index;
	if (str[index] == SYMBOL_DOLLAR
		&& ft_isdigit((unsigned char)str[index + 1]) == 1)
			index += 2;
	return (index - start);
}

static void	ft_append_regular_char(const char *str, int *index, char **result)
{
	char	*char_str;
	char	*tmp_result;

	char_str = char_to_str(str[*index]);
	(*index)++;
	tmp_result = ft_strjoin(*result, char_str);
	free(*result);
	*result = tmp_result;
	free(char_str);
}

char	*detect_dollar_sign(t_shell_data *shell_data, char *str)
{
	int		index;
	int		advance;
	char	*result;

	index = 0;
	result = ft_strdup("");
	while (str[index])
	{
		advance = ft_handle_digit_after_dollar(index, str);
		index += advance;
		if (str[index] == SYMBOL_DOLLAR && str[index + 1] == SYMBOL_QUESTION_MARK)
		{
			advance = question_mark(&result);
			index += advance;
			continue;
		}
		else if (str[index] == SYMBOL_DOLLAR
					&& (str[index + 1] != ' ' && (str[index + 1] != SYMBOL_QUOTE_DOUBLE || str[index + 2] != '\0')) 
					&& str[index + 1] != '\0')
		{
			advance = ft_loop_if_dollar_sign(shell_data, str, &result, index);
			index += advance;
			continue;
		}
		else
			ft_append_regular_char(str, &index, &result);
	}
	return (result);
}

size_t	ft_find_dollar_sign(const char *str)
{
	size_t	index;

	index = 0;
	while (str[index])
	{
		if (str[index] == SYMBOL_DOLLAR)
			return (index + 1);
		index++;
	}
	return (0);
}
