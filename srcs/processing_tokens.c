#include "../includes/minishell.h"

void	processing_tokens(t_mini *shell)
{
	char	**split;
	int 	i;

	split = ft_custom_split(shell->tokens->name, &shell->garbage);
	i = 0;
	while (split[i])
	{

		i++;
	}
}
