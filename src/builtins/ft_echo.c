#include "minishell.h"

void	print_lines(int index, char **str, int out)
{
	while (str[index])
	{
		ft_putstr_fd(str[index++], out);
		if (str[index])
			ft_putchar_fd(' ', out);
	}
}

int	mini_echo(t_shell_data *shell_data, t_commands_list *simple_cmd)
{
	int		index;
	int		j;
	bool	n_option;

	index = 1;
	n_option = false;
	(void) shell_data;
	while (simple_cmd->str[index] && simple_cmd->str[index][0] == '-'
		&& simple_cmd->str[index][1] == 'n')
	{
		j = 1;
		while (simple_cmd->str[index][j] == 'n')
			j++;
		if (simple_cmd->str[index][j] == '\0')
			n_option = true;
		else
			break ;
		index++;
	}
	print_lines(index, simple_cmd->str, STDOUT_FILENO);
	if (n_option == false)
		ft_putchar_fd('\n', STDOUT_FILENO);
	return (EXIT_SUCCESS);
}
