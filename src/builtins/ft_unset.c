/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaro-ro <mcaro-ro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 15:04:19 by mcaro-ro          #+#    #+#             */
/*   Updated: 2025/06/24 15:04:21 by mcaro-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief Checks if an environment entry matches the given variable name.
 *
 * @param env_entry The environment entry string.
 * @param var_name The variable name to match.
 * @return EXIT_SUCCESS if matches, EXIT_FAILURE otherwise.
 */
static int	ft_env_var_match(const char *env_entry, const char *var_name)
{
	size_t	len;

	len = ft_strlen(var_name);
	if (ft_strncmp(env_entry, var_name, len) == 0
		&& env_entry[len] == SYMBOL_EQUAL)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

/**
 * @brief Processes environment entries and copies those not matching var_name.
 *
 * @param envp The original environment array.
 * @param var_name The variable name to remove.
 * @param new_env The new environment array to fill.
 * @return EXIT_SUCCESS on success, EXIT_FAILURE on allocation error.
 */
static int	ft_process_env_entries(char **envp, const char *var_name,
	char **new_env)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (envp[i])
	{
		if (ft_env_var_match(envp[i], var_name) == EXIT_SUCCESS)
		{
			i++;
			continue ;
		}
		new_env[j] = ft_strdup(envp[i]);
		if (!new_env[j])
			return (EXIT_FAILURE);
		i++;
		j++;
	}
	new_env[j] = NULL;
	return (EXIT_SUCCESS);
}

/**
 * @brief Removes a variable from the environment array.
 *
 * @param envp The original environment array.
 * @param var_name The variable name to remove.
 * @return The new environment array without the variable, or NULL on error.
 */
static char	**ft_remove_env_var(char **envp, const char *var_name)
{
	size_t	total;
	char	**new_env;

	total = ft_count_envp(envp);
	new_env = ft_calloc(total + 1, sizeof(char *));
	if (!new_env)
		return (NULL);
	if (ft_process_env_entries(envp, var_name, new_env) != EXIT_SUCCESS)
	{
		ft_free_array(new_env);
		return (NULL);
	}
	return (new_env);
}

/**
 * @brief Checks for errors in the unset command arguments.
 *
 * This function:
 *   - Validates the argument for unset.
 *   - Prints errors for invalid identifiers or missing arguments.
 *
 * @param command_list Pointer to the command list.
 * @return EXIT_SUCCESS if valid, EXIT_FAILURE if error.
 */
static int	ft_unset_error(t_command_list *command_list)
{
	int	i;

	if (!command_list->str[1])
	{
		ft_putendl_fd(COLOR_RED_BOLD MSG_DEFAULT_PROMPT COLOR_RESET
			MSG_ERR_UNSET_NOT_ENOUGH_ARGS, STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	i = 0;
	while (command_list->str[1][i])
	{
		if (command_list->str[1][i] == '/')
		{
			ft_error_print_unset_slash_error(command_list);
			return (EXIT_FAILURE);
		}
		i++;
	}
	if (ft_strchr(command_list->str[1], SYMBOL_EQUAL) != NULL)
	{
		ft_putendl_fd(COLOR_RED_BOLD MSG_DEFAULT_PROMPT COLOR_RESET
			MSG_ERR_UNSET_INVALID_ID, STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	ft_unset(t_shell_data *shell_data, t_command_list *command_list)
{
	char	**new_env;

	if (ft_unset_error(command_list) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	new_env = ft_remove_env_var(shell_data->envp, command_list->str[1]);
	if (!new_env)
		return (EXIT_FAILURE);
	ft_free_array(shell_data->envp);
	shell_data->envp = new_env;
	return (EXIT_SUCCESS);
}
