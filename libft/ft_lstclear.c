/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fuserwyn <fuserwyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 19:10:07 by fuserwyn          #+#    #+#             */
/*   Updated: 2022/01/29 21:46:25 by fuserwyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*p;
	t_list	*t;

	t = *lst;
	while (t != NULL)
	{
		p = (*t).next;
		if (del != NULL)
			del ((*t).content);
		free(t);
		t = p;
	}
	*lst = NULL;
}
