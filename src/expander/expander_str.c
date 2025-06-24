/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalvez- <mgalvez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 14:59:34 by mgalvez-          #+#    #+#             */
/*   Updated: 2025/06/24 14:59:35 by mgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_expand_str(t_shell_data *shell_data, char *str)
{
	char	*tmp;
	char	*dollar_ptr;

	tmp = NULL;
	dollar_ptr = ft_strchr(str, SYMBOL_DOLLAR);
	if (dollar_ptr != NULL)
	{
		if (dollar_ptr == str
			|| (dollar_ptr > str && *(dollar_ptr - 2) != SYMBOL_QUOTE))
		{
			tmp = ft_detect_dollar_sign(shell_data, str);
			free(str);
			str = tmp;
		}
	}
	str = ft_apply_del_quotes(str, SYMBOL_QUOTE_DOUBLE);
	str = ft_apply_del_quotes(str, SYMBOL_QUOTE);
	return (str);
}
