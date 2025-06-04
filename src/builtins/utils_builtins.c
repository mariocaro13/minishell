#include "minishell.h"

void	change_path(t_shell_data *shell_data)
{
	char	*tmp;

	tmp = ft_strdup(shell_data->pwd);
	free(shell_data->old_pwd);
	shell_data->old_pwd = tmp;
	free(shell_data->pwd);
	shell_data->pwd = getcwd(NULL, sizeof(NULL));
}

size_t	ft_equal_sign(char *str)
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

char	*delete_quotes_value(char *str)
{
	char	**split_quotes;

	split_quotes = ft_split(str, '"');
	if (!split_quotes[1])
	{
		ft_free_array(split_quotes);
		split_quotes = ft_split(str, '\'');
	}
	free(str);
	str = ft_strjoin(split_quotes[0], split_quotes[1]);
	ft_free_array(split_quotes);
	return (str);
}

int	check_valid_identifier(char c)
{
	return (c == '|' || c == '<' || c == '>' || c == '[' || c == ']'
		|| c == '\'' || c == '\"' || c == ' ' || c == ',' || c == '.'
		|| c == ':' || c == '/' || c == '{' || c == '}' || c == '+'
		|| c == '^' || c == '%' || c == '#' || c == '@' || c == '!'
		|| c == '~'
		|| c == '=' || c == '-' || c == '?' || c == '&' || c == '*');
}

// "\'\"\\$ ,.:/[{]}+=-?&*^%#@!~"
