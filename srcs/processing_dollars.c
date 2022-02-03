#include "../includes/minishell.h"

int	localize_dollar(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '$')
		i++;
	if (tokens->name[i] == '$')
		return (i);
	return (-1);
}

char	*find_arg(t_tok *tokens, int index, t_garbage **garbage)
{
	char *str;
	int	i;

	i = 0;
	while (tokens->name[index] && tokens->name[index] != ' '  &&
	tokens->name[index] != '\'' && tokens->name[index] != '\"')
	{
		index++;
		i++;
	}
	str = (char *) save_malloc(i);

}

void	processing_dollars(t_mini *shell)
{
	int		index;
	char	*arg;

	index = 1;
	while (index)
	{
		index = localize_dollar(shell->processed_line);
		if (index >= 0)
			shell->processed_line = prolongate_or_not(shell->processed_line, index,
										  &shell->garbage);
	}
	if (!index)
		return;
}