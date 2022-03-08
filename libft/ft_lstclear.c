/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 17:35:59 by rstephan          #+#    #+#             */
/*   Updated: 2022/03/08 17:36:00 by rstephan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*buf;
	t_list	*this;

	if (lst)
	{
		this = *lst;
		while (this)
		{
			buf = this;
			this = this->next;
			ft_lstdelone(buf, del);
		}
		*lst = 0;
	}
	return ;
}
