/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens_linker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 17:24:11 by rstephan          #+#    #+#             */
/*   Updated: 2022/03/08 17:24:13 by rstephan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	tokens_size(t_tok *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

void	token_add_back(t_tok **lst, t_tok *new)
{
	t_tok	*begin;

	if (!new)
		return ;
	if (*lst)
	{
		begin = *lst;
		while ((*lst)->next)
			*lst = (*lst)->next;
		(*lst)->next = new;
		*lst = begin;
	}
	else
		*lst = new;
}

t_tok	*create_new_token(char **str, t_garbage **garbage)
{
	t_tok	*elem;

	elem = save_malloc(sizeof(t_tok), garbage);
	if (!elem)
		return (0);
	elem->name = str;
	elem->std[0] = 0;
	elem->std[1] = 1;
	elem->next = 0;
	return (elem);
}

void	token_add(t_tok **tokens, t_garbage **garbage, char **str)
{
	t_tok	*new;

	new = create_new_token(str, garbage);
	token_add_back(tokens, new);
}
