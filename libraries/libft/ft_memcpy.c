/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaro-ro <mcaro-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 12:32:02 by mcaro-ro          #+#    #+#             */
/*   Updated: 2024/02/27 14:57:11 by mcaro-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	const char	*pt_src;
	char		*pt_dst;
	size_t		count;

	if (!dst && !src)
		return (NULL);
	pt_dst = dst;
	pt_src = src;
	count = 0;
	while (count < n)
	{
		pt_dst[count] = pt_src[count];
		count++;
	}
	return (pt_dst);
}
