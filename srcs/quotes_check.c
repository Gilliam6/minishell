#include "../includes/minishell.h"

int quotes(char *line, int index)
{
	int	i;
	unsigned char	quot;
	unsigned char	d_quot;

	i = 0;
	quot = 0;
	d_quot = 0;
	while (line[i] && i < index)
	{
		if (i > 0 && line[i - 1] == '\\')
			;
		else if (!d_quot && line[i] == '\"')
			d_quot = !d_quot;
		else if (!quot && line[i] == '\'')
			quot = !quot;
		else if (d_quot && line[i] == '\"')
			d_quot = !d_quot;
		else if (quot && line[i] == '\'')
			quot = !quot;
		i++;
	}
	return (quot || d_quot);
}

int quot_checker(char *line, int i)
{
	if (quotes(line, i))
		return (ft_strerror(QUOT_ERR, 1));
	return (0);
}