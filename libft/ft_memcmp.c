/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 17:37:24 by rstephan          #+#    #+#             */
/*   Updated: 2022/03/08 17:37:25 by rstephan         ###   ########.fr       */
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
