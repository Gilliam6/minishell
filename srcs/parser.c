#include "../includes/minishell.h"

void	parser(t_mini *shell)
{
//	char *str;
	if (quot_checker(shell->input_line, MAX_INT))
		return ;
	space_del(shell);
	processing_pipes(shell);

}