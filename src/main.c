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
	char	*shlvl_val;

	g_data.last_exit_code = 0;
	g_data.main_proc_mark = 1;
	ft_copy_params(data, argc, argv, envp);
	ft_env_parse(data);
	parse_path(data);
	shlvl_val = get_env_by_name(data, "SHLVL");
	set_env_by_name(data, get_env_name("SHLVL"),
		ft_itoa(ft_atoi(shlvl_val) + 1), 1);
	printf("%s\n", shlvl_val);
	g_data.data = data;
}

int	main(int argc, char **argv, char **envp)
{
	char				*input;
	t_data				data;

	ft_init(&data, argc, argv, envp);
	input = NULL;
	// while (data.env_parsed->var_name)
	// {
	// 	printf("%s\n", data.env_parsed->var_name);
	// 	data.env_parsed = data.env_parsed->next;
	// }
	printf("%s\n", data.path[1]);
	printf("%s\n", data.path[2]);
	printf("%s\n", data.path[3]);
	printf("%s\n", data.path[4]);
	printf("%s\n", data.path[5]);
	return(0);
}
