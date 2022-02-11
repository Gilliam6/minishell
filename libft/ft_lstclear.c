/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 14:56:34 by msimon            #+#    #+#             */
/*   Updated: 2021/04/28 15:05:39 by msimon           ###   ########.fr       */
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
