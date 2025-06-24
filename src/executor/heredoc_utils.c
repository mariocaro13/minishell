/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalvez- <mgalvez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 14:58:17 by mgalvez-          #+#    #+#             */
/*   Updated: 2025/06/24 14:58:18 by mgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_create_heredoc_filename(void)
{
	static int	index = 0;
	char		*num;
	char		*file_name;

	num = ft_itoa(index++);
	file_name = ft_strjoin(FILENAME_HEREDOC, num);
	free(num);
	return (file_name);
}

int	ft_get_fd_heredoc(t_shell_data *shell_data, int end[2],
	t_command_list *command_list)
{
	int	fd_in;

	if (shell_data->heredoc && command_list->heredoc_file_name != NULL)
	{
		close(end[0]);
		fd_in = open(command_list->heredoc_file_name, O_RDONLY);
	}
	else
		fd_in = end[0];
	return (fd_in);
}
