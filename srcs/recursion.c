#include "../includes/minishell.h"

void	switch_echoctl(char on)
{
	struct termios	ts;

	tcgetattr(STDIN_FILENO, &ts);
	if (on)
		ts.c_lflag |= ECHOCTL;
	else
		ts.c_lflag &= ~ECHOCTL;
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &ts);
}

void	exit_err(char *str)
{
	switch_echoctl(1);
	write(STDERR_FILENO, str, ft_strlen(str));
	exit(EXIT_FAILURE);
}

char	*get_environment_name(char *str)
{
	char	*result;
	int		length;

	length = ft_strlen(str);
	result = malloc(sizeof(char) * (length + 1));
	if (!result)
		exit_err(MLC_ERR);
	result[length] = 0;
	ft_memcpy(result, str, length);
	return (result);
}

void	set_environment(t_mini *shell_data,
			char *name_env, char *value_env, char flag)
{
	t_list			*element;
	t_env			*element_content;

	element = list_element_finder(shell_data->env, name_env);
	if (element)
	{
		element_content = (t_env *)element->content;
		if (element_content->value)
			free(element_content->value);
		element_content->value = value_env;
		if (flag > element_content->flag)
			element_content->flag = flag;
		free(name_env);
	}
	else
	{
		element_content = malloc(sizeof(t_env));
		if (!element_content)
			exit_err(MLC_ERR);
		element_content->name = name_env;
		element_content->value = value_env;
		element_content->flag = flag;
		ft_lsstadd_back(&(shell_data->env), ft_lsstnew(element_content));
	}
}

void	recursion(t_mini *shell)
{
	char	*shell_lvl_value;

	shell_lvl_value = get_environment_by_name(shell, "SHLVL");
	set_environment(shell, get_environment_name("SHLVL"),
		ft_itoa(ft_atoi(shell_lvl_value) + 1), 1);
	printf("%s\n", shell_lvl_value);
}
