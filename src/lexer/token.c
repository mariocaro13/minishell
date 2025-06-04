#include "minishell.h"

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
