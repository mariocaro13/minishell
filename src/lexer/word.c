#include "minishell.h"

static int	ft_get_word_len(int start, char *str)
{
	int		index;
	int		advance;
	char	c;

	index = 0;
	advance = 0;
	while (str[start + index]
		&& !ft_is_whitespace(str[start + index])
		&& !ft_is_operator_char(str[start + 1]))
	{
		c = str[start + index];
		if (c == SYMBOL_QUOTE || c == SYMBOL_QUOTE_DOUBLE)
		{
			advance = ft_get_quote_len(start + index, str, c);
			if (advance < 0)
				return (-1);
			index += advance;
		}
		else
			index++;
	}
	return (index);
}

static int	ft_add_word_to_lexer(int start, int len, char *str,
	t_lexer_list **lexer_list)
{
	char	*token_str;

	token_str = ft_substr(str, start, len);
	if (!token_str)
		return (EXIT_FAILURE);
	if (ft_add_token_to_lexer(token_str, WORD, lexer_list) != EXIT_SUCCESS)
	{
		free(token_str);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	ft_tokenize_word(int start, char *str, t_lexer_list **lexer_list)
{
	int	len;

	len = ft_get_word_len(start, str);
	if (len < 0)
		return (-1);
	if (ft_add_word_to_lexer(start, len, str, lexer_list) != EXIT_SUCCESS)
		return (-1);
	return (len);
}
