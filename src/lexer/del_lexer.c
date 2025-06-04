#include "minishell.h"

t_lexer_list	*ft_lexer_free_node(t_lexer_list **lexer_list)
{
	if (!lexer_list || !*lexer_list)
		return (NULL);
	ft_free_node_str(*lexer_list);
	free(*lexer_list);
	*lexer_list = NULL;
	return (NULL);
}

void	ft_lexer_del_first_node(t_lexer_list **lexer_list)
{
	t_lexer_list	*node;

	if (!lexer_list || !*lexer_list)
		return ;
	node = *lexer_list;
	*lexer_list = node->next;
	ft_lexer_free_node(&node);
	if (*lexer_list)
		(*lexer_list)->prev = NULL;
}

void	ft_lexer_del_by_index(t_lexer_list **lexer_list, int index)
{
	t_lexer_list	*start;
	t_lexer_list	*node;
	t_lexer_list	*prev;

	if (!lexer_list || !*lexer_list)
		return ;
	start = *lexer_list;
	node = *lexer_list;
	if (node->index == index)
	{
		ft_lexer_del_first_node(lexer_list);
		return ;
	}
	ft_lexer_find_node_by_index(start, index, &prev, &node);
	if (node)
	{
		prev->next = node->next;
		if (node->next)
			node->next->prev = prev;
		ft_lexer_free_node(&node);
	}
	*lexer_list = start;
}
