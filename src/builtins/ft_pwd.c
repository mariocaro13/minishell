/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaro-ro <mcaro-ro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 15:04:14 by mcaro-ro          #+#    #+#             */
/*   Updated: 2025/06/24 15:04:16 by mcaro-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_pwd(t_shell_data *shell_data, t_command_list *command_list)
{
	(void) command_list;
	if (!shell_data->pwd)
		return (EXIT_FAILURE);
	ft_putendl_fd(shell_data->pwd, STDOUT_FILENO);
	return (EXIT_SUCCESS);
}
