/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_commands.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalvez- <mgalvez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 14:57:34 by mgalvez-          #+#    #+#             */
/*   Updated: 2025/06/24 14:57:35 by mgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_command_list	*ft_build_command_node(t_shell_data *shell_data,
	t_parser_data *parser_data)
{
	t_command_list	*cmd_node;

	*parser_data = ft_init_parser_data(shell_data->lexer_list, shell_data);
	cmd_node = ft_build_command(parser_data);
	return (cmd_node);
}

void	ft_command_list_append_node(t_shell_data *shell_data,
	t_command_list *cmd_node)
{
	if (!shell_data->command_list)
		shell_data->command_list = cmd_node;
	else
		ft_command_list_add_node_back(&shell_data->command_list, cmd_node);
}

t_command_list	*ft_command_list_create_node(char **str,
	int num_redirections, t_lexer_list *redirections)
{
	t_command_list	*new_node;

	new_node = (t_command_list *)malloc(sizeof(t_command_list));
	if (!new_node)
		return (NULL);
	new_node->str = str;
	new_node->builtin = ft_get_builtin_function(str[0]);
	new_node->heredoc_file_name = NULL;
	new_node->num_redirections = num_redirections;
	new_node->redirections = redirections;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}

void	ft_command_list_add_node_back(t_command_list **command_list,
	t_command_list *new_node)
{
	t_command_list	*tmp;

	tmp = *command_list;
	if (*command_list == NULL)
	{
		*command_list = new_node;
		return ;
	}
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new_node;
	new_node->prev = tmp;
}

t_command_list	*ft_command_list_get_first(t_command_list *map)
{
	int	index;

	index = 0;
	if (!map)
		return (NULL);
	while (map->prev != NULL)
	{
		map = map->prev;
		index++;
	}
	return (map);
}
