#include "minishell.h"

int	ft_add_redirection(t_lexer_list *tmp, t_parser_data *parser_data)
{
	t_lexer_list	*node;
	int				index_1;
	int				index_2;

	node = ft_lexer_create_node(ft_strdup(tmp->next->str), tmp->token);
	if (!node)
		ft_error_parser(1, parser_data->shell_data, parser_data->lexer_list);
	ft_lexer_append_node(&parser_data->redirections, node);
	index_1 = tmp->index;
	index_2 = tmp->next->index;
	ft_lexer_del_by_index(&parser_data->lexer_list, index_1);
	ft_lexer_del_by_index(&parser_data->lexer_list, index_2);
	parser_data->num_redirections++;
	return (0);
}

static t_lexer_list	*ft_skip_empty_tokens(t_lexer_list *lexer_list)
{
	while (lexer_list && lexer_list->token == WORD)
		lexer_list = lexer_list->next;
	return (lexer_list);

}

static void	ft_error_check_redirections(t_parser_data *parser_data, t_lexer_list *node)
{
	if (!node->next)
		ft_error_parser(ERR_SYNTAX, parser_data->shell_data, parser_data->lexer_list);
	if (node->next->token)
		ft_error_parser_token(parser_data->shell_data,
			parser_data->lexer_list, node->next->token);
}

static void	ft_process_redirection(t_lexer_list *node, t_parser_data *parser_data)
{
	if (node->token >= REDIRECT_OUT && node->token <= REDIRECT_HEREDOC)
	{
		ft_error_check_redirections(parser_data, node);
		ft_add_redirection(node, parser_data);
	}
}

void	ft_remove_redirections(t_parser_data *parser_data)
{
	t_lexer_list	*node;

	node = ft_skip_empty_tokens(parser_data->lexer_list);
	if (!node || node->token == PIPE)
		return ;
	ft_process_redirection(node, parser_data);
	ft_remove_redirections(parser_data);
}
