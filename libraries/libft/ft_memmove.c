/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaro-ro <mcaro-ro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 12:32:14 by mcaro-ro          #+#    #+#             */
/*   Updated: 2025/06/03 19:37:12 by mcaro-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	const char	*pt_src;
	char		*pt_dst;
	size_t		i;

	pt_src = src;
	pt_dst = dst;
	if (pt_src == pt_dst || n == 0)
		return (pt_dst);
	if (pt_src < pt_dst)
	{
		i = n;
		while (i > 0)
		{
			i--;
			pt_dst[i] = pt_src[i];
		}
	}
	else
		ft_memcpy(pt_dst, pt_src, n);
	return (pt_dst);
}
