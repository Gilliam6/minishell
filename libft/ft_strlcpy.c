/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 09:25:18 by msimon            #+#    #+#             */
/*   Updated: 2021/04/30 11:39:55 by msimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	len;

	if (!dst)
		return (0);
	len = ft_strlen(src);
	if (size == 0)
		return (len);
	size--;
	if (len < size)
		size = len;
	dst[size] = 0;
	ft_memmove(dst, src, size);
	return (len);
}
