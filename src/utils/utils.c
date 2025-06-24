/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaro-ro <mcaro-ro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 15:06:34 by mcaro-ro          #+#    #+#             */
/*   Updated: 2025/06/24 15:06:35 by mcaro-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	ft_is_whitespace(char c)
{
	return (c == ' ' || (c > 8 && c < 14));
}

bool	ft_is_operator_char(char c)
{
	return (c == SYMBOL_PIPE
		|| c == SYMBOL_LESS_THAN
		|| c == SYMBOL_GREATER_THAN);
}

bool	ft_is_special_token(const t_token token)
{
	return (token == PIPE
		|| token == REDIRECT_IN
		|| token == REDIRECT_HEREDOC
		|| token == REDIRECT_OUT
		|| token == REDIRECT_OUT_APPEND);
}

int	ft_skip_spaces(char *str, int start)
{
	int	index;

	index = 0;
	while (ft_is_whitespace(str[start + index]))
		index++;
	return (index);
}

char	**ft_duplicate_string_array(char **arr)
{
	char	**dup_array;
	size_t	count;
	size_t	index;

	count = 0;
	while (arr[count] != NULL)
		count++;
	dup_array = ft_calloc(sizeof(char *), count + 1);
	if (!dup_array)
		return (NULL);
	index = 0;
	while (index < count)
	{
		dup_array[index] = ft_strdup(arr[index]);
		if (!dup_array[index])
		{
			ft_free_array(dup_array);
			return (NULL);
		}
		index++;
	}
	return (dup_array);
}
