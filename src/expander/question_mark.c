/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   question_mark.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalvez- <mgalvez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 14:59:48 by mgalvez-          #+#    #+#             */
/*   Updated: 2025/06/24 14:59:49 by mgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_process_question_mark(t_shell_data *shell_data, char **result)
{
	if (*result)
		free(*result);
	*result = ft_itoa(shell_data->state.error_num);
	return (2);
}
