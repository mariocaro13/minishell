/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaro-ro <mcaro-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 19:23:38 by mcaro-ro          #+#    #+#             */
/*   Updated: 2024/02/27 14:59:43 by mcaro-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	len;

	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	str = (char *)ft_calloc(len, sizeof(char));
	if (str)
	{
		ft_strlcpy(str, s1, ft_strlen(s1) + 1);
		ft_strlcat(str, s2, len);
		return (str);
	}
	return (NULL);
}
