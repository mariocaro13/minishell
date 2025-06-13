#include "minishell.h"

static bool	ft_is_n_option(const char *str)
{
	int	index;

	if (!str || str[0] != '-')
		return (false);
	index = 1;
	while (str[index])
	{
		if (str[index] != 'n')
			return (false);
		index++;
	}
	return (true);
}

void	ft_print_lines(int index, char **str, int out)
{
	while (str[index])
	{
		ft_putstr_fd(str[index++], out);
		if (str[index])
			ft_putchar_fd(' ', out);
	}
}

int	ft_echo(t_shell_data *shell_data, t_command_list *command_list)
{
	int		index;
	bool	is_n_option;

	(void) shell_data;
	index = 1;
	is_n_option = false;
	while (command_list->str[index] && ft_is_n_option(command_list->str[index]))
	{
		is_n_option = true;
		index++;
	}
	ft_print_lines(index, command_list->str, STDOUT_FILENO);
	if (is_n_option == false)
		ft_putchar_fd('\n', STDOUT_FILENO);
	return (EXIT_SUCCESS);
}
