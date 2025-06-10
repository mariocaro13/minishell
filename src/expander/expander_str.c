#include "minishell.h"

char	*ft_expand_str(t_shell_data *shell_data, char *str)
{
	char	*tmp;
	size_t	dollar_index;

	tmp = NULL;
	dollar_index = ft_get_dollar_sign_index(str);
	if (dollar_index > 1 && dollar_index != 0 && str[dollar_index] != '\0'
		&& str[dollar_index - 2] != SYMBOL_QUOTE)
	{
		tmp = ft_detect_dollar_sign(shell_data, str);
		free(str);
		str = tmp;
	}
	str = ft_apply_del_quotes(str, SYMBOL_QUOTE_DOUBLE);
	str = ft_apply_del_quotes(str, SYMBOL_QUOTE);
	return (str);
}
