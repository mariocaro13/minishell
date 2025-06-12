#include "minishell.h"

void	ft_remove_leading_pipe(t_shell_data *shell_data)
{
	if (shell_data->lexer_list && shell_data->lexer_list->token == PIPE)
		ft_lexer_del_by_index(&shell_data->lexer_list,
			shell_data->lexer_list->index);
}

int	ft_count_pipes_in_lexer(t_lexer_list *lexer_list)
{
	int	count;

	count = 0;
	while (lexer_list)
	{
		if (lexer_list->token == PIPE)
			count++;
		lexer_list = lexer_list->next;
	}
	return (count);
}

static void	ft_wait_for_child(int pid, int *last_status, bool *is_interrupted)
{
	int	status;

	status = 0;
	waitpid(pid, &status, 0);
	if (WIFSIGNALED(status) && WTERMSIG(status) == SIGINT)
		*is_interrupted = true;
	*last_status = status;
}

static void	ft_wait_for_all_children(int *pid, int amount,
	int *last_status, bool *is_interrupted)
{
	int	index;

	index = 0;
	*is_interrupted = false;
	while (index < amount)
	{
		ft_wait_for_child(pid[index], last_status, is_interrupted);
		index++;
	}
}

int	ft_pipe_wait(t_shell_data *shell_data, int *pid, int amount)
{
	bool	is_interrupted;
	int		last_status;

	last_status = 0;
	is_interrupted = false;
	signal(SIGINT, SIG_IGN);
	ft_wait_for_all_children(pid, amount, &last_status, &is_interrupted);
	if (is_interrupted)
		ft_putstr_fd("\n", STDERR_FILENO);
	waitpid(pid[amount], &last_status, 0);
	if (WIFEXITED(last_status))
		shell_data->state.error_num = WEXITSTATUS(last_status);
	else if (WIFSIGNALED(last_status))
		shell_data->state.error_num = 128 + WTERMSIG(last_status);
	else
		shell_data->state.error_num = EXIT_FAILURE;
	signal(SIGINT, ft_sigint_handler);
	return (EXIT_SUCCESS);
}
