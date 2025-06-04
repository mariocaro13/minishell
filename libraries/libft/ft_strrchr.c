/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaro-ro <mcaro-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 12:33:08 by mcaro-ro          #+#    #+#             */
/*   Updated: 2024/02/27 15:00:13 by mcaro-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*pt_s;
	size_t	len;
	char	a;

	a = (char)c;
	pt_s = (char *)s;
	len = ft_strlen(pt_s);
	if (a == '\0')
		return (pt_s + len);
	while (len > 0)
	{
		if (pt_s[len - 1] == a)
			return (pt_s + len - 1);
		len--;
	}
	return (NULL);
}
