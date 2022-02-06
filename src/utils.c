#include "minishell.h"

char	*get_enviroment_name(char *str)
{
	char	*result;
	int		length;

	length = ft_strlen(str);
	result = malloc(sizeof(char) * (length + 1));
	if (!result)
		exit_err(MEM_ERR);
	result[length] = 0;
	ft_memcpy(result, str, length);
	return (result);
}

void	enviroment_addback(t_enviroment **env, t_enviroment *new)
{
	t_enviroment	*current;

	current = *env;
	if (current == NULL)
		*env = new;
	else
	{
		while (current->next)
			current = current->next;
		current->next = new;
	}
}