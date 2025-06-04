#include "minishell.h"

int	ft_rl_event_hook(void)
{
	return (EXIT_SUCCESS);
}

void	ft_sigint_handler(int signum)
{
	(void)signum;
	if (!g_shell_state.is_in_heredoc)
		ft_putstr_fd("\n", STDERR_FILENO);
	if (g_shell_state.is_in_cmd)
	{
		g_shell_state.should_stop_heredoc = true;
		rl_done = true;
	}
	else
		rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

void	ft_sigquit_handler(int signum)
{
	ft_putstr_fd("Quit: ", STDERR_FILENO);
	ft_putnbr_fd(signum, STDERR_FILENO);
	ft_putchar_fd('\n', STDERR_FILENO);
}
