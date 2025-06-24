/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalvez- <mgalvez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 14:59:46 by mgalvez-          #+#    #+#             */
/*   Updated: 2025/06/24 14:59:47 by mgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief Determines if a string should be expanded for variables.
 *
 * Checks if there is a dollar sign in the string and if it is not inside quotes.
 *
 * @param str The string to check.
 * @return true if the string should be expanded, false otherwise.
 */
static bool	ft_should_expand(char *str)
{
	int	pos;

	pos = ft_get_dollar_sign_index(str);
	if (pos == 0)
		return (false);
	if (pos < 2)
		return (true);
	if (str[pos - 2] == SYMBOL_QUOTE)
		return (false);
	return (true);
}

/**
 * @brief Checks if the command is 'export'.
 *
 * Used to avoid removing quotes from arguments of the export builtin.
 *
 * @param command The command string to check.
 * @return true if the command is 'export', false otherwise.
 */
static bool	ft_is_export_command(const char *command)
{
	if (!command)
		return (false);
	return (ft_strncmp(command, EXPORT, EXPORT_LEN) == 0);
}

/**
 * @brief Expands variables in redirection file names for a command.
 *
 * Iterates through the redirections list and expands variables in each
 * file name, except for heredoc redirections.
 *
 * @param shell_data Pointer to the main shell data structure.
 * @param command_list Pointer to the command list node.
 */
static void	ft_expand_command_redirections(t_shell_data *shell_data,
	t_command_list *command_list)
{
	t_lexer_list	*current;

	if (!command_list)
		return ;
	current = command_list->redirections;
	while (current)
	{
		if (current->token != REDIRECT_HEREDOC && current->str)
			current->str = ft_expand_str(shell_data, current->str);
		current = current->next;
	}
}

char	**ft_expand_command_args(t_shell_data *shell_data, char **str)
{
	int		index;
	char	*tmp;

	index = 0;
	tmp = NULL;
	while (str[index] != NULL)
	{
		if (ft_should_expand(str[index]))
		{
			tmp = ft_detect_dollar_sign(shell_data, str[index]);
			free(str[index]);
			str[index] = tmp;
		}
		if (!ft_is_export_command(str[0]))
		{
			str[index] = ft_apply_del_quotes(str[index], SYMBOL_QUOTE_DOUBLE);
			str[index] = ft_apply_del_quotes(str[index], SYMBOL_QUOTE);
		}
		index++;
	}
	return (str);
}

void	ft_expander_caller(t_shell_data *shell_data,
	t_command_list **command_list)
{
	if (!command_list || !(*command_list))
		return ;
	if ((*command_list)->str)
		(*command_list)->str = ft_expand_command_args(shell_data,
				(*command_list)->str);
	ft_expand_command_redirections(shell_data, *command_list);
}
