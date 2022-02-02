/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fuserwyn <fuserwyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 19:10:46 by fuserwyn          #+#    #+#             */
/*   Updated: 2021/08/15 19:10:48 by fuserwyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dst_temp;
	unsigned char	*src_temp;
	size_t			i;

	dst_temp = (unsigned char *)dst;
	src_temp = (unsigned char *)src;
	i = 0;
	if (src == dst)
		return (dst);
	if (dst_temp > src_temp)
	{
		while (len-- > 0)
			dst_temp[len] = src_temp[len];
	}
	else
	{
		while (i < len)
		{
			dst_temp[i] = src_temp[i];
			i++;
		}
	}
	return (dst);
}
