#include "../includes/minishell.h"

char	**processing_pipes(t_mini *shell)
{
	char	**splitted;

	splitted = 0;
	if (shell->processed_line)
		splitted = ft_custom_split(shell->processed_line, '|', &shell->garbage);
	return (splitted);
}