/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage_collector.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 17:25:08 by rstephan          #+#    #+#             */
/*   Updated: 2022/03/08 17:25:10 by rstephan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_custom_lstsize(t_garbage *lst)
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

void	ft_custom_lstclear(t_garbage **lst, void (*del)(void*))
{
	t_garbage	*tmp;

	while ((*lst))
	{
		tmp = (*lst)->next;
		(*del)((*lst)->content);
		free(*lst);
		*lst = tmp;
	}
}

void	ft_custom_lstadd_front(t_garbage **lst, t_garbage *new)
{
	if (*lst == 0)
	{
		*lst = new;
		(*lst)->next = 0;
	}
	else
	{
		new->next = *lst;
		*lst = new;
	}
}

t_garbage	*ft_custom_lstnew(void *content)
{
	t_garbage	*elem;

	elem = malloc(sizeof(t_garbage));
	if (!elem)
		return (0);
	elem->content = content;
	elem->next = 0;
	return (elem);
}

void	*save_malloc(int num_bytes, t_garbage **garbage)
{
	void	*pointer;

	pointer = malloc(num_bytes);
	if (!pointer)
	{
		ft_putstr_fd(MLC_ERR, 1);
		exit(1);
	}
	ft_custom_lstadd_front(garbage, ft_custom_lstnew(pointer));
	return (pointer);
}
