/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalvez- <mgalvez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 15:09:32 by mgalvez-          #+#    #+#             */
/*   Updated: 2025/06/24 15:09:33 by mgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "minishell.h"

int	ft_strip_env_prefix(char **dest, char *env_entry, size_t prefix_len)
{
	if (!dest || !env_entry)
		return (EXIT_FAILURE);
	*dest = ft_substr(env_entry, prefix_len, ft_strlen(env_entry) - prefix_len);
	if (!*dest)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

char	*ft_get_env_path(char **envp)
{
	int		index;
	char	*result;

	if (!envp)
		return (NULL);
	index = 0;
	while (envp[index])
	{
		if (!ft_strncmp(envp[index], PATH_PREFIX, PATH_PREFIX_LEN))
		{
			if (ft_strip_env_prefix(&result, envp[index], PATH_PREFIX_LEN)
				!= EXIT_SUCCESS)
				return (NULL);
			return (result);
		}
		index++;
	}
	return (ft_strdup(""));
}

char	**ft_split_env_paths(char **envp)
{
	char	*env_path;
	char	**paths;

	env_path = ft_get_env_path(envp);
	if (!env_path)
		return (NULL);
	paths = ft_split(env_path, ':');
	free(env_path);
	if (!paths)
		return (NULL);
	return (paths);
}

size_t	ft_count_envp(char **envp)
{
	size_t	count;

	count = 0;
	while (envp[count])
		count++;
	return (count);
}
