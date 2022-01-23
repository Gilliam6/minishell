#include "../includes/minishell.h"

int ft_strerror(char *str)
{
	ft_putstr_fd(str, 1);
	return (1);
}

int main(int argc, char **argv, char **env)
{
	t_mini shell;

	(void)argc;
	(void)argv;
	shell.exit = 0;
	shell.envi = init_environment(env, &shell.garbage);
	if (!shell.envi)
		return (ft_strerror(MLC_ERR));
//	printf("%d garbage size\n", ft_custom_lstsize(shell
//	.garbage));
	while(!shell.exit)
	{
		shell.input_line = readline("🍌");
		tokenizator(&shell);
//		printf("%s\n", shell.input_line);
//		readline("➡️");
		shell.exit = ft_strcmp(shell.input_line, "exit");
		add_history(shell.input_line);
	}
	ft_custom_lstclear(&shell.garbage, free);
	printf("%s\n", "🖕");
	return (0);
}