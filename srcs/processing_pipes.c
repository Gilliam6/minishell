#include "../includes/minishell.h"

int	count_token_mem(char *str)
{
	int	i;

	i = 0;
	while (str && str[i] && str[i] != '|')
		i++;
	return (i);
}

char *create_token_str(char *str, int mem_size, t_garbage **garbage)
{
	char	*final;

	final = (char *)save_malloc(mem_size + 1, garbage);
	final[mem_size] = 0;
	while (mem_size--)
		final[mem_size] = str[mem_size];
	return (final);
}

void	print_tokens(t_tok *tokens)
{
	while (tokens)
	{
		printf("-=content | %s=-\n", tokens->name);
		printf("-=index | %d=-\n", tokens->index);
		tokens = tokens->next;
	}
}

void	processing_pipes(t_mini *shell)
{
	int		index;
	int		mem_size;
	char	*next_token;

	index = 0;
	shell->tokens = 0;
	while (shell->processed_line[index])
	{
		mem_size = count_token_mem(shell->processed_line + index);
		next_token = create_token_str(shell->processed_line + index,
									  mem_size, &shell->garbage);
		token_add(&shell->tokens, &shell->garbage, tokens_size(shell->tokens)
				  , next_token);
		if (!shell->processed_line[index + mem_size])
			break;
		index += mem_size + 1;
	}
//	print_tokens(shell->tokens);
}