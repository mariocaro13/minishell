/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaro-ro <mcaro-ro@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 18:43:32 by mcaro-ro          #+#    #+#             */
/*   Updated: 2024/01/25 20:40:06 by mcaro-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dst_size)
{
	size_t	i_src;
	size_t	i_dst;
	size_t	len_src;
	size_t	len_dst;

	i_src = 0;
	len_src = ft_strlen(src);
	i_dst = ft_strlen(dst);
	len_dst = ft_strlen(dst);
	if (dst_size < i_dst)
		return (dst_size + ft_strlen(src));
	while (i_dst + 1 < dst_size && src[i_src] != '\0')
	{
		dst[i_dst] = src[i_src];
		i_dst++;
		i_src++;
	}
	dst[i_dst] = '\0';
	return (len_dst + len_src);
}
