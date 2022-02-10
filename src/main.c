#include "minishell.h"

int	main(int argc, char **argv, char **envp)
{
	char				*input;
	// t_list				*tokens;
	t_data				data;
	// t_complex_return	ret;

	inition(&data, argc, argv, envp);
	input = NULL;
	// var_init(&ret, &tokens);
	// while (data.parsed_enviroment->name)
	// {
	// 	printf("%s\n", data.parsed_enviroment->name);
	// 	data.parsed_enviroment = data.parsed_enviroment->next;
	// }
	// printf("%s\n", data.path[1]);
	// printf("%s\n", data.path[2]);
	// printf("%s\n", data.path[3]);
	// printf("%s\n", data.path[4]);
	// printf("%s\n", data.path[5]);
	return(0);
}
