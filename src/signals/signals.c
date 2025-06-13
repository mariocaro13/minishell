#include "minishell.h"

int	ft_rl_event_hook(void)
{
	return (EXIT_SUCCESS);
}

void	ft_sigint_handler(int signum)
{
	(void)signum;
	if (g_is_in_heredoc)
		rl_done = 1;
	else
	{
		ft_putstr_fd("\n", STDERR_FILENO);
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
	}
}

void	ft_sigquit_handler(int signum)
{
	(void)signum;
	write(STDERR_FILENO, "\r", 1);
	ft_putendl_fd(COLOR_YELLOW MSG_DEFAULT_PROMPT COLOR_RESET
		"^\\Quit (core dumped)", STDERR_FILENO);
}
