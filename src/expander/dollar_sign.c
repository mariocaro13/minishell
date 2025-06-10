#include "minishell.h"

static int	ft_handle_digit_after_dollar(int index, char *str)
{
	int	start;

	start = index;
	if (str[index] == SYMBOL_DOLLAR
		&& ft_isdigit((unsigned char)str[index + 1]))
		index += 2;
	return (index - start);
}

int	ft_get_after_dollar_len(char *str, int start)
{
	int	index;

	index = start + 1;
	while (str[index]
		&& str[index] != SYMBOL_DOLLAR
		&& str[index] != ' '
		&& str[index] != SYMBOL_QUOTE_DOUBLE
		&& str[index] != SYMBOL_QUOTE
		&& str[index] != SYMBOL_EQUAL
		&& str[index] != '-'
		&& str[index] != ':')
		index++;
	return (index);
}

static int	ft_process_dollar_token(t_shell_data *shell_data,
	char *str, int index, char **result)
{
	int	advance;

	if (str[index + 1] == SYMBOL_QUESTION_MARK)
		advance = ft_process_question_mark(shell_data, result);
	else if (ft_should_process_env(str, index))
		advance = ft_process_env(shell_data, str, index, result);
	else
		advance = 1;
	if (advance < 1)
		advance = 1;
	return (advance);
}

char	*ft_detect_dollar_sign(t_shell_data *shell_data, char *str)
{
	int		index;
	int		advance;
	char	*result;

	index = 0;
	result = ft_calloc(1, sizeof(char));
	while (str[index])
	{
		advance = ft_handle_digit_after_dollar(index, str);
		index += advance;
		if (str[index] == SYMBOL_DOLLAR && str[index + 1])
		{
			advance = ft_process_dollar_token(shell_data, str, index, &result);
			index += advance;
		}
		else
			ft_append_regular_char(str, &index, &result);
	}
	return (result);
}

size_t	ft_get_dollar_sign_index(const char *str)
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
