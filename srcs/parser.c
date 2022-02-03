#include "../includes/minishell.h"

void	parser(t_mini *shell)
{
	char	**piped;
	int 	i = 0;
	if (quot_checker(shell->input_line, MAX_INT))
		return ;
	space_del(shell);
	processing_dollars(shell); // to do раскрыть доллар
	piped = processing_pipes(shell);
//	processing_tokens(shell); // to do разбить на отдельные операторы и команды
//	print_tokens(shell->tokens);

}