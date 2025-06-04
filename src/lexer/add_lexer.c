#include "minishell.h"

t_lexer_list	*ft_lexer_create_node(char *str, int token)
{
	static int		index = 0;
	t_lexer_list	*new_node;

	new_node = (t_lexer_list *)malloc(sizeof(t_lexer_list));
	if (!new_node)
		return (0);
	new_node->str = str;
	new_node->token = token;
	new_node->index = index++;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}

void	ft_lexer_append_node(t_lexer_list **lexer_list, t_lexer_list *node)
{
	t_lexer_list	*tmp;

	if (*lexer_list == NULL)
	{
		*lexer_list = node;
		return ;
	}
	tmp = *lexer_list;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = node;
	node->prev = tmp;
}

int	ft_add_token_to_lexer(char *str, t_token token_type,
	t_lexer_list **lexer_list)
{
	t_lexer_list	*node;

	if (!lexer_list)
		return (EXIT_FAILURE);
	node = ft_lexer_create_node(str, token_type);
	if (!node)
		return (EXIT_FAILURE);
	ft_lexer_append_node(lexer_list, node);
	return (EXIT_SUCCESS);
}
