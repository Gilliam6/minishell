#include "../includes/minishell.h"

//int	skip_till_eqv(char *str)
//{
//	int	i;
//
//	i = 0;
//	while (str[i] && str[i] != '=')
//		i++;
//	return (i + 1);
//}

t_env 	*compare_args(char *str, int len, t_mini *shell)
{
	t_env *env;

	env = shell->envi;
	while (env)
	{
		if (!ft_strncmp(str + 1, env->content, len - 1))
			break;
		env = env->next;
	}
	return (env);
}

int count_arg_size(char *str)
{
	int len;
	int	i;

	i = 0;
	len = 0;
	while (str[i] != '=')
		i++;
	while (str[i] && str[i] != ' ')
	{
		len++;
		i++;
	}
	return (len);
}

int	arg_size(t_env *env)
{
	int len;

	len = 0;
	if (env)
		len = count_arg_size(env->content);
	return (len);
}

int	calculate_new_line(char *str, int i, t_mini *shell)
{
	int		len;
	t_env	*env;

	len = 0;
	while (str[i + len] && (str[i + len] != ' ' && str[i + len] != '\"'))
		len++;
//	printf("")
	env = compare_args(str + i, len, shell);
	len = arg_size(env) - len;
	return (len);
}

int	copy_arg(t_mini *shell, char *new_line, int i, int *ind)
{
	int		len;
	int		index;
	t_env	*env;

	len = 0;
	while (shell->processed_line[i + len] && (shell->processed_line[i + len]
	!= ' ' && shell->processed_line[i + len] != '\"'))
		len++;
	index = len;
	env = compare_args(shell->processed_line + i, len, shell);
	if (!env)
		return (index);
	while (env->content[++len])
		new_line[(*ind)++] = env->content[len];
	return (index);
}

char	*construct_new_line(int mem_size, t_mini *shell)
{
	char	*new_line;
	int		i;
	int		index;

	new_line = (char *) save_malloc(mem_size, &shell->garbage);
	i = 0;
	index = 0;
	while (shell->processed_line[i])
	{
		if (shell->processed_line[i] == '$' &&
		quotes(shell->processed_line, i) != 1)
			i += copy_arg(shell, new_line, i, &index);
		else
		{
			new_line[index] = shell->processed_line[i];
			i++;
			index++;
		}
	}
	new_line[index] = 0;
	return (new_line);
}

void	processing_dollars(t_mini *shell)
{
	int		index;
	int 	mem_size;
	char	*new_line;

	index = 0;
	mem_size = 0;
	while (shell->processed_line && shell->processed_line[index])
	{
		if (shell->processed_line[index] == '$' && quotes(shell->processed_line, index) != 1)
			mem_size += calculate_new_line(shell->processed_line, index, shell);
		index++;
	}
//	printf("MEMSIZE: %d\n", mem_size);
	mem_size = ft_strlen(shell->processed_line) + mem_size + 1;
	new_line = construct_new_line(mem_size, shell);
//	printf("CHECK NEW LINE: %s\nCHECK OLD LINE: %s\n", new_line,
//		   shell->processed_line);
	shell->processed_line = new_line;
}
