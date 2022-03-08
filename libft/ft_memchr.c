/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 17:37:11 by rstephan          #+#    #+#             */
/*   Updated: 2022/03/08 17:37:12 by rstephan         ###   ########.fr       */
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
