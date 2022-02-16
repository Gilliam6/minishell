/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 16:03:37 by msimon            #+#    #+#             */
/*   Updated: 2021/04/28 16:39:49 by msimon           ###   ########.fr       */
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
