/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 17:38:09 by rstephan          #+#    #+#             */
/*   Updated: 2022/03/08 17:38:10 by rstephan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (!dest && !src)
		return (0);
	i = -1;
	if (src < dest)
		while (n-- > 0)
			*(((char *)dest) + n) = *(((char *)src) + n);
	else
		while (++i < n)
			*(((char *)dest) + i) = *(((char *)src) + i);
	return (dest);
}
