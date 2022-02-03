#include "../includes/minishell.h"

int	localize_dollar(t_tok *tokens)
{
	int	i;

	i = 0;
	while (tokens->name[i] && tokens->name[i] != '$')
		i++;
	if (tokens->name[i] == '$')
		return (i);
	return (0);
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
		index = localize_dollar(shell->tokens);
		arg = find_arg(shell->tokens, index, &shell->garbage);
	}
	if (!index)
		return;
}