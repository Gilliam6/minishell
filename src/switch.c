#include "minishell.h"

void	exit_err(char *str)
{
	switch_echoctl(1);
	write(STDERR_FILENO, str, ft_strlen(str));
	exit(EXIT_FAILURE);
}

void	switch_echoctl(char on)
{
	struct termios	ts;

	tcgetattr(STDIN_FILENO, &ts);
	if (on)
		ts.c_lflag |= ECHOCTL;
	else
		ts.c_lflag &= ~ECHOCTL;
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &ts);
}