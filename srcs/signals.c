#include "../includes/minishell.h"

// void rl_replace_line (const char *text, int clear_undo)
// {
// 	(void)text;
// 	(void)clear_undo;
// 	return ;
// }

void	set_input_signals(void)
{
	signal(SIGINT, signal_handler);
	signal(SIGQUIT, SIG_IGN);
	printf("OK-0\n");
}

void	signal_handler(int signo)
{
	if (signo == SIGQUIT)
	{
		printf("OK-1\n");
		rl_on_new_line();
		rl_redisplay();
	}
	else if (signo == SIGINT)
	{
		printf("OK-2\n");
		rl_on_new_line();
		write(1, "\n", 1);
		rl_replace_line("", 1);
		rl_on_new_line();
		rl_redisplay();
		exit(1);
	}
}

void	signal_handler2(int signo)
{
	if (signo == SIGINT)
	{
		printf("OK-3\n");
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
