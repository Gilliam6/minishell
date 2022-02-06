#include "minishell.h"

char	*get_environemt_value(char *name, t_data *data)
{
	t_enviroment	*enviroment;

	enviroment = data->parsed_enviroment;
	while (enviroment)
	{
		if (ft_strcmp(name, enviroment->name) == 0)
			break ;
		enviroment = enviroment->next;
	}
	if (enviroment)
		return (enviroment->value);
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
	if (data && data->parsed_enviroment)
	{
		path = get_environemt_value("PATH", data);
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
