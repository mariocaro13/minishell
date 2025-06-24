/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaro-ro <mcaro-ro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 15:06:22 by mcaro-ro          #+#    #+#             */
/*   Updated: 2025/06/24 15:06:24 by mcaro-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_append_slash_if_missing(char **path)
{
	size_t	len;
	char	*fixed;

	if (!path || !*path)
		return (EXIT_FAILURE);
	len = ft_strlen(*path);
	if (len > 0 && (*path)[len - 1] != '/')
	{
		fixed = ft_strjoin(*path, "/");
		if (!fixed)
			return (EXIT_FAILURE);
		free(*path);
		*path = fixed;
	}
	return (EXIT_SUCCESS);
}

int	ft_append_slash_to_paths(char **paths)
{
	int	index;

	if (!paths)
		return (EXIT_FAILURE);
	index = 0;
	while (paths[index])
	{
		if (ft_append_slash_if_missing(&paths[index]) != EXIT_SUCCESS)
			return (EXIT_FAILURE);
		index++;
	}
	return (EXIT_SUCCESS);
}
