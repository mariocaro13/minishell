#include "minishell.h"

static char	*ft_extract_token_argument(t_parser_data *parser_data)
{
	char			*argument;
	t_lexer_list	*current;

	current = parser_data->lexer_list;
	if (current->str)
		argument = ft_strdup(current->str);
	else
		argument = NULL;
	ft_lexer_del_by_index(&parser_data->lexer_list, current->index);
	return (argument);
}

static void	ft_build_arguments_loop(t_parser_data *parser_data, char **args,
	int num_arg)
{
	int	index;

	index = 0;
	while (num_arg > 0 && parser_data->lexer_list)
	{
		args[index++] = ft_extract_token_argument(parser_data);
		num_arg--;
	}
	args[index] = NULL;
}

static char	**ft_build_command_arguments(t_parser_data *parser_data)
{
	char			**args;
	int				num_args;

	num_args = ft_lexer_count_args(parser_data->lexer_list);
	args = ft_calloc(num_args + 1, sizeof(char *));
	if (!args)
	{
		ft_error_parser(ERR_MEMORY,
			parser_data->shell_data,
			parser_data->lexer_list);
		return (NULL);
	}
	ft_build_arguments_loop(parser_data, args, num_args);
	return (args);
}

t_command_list	*ft_build_command(t_parser_data *parser_data)
{
	char			**args;
	t_command_list	*node;

	ft_remove_redirections(parser_data);
	args = ft_build_command_arguments(parser_data);
	if (!args)
		return (NULL);
	node = ft_command_list_create_node(args,
			parser_data->num_redirections,
			parser_data->redirections);
	if (!node)
	{
		ft_free_array(args);
		return (NULL);
	}
	return (node);
}

t_lexer_list	*ft_get_next_command(t_lexer_list *lexer_lst)
{
	while (lexer_lst && lexer_lst->token != PIPE)
		lexer_lst = lexer_lst->next;
	return (lexer_lst);
}
