/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaro-ro <mcaro-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 18:52:53 by mcaro-ro          #+#    #+#             */
/*   Updated: 2024/02/27 13:05:01 by mcaro-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char	*pt_b;
	size_t	count;

	pt_b = b;
	count = 0;
	while (count < len)
	{
		pt_b[count] = (unsigned char)c;
		count++;
	}
	return (pt_b);
}
