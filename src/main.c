#include "minishell.h"

t_glob_data	g_data;

int	get_path_count(char *str)
{
	int	i;
	int	count;
	int	mark;

	count = 0;
	mark = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == ':')
			mark = 0;
		else if (mark == 0)
		{
			count++;
			mark = 1;
		}
		i++;
	}
	return (count);
}

char	*get_path(char *str, int *start)
{
	int		i;
	char	*path;

	i = 0;
	path = NULL;
	while (str[i] != '\0' && str[i] != ':')
		i++;
	if (i == 0)
		return (NULL);
	path = (char *)malloc((i + 2) * sizeof(char));
	if (!path)
		exit(1);
	ft_strlcpy(path, str, i + 1);
	*(path + i) = '/';
	*(path + i + 1) = 0;
	if (str[i] == ':')
		i++;
	*start += i;
	return (path);
}

void	ft_env_parse(t_data *data)
{
	int		i;
	int		j;
	int		k;
	t_env	*env;

	i = 0;
	if (data->envp)
	{
		while (data->envp[i])
		{
			j = 0;
			while (data->envp[i][j] != '=')
				j++;
			k = 0;
			while (data->envp[i][k + j + 1])
				k++;
			env = ft_env_addnew(j, k);
			ft_strlcpy(env->var_name, *(data->envp + i), j + 1);
			ft_strlcpy(env->value, *(data->envp + i) + j + 1, k + 1);
			ft_env_addback(&data->env_parsed, env);
			env = NULL;
			i++;
		}
	}
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

t_env	*ft_env_addnew(int var_name_len, int value_len)
{
	t_env	*new;

	new = (t_env *)malloc(sizeof(t_env));
	if (!new)
		exit(1);
	new->value = (char *)malloc((value_len + 1) * sizeof(char));
	new->var_name = (char *)malloc((var_name_len + 1) * sizeof(char));
	if (!new->value || !new->var_name)
		exit(1);
	new->next = NULL;
	return (new);
}

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

void	ft_copy_params(t_data *data, int argc, char **argv, char **envp)
{
	data->argc = argc;
	data->argv = argv;
	data->envp = envp;
	data->env_tosend = NULL;
	data->env_parsed = NULL;
	data->path = NULL;
	data->last_exit_code = 0;
}

void	ft_init(t_data *data, int argc, char **argv, char **envp)
{
	g_data.last_exit_code = 0;
	g_data.main_proc_mark = 1;
	ft_copy_params(data, argc, argv, envp);
	ft_env_parse(data);
	parse_path(data);
	g_data.data = data;
}

int	main(int argc, char **argv, char **envp)
{
	char				*input;

	t_data				data;

	ft_init(&data, argc, argv, envp);
	input = NULL;
	printf("%s\n", data.path[0]);
	printf("%s\n", data.path[1]);
	printf("%s\n", data.path[2]);
	printf("%s\n", data.path[3]);
	printf("%s\n", data.path[4]);
	printf("%s\n", data.path[5]);
	return(0);
}
