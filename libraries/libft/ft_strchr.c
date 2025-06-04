/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaro-ro <mcaro-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 12:33:01 by mcaro-ro          #+#    #+#             */
/*   Updated: 2024/02/27 14:57:43 by mcaro-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*pt_s;

	pt_s = (char *)s;
	if ((char)c == '\0')
		return (pt_s + ft_strlen(pt_s));
	while (*pt_s != '\0')
	{
		if (*pt_s == (char)c)
			return (pt_s);
		pt_s++;
	}
	return (NULL);
}
