#include "../includes/minishell.h"

void	set_input_signals(void)//!
{
	signal(SIGINT, signal_handler);
	signal(SIGQUIT, SIG_IGN);
}

void	signal_handler(int signo)
{
	if (signo == SIGINT)
	{
		// ft_putstr_fd("\b\b\n", 1);
		// rl_on_new_line();
		// rl_replace_line("", 0);
		// rl_redisplay();
		rl_on_new_line();
		write(1, "\n", 1);
		rl_replace_line("", 1);
		rl_on_new_line();
		rl_redisplay();
	}
}

void	signal_handler2(int signo)
{
	if (signo == SIGINT)
	{
		ft_putendl_fd("", 1);
	}
}