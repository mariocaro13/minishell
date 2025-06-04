/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaro-ro <mcaro-ro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 19:09:10 by mcaro-ro          #+#    #+#             */
/*   Updated: 2025/06/03 19:37:12 by mcaro-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i_hstack;
	size_t	i;

	i_hstack = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (haystack[i_hstack] != '\0')
	{
		i = 0;
		while (haystack[i_hstack + i] == needle[i] && (i_hstack + i) < len)
		{
			if (needle[++i] == '\0')
				return ((char *)&haystack[i_hstack]);
		}
		i_hstack++;
	}
	return (NULL);
}
