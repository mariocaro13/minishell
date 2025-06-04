#include "minishell.h"

int	ft_get_matching_quote_index(const char *line, int start, char quote)
{
	int	index;

	index = start + 1;
	while (line[index] && line[index] != quote)
		index++;
	if (line[index] == quote)
		return (index);
	return (-1);
}

bool	ft_are_quotes_closed(const char *line)
{
	int	index;
	int	quote_end;

	index = 0;
	while (line[index])
	{
		if (line[index] == SYMBOL_QUOTE_DOUBLE || line[index] == SYMBOL_QUOTE)
		{
			quote_end = ft_get_matching_quote_index(line, index, line[index]);
			if (quote_end < 0)
				return (false);
			index = quote_end;
		}
		index++;
	}
	return (true);
}

int	ft_get_quote_len(int start, char *str, char quote_char)
{
	int	index;

	index = start + 1;
	while (str[index] && str[index] != quote_char)
		index++;
	if (str[index] != quote_char)
		return (-2);
	return (index - start + 1);
}

size_t	ft_count_quotes(char *str)
{
	size_t	index;
	size_t	count;

	index = 0;
	count = 0;
	while (str[index])
	{
		if (str[index] == SYMBOL_QUOTE || str[index] == SYMBOL_QUOTE_DOUBLE)
			count++;
		index++;
	}
	return (count);
}

char	*ft_del_quotes(char *str, char quote_char)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (str[i])
	{
		if (str[i] == quote_char)
		{
			j = 0;
			while (str[i + j] == quote_char)
				j++;
			ft_strlcpy(&str[i], &str[i + j], strlen(&str[i]) + 1);
		}
		else
			i++;
	}
	return (str);
}
