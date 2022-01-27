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

char *refactor_str(t_mini *shell, int mem_size)
{
	char	*final;
	int		index;

	final = (char *)save_malloc(sizeof(char) * mem_size + 1, &shell->garbage);
	index = 0;
	mem_size = 0;
	while (shell->input_line && shell->input_line[index])
	{
		if (shell->input_line[index] != ' ')
			final[mem_size++] = shell->input_line[index];
		if (shell->input_line[index] == ' ' && shell->input_line[index + 1]
		== '-')
			final[mem_size++] = shell->input_line[index];
		if (shell->input_line[index] == ' ' && quotes(shell->input_line, index))
			final[mem_size++] = shell->input_line[index];
		index++;
	}
	final[index] = 0;
	return (final);
}

void	space_del(t_mini *shell)
{
	int	mem_size;
//	char *un_spaced;

	mem_size = calculate_strmem(shell->input_line);
	shell->processed_line = refactor_str(shell, mem_size);

}