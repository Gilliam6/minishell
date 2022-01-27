#include "../includes/minishell.h"

char **parser(t_mini *shell)
{
	char **splitted;
	char *str;

	splitted = 0;
	if (quot_checker(shell->input_line, MAX_INT))
		return (0);
	str = space_del(shell->input_line);
	if (!str)
		return (0);

	//	splitted = ft_custom_split(shell->input_line, ' ', &shell->garbage);



	return (splitted);
}