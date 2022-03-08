/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 17:37:01 by rstephan          #+#    #+#             */
/*   Updated: 2022/03/08 17:37:02 by rstephan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	void	*ch;

	ch = &c;
	while (n-- > 0)
	{
		*((char *)dest) = *((char *)src);
		if (*((char *)src) == *((char *)ch))
			return (++dest);
		src++;
		dest++;
	}
	return (0);
}
