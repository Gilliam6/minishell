#include "../includes/minishell.h"

char	**parser(t_mini *shell)
{
	if (quot_checker(shell->input_line, MAX_INT))
		return (0);
	space_del(shell);
//	processing_dollars(shell); // to do раскрыть доллар
	return (processing_pipes(shell));
//	processing_tokens(shell); // to do разбить на отдельные операторы и команды
//	print_tokens(shell->tokens);

}