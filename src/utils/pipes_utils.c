#include "minishell.h"

void	ft_remove_leading_pipe(t_shell_data *shell_data)
{
	if (shell_data->lexer_list && shell_data->lexer_list->token == PIPE)
		ft_lexer_del_by_index(&shell_data->lexer_list,
			shell_data->lexer_list->index);
}

int	ft_count_pipes_in_lexer(t_lexer_list *lexer_list)
{
	int	count;

	count = 0;
	while (lexer_list)
	{
		if (lexer_list->token == PIPE)
			count++;
		lexer_list = lexer_list->next;
	}
	return (count);
}
