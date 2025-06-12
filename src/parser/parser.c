#include "minishell.h"

t_parser_data	ft_init_parser_data(t_lexer_list *lexer_list,
	t_shell_data *shell_data)
{
	t_parser_data	parser_data;

	parser_data.lexer_list = lexer_list;
	parser_data.redirections = NULL;
	parser_data.num_redirections = 0;
	parser_data.shell_data = shell_data;
	return (parser_data);
}

static int	ft_validate_current_lexer(t_shell_data *shell_data)
{
	if (!shell_data->lexer_list)
		return (EXIT_FAILURE);
	if (ft_error_pipe_handler(shell_data, shell_data->lexer_list->token))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static int	ft_process_current_lexer(t_shell_data	*shell_data)
{
	t_parser_data	parser_data;
	t_commands_list	*cmd_node;

	if (ft_validate_current_lexer(shell_data) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	cmd_node = ft_build_command_node(shell_data, &parser_data);
	if (!cmd_node)
	{
		ft_error_parser(ERR_SYNTAX, shell_data, parser_data.lexer_list);
		return (EXIT_FAILURE);
	}
	ft_command_list_append_node(shell_data, cmd_node);
	shell_data->lexer_list = parser_data.lexer_list;
	return (EXIT_SUCCESS);
}

int	ft_parse_lexer_list(t_shell_data *shell_data)
{
	shell_data->command_list = NULL;
	shell_data->pipes = ft_count_pipes_in_lexer(shell_data->lexer_list);
	if (shell_data->lexer_list && shell_data->lexer_list->token == PIPE)
		return (ft_error_parser_token(shell_data, shell_data->lexer_list,
				shell_data->lexer_list->token));
	while (shell_data->lexer_list)
	{
		ft_remove_leading_pipe(shell_data);
		if (ft_process_current_lexer(shell_data) != EXIT_SUCCESS)
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
