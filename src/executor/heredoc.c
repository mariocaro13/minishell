#include "minishell.h"

/**
 * @brief Reads a line from the user for heredoc input, checks for delimiter,
 * expands variables if needed, and writes to file.
 *
 * Prompts the user for input, compares the line to the heredoc delimiter,
 * and if not matched, expands variables
 * (unless the delimiter is quoted) and writes the line to the heredoc file.
 *
 * @param heredoc Pointer to the heredoc lexer node.
 * @param is_quoted True if the delimiter is quoted (no variable expansion).
 * @param shell_data Pointer to the main shell data structure.
 * @param fd File descriptor to write the heredoc content.
 * @return true to continue reading lines, false to stop
 * (delimiter found or EOF).
 */
static int	ft_process_heredoc_line(t_lexer_list *heredoc, bool is_quoted,
	t_shell_data *shell_data, int fd)
{
	char	*line;

	line = readline(COLOR_BLUE MSG_HEREDOC COLOR_RESET);
	if (!line)
		return (false);
	if (ft_strncmp(line, heredoc->str, ft_strlen(heredoc->str) + 1) == 0)
	{
		free(line);
		return (false);
	}
	if (!is_quoted)
		line = ft_expand_str(shell_data, line);
	write(fd, line, ft_strlen(line));
	write(fd, "\n", 1);
	free(line);
	return (true);
}

/**
 * @brief Creates the heredoc temporary file and writes user input to it.
 *
 * Opens the file for writing, then repeatedly reads lines from the user
 * and writes them to the file until the delimiter is found or heredoc is
 * interrupted.
 *
 * @param heredoc Pointer to the heredoc lexer node.
 * @param is_quoted True if the delimiter is quoted (no variable expansion).
 * @param shell_data Pointer to the main shell data structure.
 * @param file_name Name of the heredoc temporary file to create.
 * @return EXIT_SUCCESS on success, EXIT_FAILURE on error or interruption.
 */
static int	ft_create_heredoc(t_lexer_list *heredoc, bool is_quoted,
	t_shell_data *shell_data, char *file_name)
{
	int		fd;

	fd = open(file_name, O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (fd < 0)
		return (EXIT_FAILURE);
	while (ft_process_heredoc_line(heredoc, is_quoted, shell_data, fd))
		;
	close(fd);
	if (shell_data->state.should_stop_heredoc)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

/**
 * @brief Checks if a heredoc delimiter is quoted.
 *
 * Determines if the delimiter string is surrounded by single or double quotes.
 * Used to decide if variable expansion should occur in heredoc input.
 *
 * @param str The delimiter string.
 * @return true if quoted, false otherwise.
 */
static bool	ft_is_quoted(const char *str)
{
	size_t	len;

	len = ft_strlen(str);
	if (len < 2)
		return (false);
	if ((str[0] == SYMBOL_QUOTE_DOUBLE && str[len - 1] == SYMBOL_QUOTE_DOUBLE)
		|| (str[0] == SYMBOL_QUOTE && str[len - 1] == SYMBOL_QUOTE))
		return (true);
	return (false);
}

/**
 * @brief Processes the heredoc logic for a single heredoc redirection.
 *
 * Removes quotes from the delimiter, sets heredoc state, and calls the heredoc
 * creation routine.
 *
 * @param shell_data Pointer to the main shell data structure.
 * @param heredoc Pointer to the heredoc lexer node.
 * @param file_name Name of the heredoc temporary file to create.
 * @return EXIT_SUCCESS on success, EXIT_FAILURE on error or interruption.
 */
static int	ft_process_heredoc(t_shell_data *shell_data, t_lexer_list *heredoc,
	char *file_name)
{
	bool	is_quoted;
	int		result;

	result = EXIT_SUCCESS;
	is_quoted = ft_is_quoted(heredoc->str);
	ft_del_quotes(heredoc->str, SYMBOL_QUOTE_DOUBLE);
	ft_del_quotes(heredoc->str, SYMBOL_QUOTE);
	shell_data->state.should_stop_heredoc = false;
	g_is_in_heredoc = true;
	result = ft_create_heredoc(heredoc, is_quoted, shell_data, file_name);
	g_is_in_heredoc = false;
	shell_data->heredoc = true;
	return (result);
}

int	ft_handle_heredoc(t_shell_data *shell_data, t_command_list *command_list)
{
	t_lexer_list	*redir;
	int				result;

	redir = command_list->redirections;
	result = EXIT_SUCCESS;
	while (redir)
	{
		if (redir->token == REDIRECT_HEREDOC)
		{
			if (command_list->heredoc_file_name)
				free(command_list->heredoc_file_name);
			command_list->heredoc_file_name = ft_create_heredoc_filename();
			result = ft_process_heredoc(shell_data, redir,
					command_list->heredoc_file_name);
			if (result != EXIT_SUCCESS)
			{
				shell_data->state.error_num = 1;
				return (ft_reset_shell_loop(shell_data));
			}
		}
		redir = redir->next;
	}
	return (EXIT_SUCCESS);
}
