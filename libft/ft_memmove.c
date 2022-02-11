/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 15:33:42 by msimon            #+#    #+#             */
/*   Updated: 2021/04/30 09:03:31 by msimon           ###   ########.fr       */
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
