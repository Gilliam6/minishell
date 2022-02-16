/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 16:17:34 by msimon            #+#    #+#             */
/*   Updated: 2021/04/18 21:16:13 by msimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	void	*res;
	void	*ch;

	res = s;
	ch = &c;
	while (n-- > 0)
	{
		*((char *)s) = *((char *)ch);
		s++;
	}
	return (res);
}
