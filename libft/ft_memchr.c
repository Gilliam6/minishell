/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 16:38:17 by msimon            #+#    #+#             */
/*   Updated: 2021/04/20 17:51:22 by msimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	void	*ch;
	size_t	i;

	ch = &c;
	i = -1;
	while (++i < n)
		if (*(((char *)s) + i) == *((char *)ch))
			return (((char *)s) + i);
	return (0);
}
