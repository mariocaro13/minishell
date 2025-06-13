#include "minishell.h"

bool	g_is_in_heredoc;

int	main(int argc, char **argv, char **envp)
{
	t_shell_data	shell_data;

	if (argc != 1 || argv[1])
	{
		printf(MSG_USAGE);
		exit(0);
	}
	if (ft_init_shell(&shell_data, envp) != EXIT_SUCCESS)
	{
		ft_putstr_fd(COLOR_RED MSG_DEFAULT_PROMPT COLOR_RESET MSG_ERR_INIT,
			STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	ft_load_history_from_file(HISTORY_FILE);
	printf(MSG_WELCOME);
	ft_shell_loop(&shell_data);
	rl_clear_history();
	return (EXIT_SUCCESS);
}
