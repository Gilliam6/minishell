/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 17:37:34 by rstephan          #+#    #+#             */
/*   Updated: 2022/03/08 17:37:35 by rstephan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	void	*res;

	res = dest;
	if (dest || src)
	{
		while (n-- > 0)
		{
			*((char *)dest) = *((char *)src);
			src++;
			dest++;
		}
	}
	return (res);
}
