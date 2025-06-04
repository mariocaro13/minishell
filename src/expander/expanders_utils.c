#include "minishell.h"

char	*char_to_str(char c)
{
	char	*str;

	str = ft_calloc(sizeof(char), 2);
	str[0] = c;
	return (str);
}

int	after_dol_lenght(char *str, int j)
{
	int	index;

	index = j + 1;
	while (str[index] != '\0' && str[index] != '$' && str[index] != ' '
		&& str[index] != '\"' && str[index] != '\'' && str[index] != '=' && str[index] != '-'
		&& str[index] != ':')
		index++;
	return (index);
}

int	question_mark(char **tmp)
{
	free(*tmp);
	*tmp = ft_itoa(g_shell_state.error_num);
	return (ft_strlen(*tmp) + 1);
}
