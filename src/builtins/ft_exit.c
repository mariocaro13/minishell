#include "minishell.h"

void	free_tools(t_shell_data *shell_data)
{
	ft_free_array(shell_data->paths);
	ft_free_array(shell_data->envp);
	free(shell_data->args);
	ft_command_list_clear(&shell_data->commands_list);
	free(shell_data->pwd);
	free(shell_data->old_pwd);
	if (shell_data->pipes)
		free(shell_data->pid);
}

int	is_str_digit(char *str)
{
	int	index;

	index = 0;
	while (str[index])
	{
		if (!ft_isdigit(str[index]))
			return (0);
		index++;
	}
	return (1);
}

void	determine_exit_code(char **str)
{
	int	exit_code;

	if (!str[1])
		exit_code = 0;
	else if (is_str_digit(str[1]))
		exit_code = ft_atoi(str[1]);
	else
	{
		ft_putstr_fd(COLOR_RED_BOLD MSG_PROMPT COLOR_RESET "exit: ", STDERR_FILENO);
		ft_putstr_fd(str[1], STDERR_FILENO);
		ft_putstr_fd(": numeric argument required\n", STDERR_FILENO);
		exit_code = 255;
	}
	ft_free_array(str);
	exit(exit_code);
}

int	ft_exit(t_shell_data *shell_data, t_commands_list *simple_cmd)
{
	char	**str;

	ft_putendl_fd("exit", STDERR_FILENO);
	if (simple_cmd->str[1] && simple_cmd->str[2])
	{
		ft_putstr_fd(COLOR_RED_BOLD MSG_PROMPT COLOR_RESET "exit: too many arguments\n", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	str = ft_duplicate_string_array(simple_cmd->str);
	free_tools(shell_data);
	determine_exit_code(str);
	return (EXIT_SUCCESS);
}
