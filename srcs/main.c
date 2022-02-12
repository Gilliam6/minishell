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
	while(!shell.exit)
	{
		set_input_signals();
		shell.input_line = readline("minishell$");
		signal(SIGINT, &signal_handler);
		shell.tokens = 0;
		if(!shell.input_line)
		{
			printf("\033[11C");
			printf("\x1bM\x1b[%d`exit\n", (int)ft_strlen(shell.input_line) + 1);
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
