#include "../includes/minishell.h"

void	ft_echo(char **data_command)
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
	exit(0);
}

void	ft_cd(char **data_command) // todo Обработку ~ / хотелось бы сделать в парсере
{
	char	buf[PATH_MAX];
	char	**cd_path;
	int		i;
	int		len_path;
	int		j;

	if (getcwd(buf, PATH_MAX) < 0)
	{
		perror("getcwd");
		exit(1);
	}
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
	if (chdir(buf) < 0)
		perror("cd");
	exit(0);
}

void ft_pwd()
{
	char buf[PATH_MAX];

	if (getcwd(buf, PATH_MAX) < 0)
		perror("getcwd");
	else
		printf("%s\n", buf);
	exit(0);
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
	exit(0);
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
	exit(0);
}

void ft_env(t_env *env)
{
	while (env)
	{
		printf("%s\n",env->content);
		env = env->next;
	}
	exit(0);
}

int len_list_env(t_env *env)
{
	int i;

	i = 0;
	while (env)
	{
		env = env->next;
		i++;
	}
	return i;
}

char **env_convert(t_env *env, t_garbage **garbage)
{
	int len;
	int i;
	char **result_env;

	len = len_list_env(env);
	result_env = (char **)save_malloc(sizeof(char *) * (len + 1), garbage);
	result_env[len] = 0;
	i = 0;
	while (env)
	{
		result_env[i] = env->content;
		env = env->next;
		i++;
	}
	return result_env;
}

int	file_descriptor_handler(int in, int out)
{
	if (in != 0)
	{
		dup2(in, 0);
		close(in);
	}
	if (out != 1)
	{
		dup2(out, 1);
		close(out);
	}
	return (0);
}

char *find_bin_path(char *command, t_env *env, t_garbage **garbage)
{
	char *bin_path;
	char **split_path;
	int i;
	int j;
	struct stat f;

	bin_path = save_malloc(1024, garbage);
	while (env)
	{
		if (!ft_strncmp(env->content, PATH, ft_strlen(PATH)))
		{
			split_path = ft_mega_custom_split(&env->content[ft_strlen(PATH) + 1], ':', garbage);
			while (*split_path)
			{
				i = 0;
				while (**split_path)
					bin_path[i++] = *(*split_path)++;
				bin_path[i++] = '/';
				j = 0;
				while (command[j])
					bin_path[i++] = command[j++];
				bin_path[i] = 0;
				if (lstat(bin_path, &f) == 0)
					return bin_path;
				split_path++;
			}
		}
		env = env->next;
	}
	return 0;
}

void ft_execve(char **command, t_env *env, t_garbage **garbage) // todo здесь нужен env в формате **char, листы здес не нужны
{
	char **env_array;
	char *bin_path;
//	char command_path[PATH_MAX];
//	int i;
//
//	i = 0;
//	while (*bin_path)
//		command_path[i++] = *bin_path++;
//	while (**command)
//		command_path[i++] = *(*command)++;
//	command_path[i] = 0;

	env_array = env_convert(env, garbage);
	bin_path = find_bin_path(command[0], env, garbage);
	if (!bin_path)
		exit(1);
	if (execve(bin_path, command, env_array) < 0)
	{
		perror("execve");
		exit(1);
	}
	exit(0);
}


void    ft_do_cmd(char **command, t_env **env, t_garbage **garbage)
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
		ft_execve(command, *env, garbage);
}

void	ft_exec_command(t_mini *shell)
{
	t_tok *token;
	int fd[2];
	pid_t pid;
	int status;

	token = shell->tokens;
	while(token)
	{
		if (token->next)
		{
			if (pipe(fd) < 0)
			{
				perror("pipe");
				return;
			}
			token->std[1] = fd[1];
			token->next->std[0] = fd[0];
		}
		pid = fork();
		if (pid == -1)
			perror("fork");
		else if (pid == 0)
		{
			file_descriptor_handler(token->std[0], token->std[1]);
//			printf("command = %s std (in, out) = %d %d\n", token->name[0], token->std[0], token->std[1]);
			ft_do_cmd(token->name, &shell->envi, &shell->garbage);
		}
		else
			waitpid(pid, &status, WUNTRACED);
		token = token->next;
	}

}
