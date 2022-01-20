#include "../includes/minishell.h"

int main(int argc, char **argv, char **env)
{
	t_env *envi;
//	int i;
	(void)argc;
	(void)argv;

	envi = init_environment(env);
//	i = 0;
	while(envi)
	{
		printf("%s\n", envi->content);
		envi = envi->next;
	}
	return (0);
}