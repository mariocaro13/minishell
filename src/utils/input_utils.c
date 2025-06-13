#include "minishell.h"

char	*ft_get_trimmed_line(t_shell_data *shell_data)
{
	char	*line;
	char	*trimmed;
	char	*prompt;
	bool	should_free_prompt;

	prompt = ft_build_prompt(shell_data);
	if (!prompt)
	{
		prompt = MSG_DEFAULT_PROMPT;
		should_free_prompt = false;
	}
	else
		should_free_prompt = true;
	line = readline(prompt);
	if (should_free_prompt)
		free(prompt);
	if (!line)
		return (NULL);
	trimmed = ft_strtrim(line, " ");
	free(line);
	if (!trimmed)
		return (NULL);
	return (trimmed);
}

char	*ft_build_prompt(t_shell_data *shell_data)
{
	char	*to_show;
	char	*tmp;
	char	*prompt;

	if (!shell_data || !shell_data->pwd)
		return (NULL);
	if (ft_strncmp(shell_data->pwd, HOME, HOME_LEN) == 0
		&& ft_strchr(shell_data->pwd + HOME_LEN, '/'))
		to_show = ft_strjoin("~", ft_strchr(shell_data->pwd + HOME_LEN, '/'));
	else
		to_show = ft_strdup(shell_data->pwd);
	if (!to_show)
		return (NULL);
	prompt = ft_strjoin(COLOR_MAGENTA_BOLD MSG_PWD_PROMPT COLOR_CYAN_BOLD,
			to_show);
	free(to_show);
	if (!prompt)
		return (NULL);
	tmp = ft_strjoin(prompt, COLOR_RESET);
	free(prompt);
	if (!tmp)
		return (NULL);
	prompt = ft_strjoin(tmp, COLOR_MAGENTA_BOLD "> " COLOR_RESET);
	free(tmp);
	return (prompt);
}
