/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar_sign.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalvez- <mgalvez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 14:59:30 by mgalvez-          #+#    #+#             */
/*   Updated: 2025/06/24 14:59:31 by mgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief Handles the case where a digit follows a dollar sign (e.g., $1, $2).
 *
 * Advances the index by 2 if a digit follows the dollar sign, otherwise does
 * nothing.
 *
 * @param index Current index in the string.
 * @param str The string being processed.
 * @return Number of characters to advance (0 or 2).
 */
static int	ft_handle_digit_after_dollar(int index, char *str)
{
	int	start;

	start = index;
	if (str[index] == SYMBOL_DOLLAR
		&& ft_isdigit((unsigned char)str[index + 1]))
		index += 2;
	return (index - start);
}

/**
 * @brief Processes a dollar token in the string and expands it.
 *
 * Handles special cases like $? and environment variables, and appends the
 * expansion to the result string. Advances the index by the number of characters
 * processed.
 *
 * @param shell_data Pointer to the main shell data structure.
 * @param str The string being processed.
 * @param index Index of the dollar sign in the string.
 * @param result Pointer to the result string to update.
 * @return Number of characters processed for the token.
 */
static int	ft_process_dollar_token(t_shell_data *shell_data,
	char *str, int index, char **result)
{
	int	advance;

	if (str[index + 1] == SYMBOL_QUESTION_MARK)
		advance = ft_process_question_mark(shell_data, result);
	else if (ft_should_process_env(str, index))
		advance = ft_process_env(shell_data, str, index, result);
	else
		advance = 1;
	if (advance < 1)
		advance = 1;
	return (advance);
}

int	ft_get_after_dollar_len(char *str, int start)
{
	int	index;

	index = start + 1;
	while (str[index]
		&& str[index] != SYMBOL_DOLLAR
		&& str[index] != ' '
		&& str[index] != SYMBOL_QUOTE_DOUBLE
		&& str[index] != SYMBOL_QUOTE
		&& str[index] != SYMBOL_EQUAL
		&& str[index] != '-'
		&& str[index] != ':')
		index++;
	return (index);
}

char	*ft_detect_dollar_sign(t_shell_data *shell_data, char *str)
{
	int		index;
	int		advance;
	char	*result;

	index = 0;
	result = ft_strdup("\0");
	if (!result)
		return (NULL);
	while (str[index])
	{
		advance = ft_handle_digit_after_dollar(index, str);
		index += advance;
		if (str[index] == SYMBOL_DOLLAR && str[index + 1])
		{
			advance = ft_process_dollar_token(shell_data, str, index, &result);
			index += advance;
		}
		else
		{
			ft_append_regular_char(str, &index, &result);
			index++;
		}
	}
	return (result);
}

size_t	ft_get_dollar_sign_index(const char *str)
{
	size_t	index;

	index = 0;
	while (str[index])
	{
		if (str[index] == SYMBOL_DOLLAR)
			return (index + 1);
		index++;
	}
	return (0);
}
