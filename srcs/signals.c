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
		write(1, "\n", 1);
		rl_replace_line("", 0);
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


// void	handler3(int st)
// {
// 	if (st == SIGQUIT)
// 		;
// 	else if (st == SIGINT)
// 		;
// }
