/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaro-ro <mcaro-ro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 15:04:09 by mcaro-ro          #+#    #+#             */
/*   Updated: 2025/06/24 15:04:10 by mcaro-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief Updates an existing environment variable if it matches the given
 * string.
 *
 * This function:
 *   - Searches for a variable with the same name as in str.
 *   - Updates its value if found.
 *
 * @param shell_data Pointer to the main shell data structure.
 * @param str The variable assignment string.
 * @return 1 if updated, 0 if not found.
 */
static int	ft_update_env_var(t_shell_data *shell_data, char *str)
{
	int	index;
	int	equal_index;

	index = 0;
	equal_index = ft_get_equal_sign_index(str);
	if (str[equal_index] == SYMBOL_QUOTE_DOUBLE)
		ft_del_quotes(str, SYMBOL_QUOTE_DOUBLE);
	if (str[equal_index] == SYMBOL_QUOTE)
		ft_del_quotes(str, SYMBOL_QUOTE);
	while (shell_data->envp[index])
	{
		if (ft_strncmp(shell_data->envp[index],
				str, ft_get_equal_sign_index(shell_data->envp[index])) == 0)
		{
			free(shell_data->envp[index]);
			shell_data->envp[index] = ft_strdup(str);
			return (1);
		}
		index++;
	}
	return (0);
}

/**
 * @brief Checks if the export parameter is valid.
 *
 * This function:
 *   - Validates the identifier and assignment format.
 *   - Prints an error if invalid.
 *
 * @param str The parameter string.
 * @return 0 if valid, EXIT_FAILURE if invalid.
 */
static int	ft_check_export_param(char *str)
{
	int	index;

	index = 0;
	if (ft_isdigit(str[0]))
		return (ft_error_print_export(str));
	if (ft_get_equal_sign_index(str) == 0)
		return (EXIT_FAILURE);
	if (str[0] == SYMBOL_EQUAL)
		return (ft_error_print_export(str));
	while (str[index] != SYMBOL_EQUAL)
	{
		if (ft_check_valid_identifier(str[index]))
			return (ft_error_print_export(str));
		index++;
	}
	return (EXIT_SUCCESS);
}

/**
 * @brief Copies the environment array and adds a new variable at the end.
 *
 * @param arr The original environment array.
 * @param rtn The new array to fill.
 * @param str The variable to add.
 * @return The new environment array.
 */
static char	**ft_copy_env_with_new_var(char **arr, char **rtn, char *str)
{
	int	index;

	index = 0;
	while (arr[index] != NULL)
	{
		if (arr[index + 1] == NULL)
		{
			rtn[index] = ft_strdup(str);
			rtn[index + 1] = ft_strdup(arr[index]);
		}
		else
			rtn[index] = ft_strdup(arr[index]);
		if (rtn[index] == NULL)
		{
			ft_free_array(rtn);
			return (rtn);
		}
		index++;
	}
	return (rtn);
}

/**
 * @brief Adds a new environment variable to the array.
 *
 * @param arr The original environment array.
 * @param str The variable to add.
 * @return The new environment array with the variable added.
 */
static char	**ft_add_env_var(char **arr, char *str)
{
	char	**result;
	size_t	index;

	index = 0;
	if (str[ft_get_equal_sign_index(str)] == SYMBOL_QUOTE_DOUBLE)
		ft_del_quotes(str, SYMBOL_QUOTE_DOUBLE);
	if (str[ft_get_equal_sign_index(str)] == SYMBOL_QUOTE)
		ft_del_quotes(str, SYMBOL_QUOTE);
	while (arr[index] != NULL)
		index++;
	result = ft_calloc(index + 2, sizeof(char *));
	if (!result)
		return (NULL);
	index = 0;
	ft_copy_env_with_new_var(arr, result, str);
	return (result);
}

int	ft_export(t_shell_data *shell_data, t_command_list *command_list)
{
	char	**tmp;
	int		index;

	index = 1;
	if (!command_list->str[1] || command_list->str[1][0] == '\0')
		ft_env(shell_data, command_list);
	else
	{
		while (command_list->str[index])
		{
			if (ft_check_export_param(command_list->str[index]) == 0
				&& ft_update_env_var(shell_data, command_list->str[index]) == 0)
			{
				if (command_list->str[index])
				{
					tmp = ft_add_env_var(shell_data->envp,
							command_list->str[index]);
					ft_free_array(shell_data->envp);
					shell_data->envp = tmp;
				}
			}
			index++;
		}
	}
	return (EXIT_SUCCESS);
}
