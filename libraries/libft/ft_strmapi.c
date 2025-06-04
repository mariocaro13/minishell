/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaro-ro <mcaro-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 16:49:14 by mcaro-ro          #+#    #+#             */
/*   Updated: 2024/02/27 14:58:56 by mcaro-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	size_t	i_str;
	size_t	len_s;

	if (!s || !f)
		return (NULL);
	len_s = ft_strlen(s);
	str = (char *)ft_calloc(len_s + 1, sizeof(char));
	if (str)
	{
		i_str = 0;
		while (i_str < len_s)
		{
			str[i_str] = f(i_str, s[i_str]);
			i_str++;
		}
		return (str);
	}
	return (NULL);
}
