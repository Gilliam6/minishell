#include "../includes/minishell.h"

void	parser(t_mini *shell)
{
//	char *str;

//	splitted = 0;
	if (quot_checker(shell->input_line, MAX_INT))
		return ;
	space_del(shell);
	printf("%s\n", shell->processed_line);

	//	splitted = ft_custom_split(shell->input_line, ' ', &shell->garbage);

}