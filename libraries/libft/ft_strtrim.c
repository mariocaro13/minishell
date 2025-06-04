/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaro-ro <mcaro-ro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 19:23:51 by mcaro-ro          #+#    #+#             */
/*   Updated: 2025/06/03 19:37:12 by mcaro-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_index_first_nonmember(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	bool	found;

	i = 0;
	while (s1[i] != '\0')
	{
		j = 0;
		found = 0;
		while (set[j] != '\0')
		{
			if (s1[i] == set[j])
			{
				found = true;
				break ;
			}
			j++;
		}
		if (!found)
			break ;
		i++;
	}
	return (i);
}

static size_t	ft_get_len(char const *aux, char const *set)
{
	size_t	i_set;
	size_t	i_aux;
	size_t	aux_len;

	aux_len = ft_strlen(aux);
	if (aux_len == 0)
		return (0);
	i_set = 0;
	i_aux = aux_len - 1;
	if (i_aux <= 0)
		return (0);
	while (set[i_set] != '\0')
	{
		if (aux[i_aux] == set[i_set])
		{
			i_set = 0;
			if (i_aux == 0)
				return (0);
			i_aux--;
		}
		else
			i_set++;
	}
	return (i_aux + 1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	char	*aux;
	size_t	len;
	size_t	start;

	if (!s1 || !set)
		return (NULL);
	start = ft_index_first_nonmember(s1, set);
	aux = (char *)s1 + start;
	len = ft_get_len(aux, set) + 1;
	str = (char *)ft_calloc(len, sizeof(char));
	if (str)
	{
		ft_strlcpy(str, aux, len);
		return (str);
	}
	return (NULL);
}
