/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 11:50:29 by msimon            #+#    #+#             */
/*   Updated: 2021/04/20 15:35:23 by msimon           ###   ########.fr       */
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
