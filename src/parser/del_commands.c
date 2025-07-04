/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_commands.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalvez- <mgalvez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 14:57:39 by mgalvez-          #+#    #+#             */
/*   Updated: 2025/06/24 14:57:40 by mgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_command_list_del_first(t_command_list **command_list)
{
	t_command_list	*next_node;

	if (!command_list || !*command_list)
		return ;
	next_node = (*command_list)->next;
	ft_lexer_clear(&(*command_list)->redirections);
	free(*command_list);
	*command_list = next_node;
}

void	ft_command_list_clear(t_command_list **command_list)
{
	t_command_list	*next_node;
	t_lexer_list	*redirections_tmp;

	if (!*command_list)
		return ;
	while (*command_list)
	{
		next_node = (*command_list)->next;
		redirections_tmp = (*command_list)->redirections;
		ft_lexer_clear(&redirections_tmp);
		if ((*command_list)->str)
		{
			ft_free_array((*command_list)->str);
			(*command_list)->str = NULL;
		}
		if ((*command_list)->heredoc_file_name)
		{
			free((*command_list)->heredoc_file_name);
			(*command_list)->heredoc_file_name = NULL;
		}
		free(*command_list);
		*command_list = next_node;
	}
	*command_list = NULL;
}
