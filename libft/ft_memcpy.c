/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 17:28:12 by msimon            #+#    #+#             */
/*   Updated: 2021/04/30 08:59:05 by msimon           ###   ########.fr       */
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
