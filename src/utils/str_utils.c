#include "minishell.h"

char	*ft_join_split_str(char **split_str, char *new_str)
{
	char	*tmp;
	char	*add_space;
	int		index;

	tmp = ft_strdup(split_str[0]);
	index = 1;
	while (split_str[index])
	{
		new_str = tmp;
		add_space = ft_strjoin(new_str, " ");
		free(new_str);
		tmp = ft_strjoin(add_space, split_str[index]);
		free(add_space);
		index++;
	}
	new_str = tmp;
	return (new_str);
}

char	**ft_resplit_str(char **double_arr)
{
	char	**ret;
	char	*joined_str;

	joined_str = ft_join_split_str(double_arr, NULL);
	ft_free_array(double_arr);
	ret = ft_split(joined_str, ' ');
	free(joined_str);
	joined_str = ft_join_split_str(ret, NULL);
	ft_free_array(ret);
	ret = ft_split(joined_str, ' ');
	free(joined_str);
	return (ret);
}

char	*ft_char_to_str(char c)
{
	char	*str;

	str = ft_calloc(sizeof(char), 2);
	str[0] = c;
	return (str);
}

char	*ft_apply_del_quotes(char *str, char quote_symbol)
{
	char	*tmp;

	tmp = ft_del_quotes(str, quote_symbol);
	if (tmp && tmp != str)
	{
		free(str);
		str = tmp;
	}
	return (str);
}

char	*ft_strjoin_free(char *s1, char *s2)
{
	char	*new_str;

	new_str = ft_strjoin(s1, s2);
	free(s1);
	return (new_str);
}
