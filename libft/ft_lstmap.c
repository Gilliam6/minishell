/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 17:36:35 by rstephan          #+#    #+#             */
/*   Updated: 2022/03/08 17:36:36 by rstephan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*res;
	t_list	*buf;

	res = 0;
	if (f && lst)
	{
		res = ft_lstnew(f(lst->content));
		if (!res)
			return (0);
		lst = lst->next;
		buf = res;
		while (lst)
		{
			buf->next = ft_lstnew(f(lst->content));
			if (!buf->next)
			{
				ft_lstclear(&res, del);
				return (0);
			}
			buf = buf->next;
			lst = lst->next;
		}		
	}
	return (res);
}
