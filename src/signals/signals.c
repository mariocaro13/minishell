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
	ft_putstr_fd("Quit: ", STDERR_FILENO);
	ft_putnbr_fd(signum, STDERR_FILENO);
	ft_putchar_fd('\n', STDERR_FILENO);
}
