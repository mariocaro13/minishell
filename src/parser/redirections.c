#include "minishell.h"

/**
 * @brief Skips over empty tokens in the lexer list.
 *
 * Advances the lexer list pointer past any nodes with token type WORD.
 *
 * @param lexer_list Pointer to the current lexer list node.
 * @return Pointer to the first non-WORD token node, or NULL if none.
 */
static t_lexer_list	*ft_skip_empty_tokens(t_lexer_list *lexer_list)
{
	while (lexer_list && lexer_list->token == WORD)
		lexer_list = lexer_list->next;
	return (lexer_list);
}

/**
 * @brief Checks for errors in redirection syntax and handles them.
 *
 * If the redirection node has no next node, or the next node is a token,
 * calls the appropriate error handler.
 *
 * @param parser_data Pointer to the parser data structure.
 * @param node Pointer to the current lexer node representing a redirection.
 */
static void	ft_error_check_redirections(t_parser_data *parser_data,
	t_lexer_list *node)
{
	if (!node->next)
		ft_error_parser(ERR_SYNTAX, parser_data->shell_data,
			parser_data->lexer_list);
	if (node->next->token)
		ft_error_parser_token(parser_data->shell_data,
			parser_data->lexer_list, node->next->token);
}

/**
 * @brief Processes a redirection node in the lexer list.
 *
 * If the node is a redirection token, checks for errors and adds the redirection
 * to the parser's redirection list.
 *
 * @param node Pointer to the current lexer node.
 * @param parser_data Pointer to the parser data structure.
 */
static void	ft_process_redirection(t_lexer_list *node,
	t_parser_data *parser_data)
{
	if (node->token >= REDIRECT_OUT && node->token <= REDIRECT_HEREDOC)
	{
		ft_error_check_redirections(parser_data, node);
		ft_add_redirection(node, parser_data);
	}
}

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

void	ft_remove_redirections(t_parser_data *parser_data)
{
	t_lexer_list	*node;

	node = ft_skip_empty_tokens(parser_data->lexer_list);
	if (!node || node->token == PIPE)
		return ;
	ft_process_redirection(node, parser_data);
	ft_remove_redirections(parser_data);
}
