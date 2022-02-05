#include "minishell.h"

char	*get_var_value(char *var_name, t_data *data)
{
	t_env	*env;

	env = data->env_parsed;
	while (env)
	{
		if (ft_strcmp(var_name, env->var_name) == 0)
			break ;
		env = env->next;
	}
	if (env)
		return (env->value);
	return (NULL);
}

void	parse_path(t_data *data)
{
	char	*path;
	int		count;
	int		i;
	int		j;

	i = 0;
	j = 0;
	path = NULL;
	if (data && data->env_parsed)
	{
		path = get_var_value("PATH", data);
		if (path)
		{
			count = get_path_count(path);
			data->path = (char **)malloc((count + 1) * sizeof(char *));
			if (!data->path)
				exit (1);
			data->path[count] = NULL;
			while (path[i] != '\0')
			{
				data->path[j++] = get_path(&path[i], &i);
			}
		}
	}
}

char	*get_str_by_el(t_env *f)
{
	char	*res;
	int		l;

	if (f)
	{
		l = ft_strlen(f->value);
		res = malloc(sizeof(char) * (l + 1));
		if (!res)
			exit_err(MEM_ERR);
		res[l] = 0;
		ft_memcpy(res, f->value, l);
	}
	else
	{
		res = malloc(sizeof(char));
		if (!res)
			exit_err(MEM_ERR);
		res[0] = 0;
	}
	return (res);
}
