#include "minishell.h"

char	*ft_get_trimmed_line(void)
{
	char	*line;
	char	*trimmed;

	line = readline(COLOR_GREEN_BOLD MSG_PROMPT COLOR_RESET);
	if (!line)
		return (NULL);
	trimmed = ft_strtrim(line, " ");
	free(line);
	if (!trimmed)
		return (NULL);
	return (trimmed);
}
