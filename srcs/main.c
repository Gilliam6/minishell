#include "../includes/minishell.h"

int unexpected_exit(t_garbage **garbage, char *str, int ret)
{
	if (*garbage)
		ft_custom_lstclear(garbage, free);
	if (str)
		ft_putstr_fd(str, 1);
	exit(ret);
}
int ft_strerror(char *str, int ret)
{
	ft_putstr_fd(str, 1);
	return (ret);
}

int main(void)
{
	t_mini shell;
	extern char **environ;

	shell.exit = 0;
	shell.garbage = 0;
	shell.envi = 0;
	shell.tokens = 0;
	shell.envi = init_environment(environ, &shell.garbage);
	if (!shell.envi)
		return (ft_strerror(MLC_ERR, 1));
//	printf("%d garbage size\n", ft_custom_lstsize(shell
//	.garbage));
	while(!shell.exit)
	{
		shell.input_line = readline("🍌");
		if (ft_strcmp(shell.input_line, "exit"))
			break;
		tokenizator(&shell);
//		printf("%s\n", shell.input_line);
//		readline("➡️");
//		shell.exit = ft_strcmp(shell.input_line, "exit");
		add_history(shell.input_line);
	}
	ft_custom_lstclear(&shell.garbage, free);
	printf("%s\n", "🖕");
	return (0);
}