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

	ft_memset(&shell, 0, sizeof(t_mini));
	shell.envi = init_environment(environ, &shell.garbage);
	if (!shell.envi)
		return (ft_strerror(MLC_ERR, 1));
//	printf("%d garbage size\n", ft_custom_lstsize(shell
//	.garbage));
	while(!shell.exit)
	{
		set_input_signals();
		signal(SIGINT, &signal_handler2);
		shell.tokens = 0;
		//shell.input_line = 0;
		shell.input_line = readline("minishell$");
		// if (ft_strcmp(shell.input_line, "exit"))
		// 	break;
		if(!shell.input_line)
		{
			ft_putstr_fd("exit\n", 1);
			free(shell.input_line);
			return(1);
		}
		tokenizator(&shell);
		print_tokens(shell.tokens);
		add_history(shell.input_line);
	}
	ft_custom_lstclear(&shell.garbage, free);
	printf("%s\n", "🖕");
	return (0);
}
