#include "minishell.h"

int	(*ft_get_builtin_function(char *str))(t_shell_data *shell_data,
	t_commands_list *simple_cmd)
{
	if (!str)
		return (NULL);
	if (!ft_strncmp(str, BUILTIN_ECHO, BUILTIN_ECHO_LEN))
		return (ft_echo);
	else if (!ft_strncmp(str, BUILTIN_CD, BUILTIN_CD_LEN))
		return (ft_cd);
	else if (!ft_strncmp(str, BUILTIN_PWD, BUILTIN_PWD_LEN))
		return (ft_pwd);
	else if (!ft_strncmp(str, BUILTIN_EXPORT, BUILTIN_EXPORT_LEN))
		return (ft_export);
	else if (!ft_strncmp(str, BUILTIN_UNSET, BUILTIN_UNSET_LEN))
		return (ft_unset);
	else if (!ft_strncmp(str, BUILTIN_ENV, BUILTIN_ENV_LEN))
		return (ft_env);
	else if (!ft_strncmp(str, BUILTIN_EXIT, BUILTIN_EXIT_LEN))
		return (ft_exit);
	return (NULL);
}

void	change_path(t_shell_data *shell_data)
{
	char	*tmp;

	tmp = ft_strdup(shell_data->pwd);
	free(shell_data->old_pwd);
	shell_data->old_pwd = tmp;
	free(shell_data->pwd);
	shell_data->pwd = getcwd(NULL, sizeof(NULL));
}

size_t	ft_get_equal_sign_index(char *str)
{
	size_t	index;

	index = 0;
	while (str[index])
	{
		if (str[index] == SYMBOL_EQUAL)
			return (index + 1);
		index++;
	}
	return (0);
}

char	*ft_del_quotes_value(char *str)
{
	char	**split_quotes;

	split_quotes = ft_split(str, SYMBOL_QUOTE_DOUBLE);
	if (!split_quotes[1])
	{
		ft_free_array(split_quotes);
		split_quotes = ft_split(str, SYMBOL_QUOTE);
	}
	free(str);
	str = ft_strjoin(split_quotes[0], split_quotes[1]);
	ft_free_array(split_quotes);
	return (str);
}

int	ft_check_valid_identifier(char c)
{
	return (c == SYMBOL_PIPE
		|| c == SYMBOL_LESS_THAN
		|| c == SYMBOL_GREATER_THAN
		|| c == SYMBOL_QUOTE
		|| c == SYMBOL_QUOTE_DOUBLE
		|| c == SYMBOL_EQUAL
		|| c == SYMBOL_QUESTION_MARK
		|| c == '[' || c == ']' || c == ' '
		|| c == ',' || c == '.' || c == ':'
		|| c == '/' || c == '{' || c == '}'
		|| c == '+' || c == '^' || c == '%' || c == '#'
		|| c == '@' || c == '!' || c == '~'
		|| c == '-' || c == '&' || c == '*');
}
