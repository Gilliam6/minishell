#include "../includes/minishell.h"

void	tokenizator(t_mini *shell)
{
	char **splitted;

	splitted = parser(shell);
	if (!splitted)
		return;
}