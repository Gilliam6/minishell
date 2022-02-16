#include "../includes/minishell.h"

char	**parser(t_mini *shell)
{
	char	**split;
	if (quot_checker(shell->input_line, MAX_INT))
		return (0);
	space_del(shell);
	processing_dollars(shell);
	split = processing_pipes(shell);
	return (split);
//	processing_tokens(shell); // to do разбить на отдельные операторы и команды
}