/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalvez- <mgalvez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 14:58:38 by mgalvez-          #+#    #+#             */
/*   Updated: 2025/06/24 14:58:39 by mgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_init_shell_envp(t_shell_data *shell_data, char **envp)
{
	if (!shell_data || !envp)
		return (EXIT_FAILURE);
	shell_data->envp = ft_duplicate_string_array(envp);
	if (!shell_data->envp)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	ft_init_env_paths(t_shell_data *shell_data)
{
	if (!shell_data || !shell_data->envp)
		return (EXIT_FAILURE);
	shell_data->paths = ft_split_env_paths(shell_data->envp);
	if (!shell_data->paths)
		return (EXIT_FAILURE);
	if (ft_append_slash_to_paths(shell_data->paths) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
