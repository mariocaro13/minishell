/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaro-ro <mcaro-ro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 12:06:55 by mcaro-ro          #+#    #+#             */
/*   Updated: 2025/06/03 19:37:12 by mcaro-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_find_char_in_list(const t_list *node, const char c)
{
	int	i;

	if (!node)
		return (0);
	while (node)
	{
		i = 0;
		while (((char *)node->content)[i] && i < INT_MAX)
		{
			if (((char *)node->content)[i] == c)
				return (1);
			i++;
		}
		node = node->next;
	}
	return (0);
}

t_list	*ft_get_last_node(t_list *node)
{
	if (!node)
		return (NULL);
	while (node->next != NULL)
		node = node->next;
	return (node);
}

void	ft_free_list(t_list **list_head)
{
	t_list	*aux;

	if (!list_head)
		return ;
	while (*list_head)
	{
		aux = (*list_head)->next;
		free((*list_head)->content);
		free(*list_head);
		*list_head = aux;
	}
	*list_head = NULL;
}

void	ft_set_content_cleaned(t_list **list_head, char *str)
{
	t_list	*last_node;
	int		i_c;
	int		i_str;

	last_node = ft_get_last_node(*list_head);
	i_c = 0;
	while (((char *)last_node->content)[i_c] != NEWLINE_CHAR
			&& ((char *)last_node->content)[i_c])
		i_c++;
	i_str = 0;
	while (((char *)last_node->content)[i_c]
			&& ((char *)last_node->content)[i_c + 1])
		str[i_str++] = ((char *)last_node->content)[++i_c];
	str[i_str] = NULL_TERMINATE;
}

void	ft_clean_list(t_list **list_head)
{
	t_list	*new_head;
	char	*str;

	if (!list_head)
		return ;
	str = malloc(BUFFER_SIZE + NULL_TERMINATE_SIZE);
	if (!str)
		return ;
	new_head = malloc(sizeof(t_list));
	if (!new_head)
		return (free(str));
	ft_set_content_cleaned(list_head, str);
	new_head->content = str;
	new_head->next = NULL;
	ft_free_list(list_head);
	if (*((char *)new_head->content) == '\0')
		return (free(str), free(new_head));
	*list_head = new_head;
}
