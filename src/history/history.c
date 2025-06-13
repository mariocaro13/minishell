/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaro-ro <mcaro-ro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 20:38:40 by mcaro-ro          #+#    #+#             */
/*   Updated: 2025/06/13 05:33:47 by mcaro-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*ft_extract_username_from_pwd(const char *pwd)
{
	char		*username;
	const char	*start;
	const char	*slash;
	size_t		len;

	if (ft_strncmp(pwd, HOME, HOME_LEN) != 0)
		return (NULL);
	start = pwd + HOME_LEN;
	slash = ft_strchr(start, '/');
	if (slash)
		len = (size_t)(slash - start);
	else
		len = ft_strlen(start);
	username = ft_calloc(len + 1, sizeof(char));
	if (!username)
		return (NULL);
	ft_strlcpy(username, start, len + 1);
	return (username);
}

char	*ft_make_history_path(const char *pwd)
{
	char	*username;
	char	*path;
	char	*history_path;

	username = ft_extract_username_from_pwd(pwd);
	if (username)
	{
		path = ft_strjoin(HOME, username);
		free(username);
		if (!path)
			return (ft_strdup(HISTORY_FILE));
		history_path = ft_strjoin(path, "/"HISTORY_FILE);
		free(path);
		return (history_path);
	}
	return (ft_strdup(HISTORY_FILE));
}

void	ft_add_to_history(const char *input, t_shell_data *shell_data)
{
	add_history(input);
	ft_save_history_to_file(shell_data->history_path, input);
}

void	ft_save_history_to_file(const char *filename, const char *input)
{
	int		fd;

	fd = open(filename, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (fd == -1)
	{
		perror(MSG_ERR_OPEN_FD);
		return ;
	}
	write(fd, input, ft_strlen(input));
	if (input[ft_strlen(input) - 1] != '\n')
		write(fd, "\n", 1);
	close(fd);
}

void	ft_load_history_from_file(const char *filename)
{
	int		fd;
	int		len;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return ;
	line = get_next_line(fd);
	while (line != NULL)
	{
		len = ft_strlen(line);
		if (len > 0 && line[len - 1] == '\n')
			line[len - 1] = '\0';
		add_history(line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}
