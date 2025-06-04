#include "minishell.h"

void	ft_free_node_str(t_lexer_list *node)
{
	if (node && node->str)
	{
		free(node->str);
		node->str = NULL;
	}
}

void	ft_lexer_find_node_by_index(t_lexer_list *lexer_list, int index,
			t_lexer_list **prev, t_lexer_list **found)
{
	*prev = NULL;
	*found = lexer_list;
	while (*found && ((*found)->index != index))
	{
		*prev = *found;
		*found = (*found)->next;
	}
}

void	ft_lexer_clear(t_lexer_list **lexer_list)
{
	t_lexer_list	*current;
	t_lexer_list	*next;

	if (!lexer_list || !*lexer_list)
		return ;
	current = *lexer_list;
	while (current)
	{
		next = current->next;
		ft_lexer_free_node(&current);
		current = next;
	}
	*lexer_list = NULL;
}

int	ft_lexer_count_args(t_lexer_list *lexer_list)
{
	t_lexer_list	*tmp;
	int				index;

	index = 0;
	tmp = lexer_list;
	while (tmp && tmp->token != PIPE)
	{
		if (tmp->index >= 0)
			index++;
		tmp = tmp->next;
	}
	return (index);
}
