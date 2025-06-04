/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaro-ro <mcaro-ro@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 12:37:35 by mcaro-ro          #+#    #+#             */
/*   Updated: 2024/02/27 12:37:39 by mcaro-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*current_lst;

	if (lst && new)
	{
		if (*lst == NULL)
			*lst = new;
		else
		{
			current_lst = ft_lstlast(*lst);
			current_lst->next = new;
		}
	}
}
