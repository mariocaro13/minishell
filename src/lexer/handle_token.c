#include "minishell.h"

t_token	ft_get_token_type(const char *str, int index)
{
	if (str[index] == SYMBOL_PIPE)
		return (PIPE);
	else if (str[index] == SYMBOL_GREATER_THAN)
	{
		if (str[index + 1] && str[index + 1] == SYMBOL_GREATER_THAN)
			return (REDIRECT_OUT_APPEND);
		return (REDIRECT_OUT);
	}
	else if (str[index] == SYMBOL_LESS_THAN)
	{
		if (str[index + 1] && str[index + 1] == SYMBOL_LESS_THAN)
			return (REDIRECT_HEREDOC);
		return (REDIRECT_IN);
	}
	else if (str[index] == SYMBOL_QUOTE)
		return (QUOTE);
	else if (str[index] == SYMBOL_QUOTE_DOUBLE)
		return (QUOTE_DOUBLE);
	return (WORD);
}

int	ft_handle_token(char *str, int index, t_lexer_list **lexer_list)
{
	t_token	token;
	int		token_len;

	token = ft_get_token_type(str, index);
	token_len = 1;
	if ((token == REDIRECT_OUT_APPEND) || (token == REDIRECT_HEREDOC))
		token_len = 2;
	if (ft_add_token_to_lexer(NULL, token, lexer_list) != EXIT_SUCCESS)
		return (-1);
	return (token_len);
}
