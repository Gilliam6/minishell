/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 17:40:07 by rstephan          #+#    #+#             */
/*   Updated: 2022/03/08 17:40:08 by rstephan         ###   ########.fr       */
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
