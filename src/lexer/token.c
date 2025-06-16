#include "minishell.h"

/**
 * @brief Gets the length of the next token in the input string.
 *
 * Determines the token type at the given start index and delegates to
 * the appropriate handler: if it is a special token (operator),
 * calls ft_handle_token; otherwise, calls ft_tokenize_word.
 *
 * @param shell_data Pointer to the main shell data structure.
 * @param token_start Index in the input string where the token starts.
 * @return Length of the token processed, or -1 on error.
 */
static int	ft_get_token_len(t_shell_data *shell_data, int token_start)
{
	t_token	token_type;

	token_type = ft_get_token_type(shell_data->args, token_start);
	if (ft_is_special_token(token_type))
		return (ft_handle_token(shell_data->args,
				token_start,
				&shell_data->lexer_list));
	else
		return (ft_tokenize_word(token_start,
				shell_data->args,
				&shell_data->lexer_list));
}

/**
 * @brief Consumes the next token in the input string, skipping whitespace.
 *
 * Skips leading spaces, determines the start of the next token,
 * and processes it.
 * Returns the total number of characters consumed (spaces + token length).
 *
 * @param shell_data Pointer to the main shell data structure.
 * @param start Index in the input string to start processing.
 * @return Number of characters consumed, or -1 on error.
 */
static int	ft_consume_token(t_shell_data *shell_data, int start)
{
	int	spaces_skipped;
	int	token_start;
	int	token_length;

	spaces_skipped = ft_skip_spaces(shell_data->args, start);
	token_start = start + spaces_skipped;
	if (shell_data->args[token_start] == '\0')
		return (spaces_skipped);
	token_length = ft_get_token_len(shell_data, token_start);
	if (token_length < 0)
		return (-1);
	return (spaces_skipped + token_length);
}

bool	ft_build_token_list(t_shell_data *shell_data)
{
	int	index;
	int	advance;

	index = 0;
	while (shell_data->args[index])
	{
		advance = ft_consume_token(shell_data, index);
		if (advance < 0)
			return (false);
		index += advance;
	}
	return (true);
}
