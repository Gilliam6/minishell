#include "../includes/minishell.h"

void	print_tokens(t_tok *tokens)
{
	int i;

	while (tokens)
	{
		i = 0;
		while (tokens->name[i])
			printf("%s\n", tokens->name[i++]);
		printf("-------------------------\n");
		tokens = tokens->next;
	}
}


void	token_constructor(char **split, t_mini *shell)
{
	int		i;
	char	**tmp;

	i = 0;
	while (split[i])
	{
		tmp = ft_mega_custom_split(split[i], ' ', &shell->garbage);
		token_add(&shell->tokens, &shell->garbage, tmp);
		i++;
	}
}

void	tokenizator(t_mini *shell)
{
	char **split;

	split = parser(shell);
	if (split)
		token_constructor(split, shell);
//	print_tokens(shell->tokens);
//	token_num = calculate_tokens(shell->processed_line);
//	printf("%d\n", token_num);
//	shell->tokens = token_split(shell);
}