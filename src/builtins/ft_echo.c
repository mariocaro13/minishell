/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaro-ro <mcaro-ro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 15:03:48 by mcaro-ro          #+#    #+#             */
/*   Updated: 2025/06/24 15:03:53 by mcaro-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief Checks if the given string is a valid -n option for echo.
 *
 * Accepts any string of the form -n, -nn, etc.
 *
 * @param str The string to check.
 * @return true if it is a valid -n option, false otherwise.
 */
static bool	ft_is_n_option(const char *str)
{
	int	index;

	if (!str || str[0] != '-')
		return (false);
	index = 1;
	while (str[index])
	{
		if (str[index] != 'n')
			return (false);
		index++;
	}
	return (true);
}

/**
 * @brief Prints the arguments of echo separated by spaces.
 *
 * @param index Starting index in the argument array.
 * @param str Argument array.
 * @param out Output file descriptor.
 */
static void	ft_print_lines(int index, char **str, int out)
{
	while (str[index])
	{
		ft_putstr_fd(str[index++], out);
		if (str[index])
			ft_putchar_fd(' ', out);
	}
}

int	ft_echo(t_shell_data *shell_data, t_command_list *command_list)
{
	int		index;
	bool	is_n_option;

	(void) shell_data;
	index = 1;
	is_n_option = false;
	while (command_list->str[index] && ft_is_n_option(command_list->str[index]))
	{
		is_n_option = true;
		index++;
	}
	ft_print_lines(index, command_list->str, STDOUT_FILENO);
	if (is_n_option == false)
		ft_putchar_fd('\n', STDOUT_FILENO);
	return (EXIT_SUCCESS);
}
