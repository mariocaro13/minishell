#include "minishell.h"

/**
 * @brief Calculates the length of a word token starting at the given index.
 *
 * Iterates through the input string starting at 'start', stopping at
 * whitespace or operator characters.
 * Handles quoted substrings by skipping over them using ft_get_quote_len.
 *
 * @param start Start index in the input string.
 * @param str Input string.
 * @return Length of the word token, or -1 on error (e.g., unclosed quote).
 */
static int	ft_get_word_len(int start, char *str)
{
	int		index;
	int		advance;
	char	c;

	index = 0;
	advance = 0;
	while (str[start + index]
		&& !ft_is_whitespace(str[start + index])
		&& !ft_is_operator_char(str[start + index]))
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

/**
 * @brief Adds a word token to the lexer list.
 *
 * Extracts a substring from the input string and adds it as a WORD
 * token to the lexer list.
 *
 * @param start Start index of the word in the input string.
 * @param len Length of the word.
 * @param str Input string.
 * @param lexer_list Pointer to the lexer list pointer.
 * @return EXIT_SUCCESS on success, EXIT_FAILURE on allocation error.
 */
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
