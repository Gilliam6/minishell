#include "minishell.h"

char	*get_env_name(char *str)
{
	char	*res;
	int		len;

	len = ft_strlen(str);
	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		exit_err(MEM_ERR);
	res[len] = 0;
	ft_memcpy(res, str, len);
	return (res);
}

void	ft_env_addback(t_env **env, t_env *new)
{
	t_env	*curr;

	curr = *env;
	if (curr == NULL)
		*env = new;
	else
	{
		while (curr->next)
			curr = curr->next;
		curr->next = new;
	}
}