#include "../includes/minishell.h"

int calculate_strmem(char *str)
{
	int mem_size;
	int index;

	mem_size = 0;
	index = 0;
	while (str && str[index])
	{
		if (str[index] != ' ')
			mem_size++;
		if (str[index] == ' ' && str[index + 1] == '-')
			mem_size++;
		if (str[index] == ' ' && quotes(str, index))
			mem_size++;
		index++;
	}
	return (mem_size);
}

char *refactor_str(char *str, int mem_size)
{
	char	*final;
	int		index;

	final = (char *)malloc(sizeof(char) * mem_size + 1);
	if (!final)
		return (0);
	index = 0;
	mem_size = 0;
	while (str && str[index])
	{
		if (str[index] != ' ')
			final[mem_size++] = str[index];
		if (str[index] == ' ' && str[index + 1] == '-')
			final[mem_size++] = str[index];
		if (str[index] == ' ' && quotes(str, index))
			final[mem_size++] = str[index];
		index++;
	}
	final[index] = 0;
	return (final);
}

char 	*space_del(char *str)
{
	int	mem_size;
	char *un_spaced;

	mem_size = calculate_strmem(str);
	un_spaced = refactor_str(str, mem_size);
	if (!un_spaced)
		return (0);
	return (un_spaced);
}