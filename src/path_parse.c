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

void	parse_enviroment(t_data *data)
{
	int				i;
	int				j;
	int				k;
	t_enviroment	*enviroment;

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
			enviroment = enviroment_addnew(j, k);
			ft_strlcpy(enviroment->name, *(data->envp + i), j + 1);
			ft_strlcpy(enviroment->value, *(data->envp + i) + j + 1, k + 1);
			enviroment_addback(&data->parsed_enviroment, enviroment);
			enviroment = NULL;
			i++;
		}
	}
}

void	write_parametrs(t_data *data, int argc, char **argv, char **envp)
{
	data->argc = argc;
	data->argv = argv;
	data->envp = envp;
	data->env_tosend = NULL;
	data->parsed_enviroment = NULL;
	data->path = NULL;
	data->last_exit_code = 0;
}

void	inition(t_data *data, int argc, char **argv, char **envp)
{
	char	*shell_lvl_value;

	g_data.exit_code = 0;
	g_data.process_mark = 1;
	write_parametrs(data, argc, argv, envp);
	parse_enviroment(data);
	parse_path(data);
	shell_lvl_value = get_enviroment_by_name(data, "SHLVL");
	set_enviroment(data, get_enviroment_name("SHLVL"),
		ft_itoa(ft_atoi(shell_lvl_value) + 1), 1);
	printf("%s\n", shell_lvl_value);
	g_data.data = data;
}