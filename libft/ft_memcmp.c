/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 17:39:42 by msimon            #+#    #+#             */
/*   Updated: 2021/04/29 16:16:58 by msimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	ch1;
	unsigned char	ch2;
	size_t			i;

	i = -1;
	while (++i < n)
	{
		ch1 = *(((unsigned char *)s1) + i);
		ch2 = *(((unsigned char *)s2) + i);
		if (ch1 != ch2)
			return (ch1 - ch2);
	}
	return (0);
}
