/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaro-ro <mcaro-ro@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 19:23:06 by mcaro-ro          #+#    #+#             */
/*   Updated: 2024/02/22 19:45:05 by mcaro-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	len_s;

	if (!s)
		return (NULL);
	len_s = ft_strlen(s);
	if (start > len_s)
	{
		str = ft_calloc(1, sizeof(char));
		if (!str)
			return (NULL);
		*str = '\0';
		return (str);
	}
	if (len > len_s - start)
		len = len_s - start;
	str = ft_calloc((len + 1), sizeof(char));
	if (str)
	{
		ft_strlcpy(str, s + start, len + 1);
		return (str);
	}
	free(str);
	return (NULL);
}
