/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processing_tokens.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 17:25:59 by rstephan          #+#    #+#             */
/*   Updated: 2022/03/08 17:26:00 by rstephan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	find_redir(t_tok *token)
{
	int	i;

	i = 0;
	while (token->name[i])
	{
		if (ft_strcmp(token->name[i], ">") || ft_strcmp(token->name[i], ">>")
			|| ft_strcmp(token->name[i], "<"))
			return (i);
		i++;
	}
	return (0);
}

void	change_token(t_tok **token, int i)
{
	if (!i || !(*token)->name[i + 1])
		return ;
	if (ft_strcmp((*token)->name[i], ">"))
	{
		(*token)->std[1] = open((*token)->name[i + 1], O_CREAT | O_WRONLY
				| O_TRUNC, S_IRWXU);
		(*token)->type = 1;
	}
	if (ft_strcmp((*token)->name[i], ">>"))
	{
		(*token)->std[1] = open((*token)->name[i + 1], O_CREAT | O_WRONLY
				| O_APPEND, S_IRWXU);
		(*token)->type = 2;
	}
	if (ft_strcmp((*token)->name[i], "<"))
	{
		(*token)->std[0] = open((*token)->name[i + 1], O_CREAT | O_WRONLY
				| O_TRUNC, S_IRWXU);
		(*token)->type = 3;
	}
	if ((*token)->std[0] >= 0)
		(*token)->name[i] = 0;
}

void	redirect_deleter(t_mini *shell)
{
	t_tok	*tmp;

	tmp = shell->tokens;
	while (tmp)
	{
		change_token(&tmp, find_redir(tmp));
		tmp = tmp->next;
	}
}
