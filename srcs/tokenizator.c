#include "../includes/minishell.h"

//t_tok	new_token(char *str, unsigned char type, t_mini *shell)
//{
//	t_tok *token;
//
//	token = (t_tok *)save_malloc(sizeof(t_tok), &shell->garbage);
//	token->name = (char *)save_malloc(sizeof(char) * ft_strlen(str) + 1, &shell->garbage);
//
//
//}
//
//t_tok 	token_split(t_mini *shell)
//{
//
//}

void	tokenizator(t_mini *shell)
{
	parser(shell);
//	shell->tokens = token_split(shell);
}