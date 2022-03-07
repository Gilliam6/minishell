#include "../includes/minishell.h"

int	quotes(char *line, int index)
{
	int				i;
	unsigned char	quot;

	i = 0;
	quot = 0;
	while (line[i] && i < index)
	{
		if (i > 0 && line[i - 1] == '\\')
			;
		else if (!quot && line[i] == '\"')
			quot = 2;
		else if (!quot && line[i] == '\'')
			quot = 1;
		else if ((quot == 2 && line[i] == '\"') || (quot == 1 && line[i]
				== '\''))
			quot = 0;
		i++;
	}
	return (quot);
}

int	quot_checker(char *line, int i)
{
	if (quotes(line, i))
		return (ft_strerror(QUOT_ERR, 1));
	return (0);
}
