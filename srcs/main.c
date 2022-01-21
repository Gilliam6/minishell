#include "../includes/minishell.h"

int main(int argc, char **argv, char **env)
{
	t_env *envi;
//	int i;
	(void)argc;
	(void)argv;
	char *str;
	int exit = 0;

	envi = init_environment(env);
//	i = 0;

	while(!exit)
	{
		readline(str);
		add_history(str);

//		readline("➡️");
//		printf("%s\n", str);
	}
	return (0);
}