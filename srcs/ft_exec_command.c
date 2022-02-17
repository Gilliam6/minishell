#include "../includes/minishell.h"

void    ft_echo(char **data_command)
{
	char	flag_n;
	char	flag_space;

	flag_n = 0;
	flag_space = 0;
	while (*data_command)
	{
		if (ft_strcmp(*data_command, "-n"))
			flag_n = 1;
		else
		{
			if (flag_space)
				printf(" ");
			printf("%s", *data_command);
			flag_space = 1;
		}
		data_command++;
	}
	if (!flag_n)
		printf("\n");
}

void	ft_cd(char **data_command) // todo Обработку ~ / хотелось бы сделать в парсере
{
	char buf[PATH_MAX];
	char **cd_path;
	int i;
	int len_path;
	int j;

	getcwd(buf, PATH_MAX); // todo обработка если вернет -1
	cd_path = ft_split(*data_command, '/'); // todo этот делить только для linux/MACOS
	len_path = ft_strlen(buf) - 1;
	printf("path = %s len_path = %d\n", buf, len_path);
	for(int c = 0; cd_path[c] != 0; c++)
		printf("[%d]cd_path = %s\n", c, cd_path[c]);
	i = -1;
	while (cd_path[++i])
	{
		if (ft_strcmp(".", cd_path[i]))
			continue;
		else if (ft_strcmp("..", cd_path[i]))
		{
			while (buf[len_path] != '/')
				buf[len_path--] = 0;
			if (len_path) // чтобы не удалить последний слеш
				buf[len_path--] = 0;
		}
		else
		{
			buf[++len_path] = '/';
			j = 0;
			while (cd_path[i][j]) // todo это str_join но который в либфт не подходит, потому что там выделяется новая память
				buf[++len_path] = cd_path[i][j++];
			buf[len_path + 1] = 0; // чтобы не было мусора в конце строки, можно избавится если после объяления buf заполнить полностью нулями
		}
	}
	free(cd_path);
	printf("buf_final = %s\n", buf);
	chdir(buf); // todo обработка если вернет -1
}

void ft_pwd()
{
	char buf[PATH_MAX];

	getcwd(buf, PATH_MAX); // todo обработка если вернет -1
	printf("%s\n", buf);
}

void ft_export(char **data_command, t_env **env, t_garbage **garbage) // todo нужно ли делать, что добавляется несколько переменных? типа: export first=1 second=2 ...
{
	t_env *begin;

	begin = *env;
	if (!begin)
	{
		*env = new_node(*data_command, garbage);
		return;
	}
	while (begin->next)
		begin = begin->next;
	begin->next = new_node(*data_command, garbage);
}

void ft_unset(char **data_command, t_env **env) // todo нужно ли делать, что удаляется несколько переменных? типа: unset first second ...
{
	t_env *begin;
	t_env *prev;

	begin = *env;
	prev = 0;
	while (begin)
	{
		if (ft_strcmp(begin->content, *data_command))
		{
			if (prev)
			{
				prev->next = begin->next;
				free(begin->content);
				free(begin);  // todo нужно ли мне free или это сделать garbage collector
			}
			else
				*env = (*env)->next;
			break; // Так как 2 переменных с одинаковым названием не должно находится в env
		}
		prev = begin;
		begin = begin->next;
	}
}

void ft_env(t_env *env)
{
	while (env)
	{
		printf("%s\n",env->content);
		env = env->next;
	}
}

void ft_execve(char **command, char *bin_path) // todo здесь нужен env в формате **char, листы здес не нужны
{
	char *env[] = { "HOME=/Users/ebalsami", "LOGNAME=ebalsami", (char *)0 };
	char command_path[PATH_MAX];
	int i;
	int status;
	pid_t pid;

	i = 0;
	while (*bin_path)
		command_path[i++] = *bin_path++;
	while (**command)
		command_path[i++] = *(*command)++;
	command_path[i] = 0;
	pid = fork();
	if (pid == -1)
		printf("ERROR"); //todo сделать очистку
	else if (pid == 0)
		execve(command_path, command, env);
	else
		waitpid(pid, &status, WUNTRACED);
}


void    ft_check_cmd(char **command, t_env **env, t_garbage **garbage)
{

	if (ft_strcmp(command[0], STR_ECHO))
        ft_echo(++command);
	else if (ft_strcmp(command[0], STR_CD))
		ft_cd(++command);
	else if (ft_strcmp(command[0], STR_PWD))
		ft_pwd();
	else if (ft_strcmp(command[0], STR_EXPORT))
		ft_export(++command, env, garbage);
	else if (ft_strcmp(command[0], STR_UNSET))
		ft_unset(++command, env);
	else if (ft_strcmp(command[0], STR_ENV))
		ft_env(*env);
	else
	{
		ft_execve(command, BIN_PATH);
	}
}

void	ft_exec_command(t_mini *shell)
{
    ft_check_cmd(shell->tokens->name, &shell->envi, &shell->garbage);
}
