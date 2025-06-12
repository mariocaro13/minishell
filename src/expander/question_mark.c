#include "minishell.h"

int	ft_process_question_mark(t_shell_data *shell_data, char **result)
{
	if (*result)
		free(*result);
	*result = ft_itoa(shell_data->state.error_num);
	return (2);
}
