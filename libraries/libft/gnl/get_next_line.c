/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaro-ro <mcaro-ro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 12:06:41 by mcaro-ro          #+#    #+#             */
/*   Updated: 2025/06/03 19:37:12 by mcaro-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*get_next_line(int fd)
{
	static t_list	*list_head;
	char			*line;

	if (fd < 0)
		return (NULL);
	if (BUFFER_SIZE <= 0 || BUFFER_SIZE >= INT_MAX)
		return (NULL);
	ft_create_list(&list_head, fd);
	if (!list_head)
		return (NULL);
	line = malloc(ft_get_linelen(list_head) + NULL_TERMINATE_SIZE);
	if (!line)
		return (NULL);
	ft_set_line(list_head, line);
	ft_clean_list(&list_head);
	return (line);
}

void	ft_create_list(t_list **list_head, int fd)
{
	char	*buffer;
	ssize_t	bytes_read;

	if (!list_head || fd < 0)
		return ;
	while (!ft_find_char_in_list(*list_head, NEWLINE_CHAR))
	{
		buffer = malloc(BUFFER_SIZE + 1);
		if (!buffer)
			return ;
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
		{
			free (buffer);
			if (bytes_read < 0)
				ft_free_list(list_head);
			return ;
		}
		buffer[bytes_read] = NULL_TERMINATE;
		ft_append_node(list_head, buffer);
	}
}

void	ft_append_node(t_list **list_head, char *content)
{
	t_list	*new_node;
	t_list	*last_node;

	if (!list_head)
		return ;
	last_node = ft_get_last_node(*list_head);
	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return ;
	new_node->content = content;
	new_node->next = NULL;
	if (!last_node)
		*list_head = new_node;
	else
		last_node->next = new_node;
}

int	ft_get_linelen(t_list *node)
{
	int	i;
	int	len;

	if (!node)
		return (0);
	len = 0;
	while (node)
	{
		i = 0;
		while (((char *)node->content)[i])
		{
			if (((char *)node->content)[i] == NEWLINE_CHAR)
			{
				len++;
				return (len);
			}
			len++;
			i++;
		}
		node = node->next;
	}
	return (len);
}

void	ft_set_line(t_list *node, char *str)
{
	int		i_content;
	int		i_str;

	if (!node || !str)
		return ;
	i_str = 0;
	while (node)
	{
		i_content = 0;
		while (((char *)node->content)[i_content])
		{
			if (((char *)node->content)[i_content] == NEWLINE_CHAR)
			{
				str[i_str++] = NEWLINE_CHAR;
				str[i_str] = NULL_TERMINATE;
				return ;
			}
			str[i_str++] = ((char *)node->content)[i_content++];
		}
		node = node->next;
	}
	str[i_str] = NULL_TERMINATE;
}
