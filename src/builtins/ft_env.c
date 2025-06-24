/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaro-ro <mcaro-ro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 15:03:58 by mcaro-ro          #+#    #+#             */
/*   Updated: 2025/06/24 15:04:00 by mcaro-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_env(t_shell_data *shell_data, t_command_list *command_list)
{
	int		index;

	(void) command_list;
	if (!shell_data || !shell_data->envp)
		return (EXIT_FAILURE);
	index = 0;
	while (shell_data->envp[index])
	{
		ft_putendl_fd(shell_data->envp[index], STDOUT_FILENO);
		index++;
	}
	return (EXIT_SUCCESS);
}
