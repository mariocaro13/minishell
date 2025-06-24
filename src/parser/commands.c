/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalvez- <mgalvez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 14:57:36 by mgalvez-          #+#    #+#             */
/*   Updated: 2025/06/24 14:57:37 by mgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief Extracts the argument string from the current lexer node
 * and removes the node from the lexer list.
 *
 * Duplicates the string from the current lexer node, deletes the node
 * from the lexer list, and returns the duplicated string.
 *
 * @param parser_data Pointer to the parser data structure.
 * @return Newly allocated string containing the argument, or NULL on
 * allocation failure.
 */
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

/**
 * @brief Fills the arguments array by extracting arguments from the lexer list.
 *
 * Iterates through the lexer list, extracts each argument using 
 * t_extract_token_argument, and fills the args array. Sets the last element
 * to NULL.
 *
 * @param parser_data Pointer to the parser data structure.
 * @param args Array of strings to fill with arguments.
 * @param num_arg Number of arguments to extract.
 */
static void	ft_build_arguments_loop(t_parser_data *parser_data,
	char **args, int num_arg)
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

/**
 * @brief Builds the array of command arguments from the parser data.
 *
 * Counts the number of argument tokens, allocates the array, and fills it
 * using ft_build_arguments_loop. Handles memory errors.
 *
 * @param parser_data Pointer to the parser data structure.
 * @return Newly allocated array of argument strings, or NULL on allocation
 * failure.
 */
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
