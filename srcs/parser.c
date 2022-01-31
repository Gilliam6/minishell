#include "../includes/minishell.h"

void	parser(t_mini *shell)
{
	if (quot_checker(shell->input_line, MAX_INT))
		return ;
	space_del(shell);
	processing_pipes(shell);
	delete_quotes(shell); // to do раскрыть ковычки
	processing_tokens(shell); // to do разбить на отдельные операторы и команды
//	print_tokens(shell->tokens);

}