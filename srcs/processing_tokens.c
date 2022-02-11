#include "../includes/minishell.h"

int	find_redir(t_tok *token)
{
	int	i;

	i = 0;
	while (token->name[i])
	{
		if (ft_strcmp(token->name[i], ">") || ft_strcmp(token->name[i],
			  ">>") || ft_strcmp(token->name[i], "<"))
			  return (i);
		i++;
	}
	return (0);
}

void	change_token(t_tok **token, int i)
{
	if (!i || !(*token)->name[i + 1])
		return;
	if (ft_strcmp((*token)->name[i], ">"))
	{
		(*token)->fd_out = open((*token)->name[i + 1], O_CREAT | O_WRONLY |
													   O_TRUNC, S_IRWXU);
		(*token)->type = 1;
	}
	if (ft_strcmp((*token)->name[i], ">>"))
	{
		(*token)->fd_out = open((*token)->name[i + 1], O_CREAT | O_WRONLY |
													   O_APPEND, S_IRWXU);
		(*token)->type = 2;
	}
	if (ft_strcmp((*token)->name[i], "<"))
	{
		(*token)->fd_in = open((*token)->name[i + 1], O_CREAT | O_WRONLY |
													   O_TRUNC, S_IRWXU);
		(*token)->type = 3;
	}
	if ((*token)->fd_out >= 0)
		(*token)->name[i] = 0;
}

void	redirect_deleter(t_mini *shell)
{
	t_tok *tmp;

	tmp = shell->tokens;
	while (tmp)
	{
		change_token(&tmp, find_redir(tmp));
//		if (tmp->fd_out == -1)
//			unexpected_exit(&shell->garbage, OPN_FD_ERR, 1);
		tmp = tmp->next;
	}
}