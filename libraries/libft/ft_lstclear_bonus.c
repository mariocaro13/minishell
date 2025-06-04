/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaro-ro <mcaro-ro@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 12:37:51 by mcaro-ro          #+#    #+#             */
/*   Updated: 2024/02/27 12:37:52 by mcaro-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*current_lst;

	if (lst && del)
	{
		while (*lst)
		{
			current_lst = *lst;
			*lst = current_lst->next;
			del(current_lst->content);
			free(current_lst);
		}
	}
}
