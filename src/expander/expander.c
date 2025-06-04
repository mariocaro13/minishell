#include "minishell.h"

static bool	ft_should_expand(char *str)
{
	int	pos;

	pos = ft_find_dollar_sign(str);
	if (pos == 0)
		return (false);
	if (pos < 2)
		return (true);
	if (str[pos - 2] == SYMBOL_QUOTE)
		return (false);
	return (true);
}

static bool	ft_is_export_command(const char *command)
{
	if (!command)
		return (false);
	return (ft_strncmp(command, EXPORT, EXPORT_LEN) == 0);
}

char	**ft_expand_command_args(t_shell_data *shell_data, char **str)
{
	int		index;
	char	*tmp;

	index = 0;
	tmp = NULL;
	while (str[index] != NULL)
	{
		if (ft_should_expand(str[index]))
		{
			tmp = detect_dollar_sign(shell_data, str[index]);
			free(str[index]);
			str[index] = tmp;
		}
		if (!ft_is_export_command(str[0]))
		{
			str[index] = ft_del_quotes(str[index], SYMBOL_QUOTE_DOUBLE);
			str[index] = ft_del_quotes(str[index], SYMBOL_QUOTE);
		}
		index++;
	}
	return (str);
}

char	*expander_str(t_shell_data *shell_data, char *str)
{
	char	*tmp;

	tmp = NULL;
	if (str[ft_find_dollar_sign(str) - 2] != SYMBOL_QUOTE && ft_find_dollar_sign(str) != 0
		&& str[ft_find_dollar_sign(str)] != '\0')
	{
		tmp = detect_dollar_sign(shell_data, str);
		free(str);
		str = tmp;
	}
	str = ft_del_quotes(str, SYMBOL_QUOTE_DOUBLE);
	str = ft_del_quotes(str, SYMBOL_QUOTE);
	return (str);
}


static void	ft_expand_command_redirections(t_shell_data *shell_data, t_commands_list *command_list)
{
	t_lexer_list	*current;

	if (!command_list)
		return ;
	current = command_list->redirections;
	while (current)
	{
		if (current->token != REDIRECT_HEREDOC && current->str)
			current->str = expander_str(shell_data, current->str);
		current = current->next;
	}
}

void	ft_expander_caller(t_shell_data *shell_data, t_commands_list **command_list)
{
	if (!command_list || !(*command_list))
		return ;
	if (command_list && (*command_list)->str)
		(*command_list)->str = ft_expand_command_args(shell_data, (*command_list)->str);
	ft_expand_command_redirections(shell_data, *command_list);
}
