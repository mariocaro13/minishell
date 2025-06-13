#include "minishell.h"

static bool	ft_is_str_digit(char *str)
{
	int	index;

	index = 0;
	while (str[index])
	{
		if (!ft_isdigit(str[index]))
			return (false);
		index++;
	}
	return (true);
}

static void	ft_determine_exit_code(char **str)
{
	int	exit_code;

	if (!str[1])
		exit_code = 0;
	else if (ft_is_str_digit(str[1]))
		exit_code = ft_atoi(str[1]);
	else
	{
		ft_putstr_fd(COLOR_RED_BOLD MSG_DEFAULT_PROMPT COLOR_RESET "exit: ",
			STDERR_FILENO);
		ft_putstr_fd(str[1], STDERR_FILENO);
		ft_putstr_fd(": numeric argument required.\n", STDERR_FILENO);
		exit_code = 255;
	}
	ft_free_array(str);
	exit(exit_code);
}

int	ft_exit(t_shell_data *shell_data, t_command_list *command_list)
{
	char	**aux_str;

	ft_putendl_fd(COLOR_YELLOW MSG_DEFAULT_PROMPT COLOR_RESET
		MSG_EXIT, STDOUT_FILENO);
	if (command_list->str[1] && command_list->str[2])
	{
		ft_putstr_fd(COLOR_RED_BOLD MSG_DEFAULT_PROMPT COLOR_RESET
			"exit: too many arguments.\n", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	aux_str = ft_duplicate_string_array(command_list->str);
	ft_determine_exit_code(aux_str);
	ft_free_shell_data(shell_data);
	return (EXIT_SUCCESS);
}
