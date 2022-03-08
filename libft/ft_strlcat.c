/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 17:39:57 by rstephan          #+#    #+#             */
/*   Updated: 2022/03/08 17:39:58 by rstephan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	d_len;
	size_t	s_len;

	d_len = ft_strlen(dst);
	if (size > d_len + 1)
		s_len = ft_strlcpy(dst + d_len, src, size - d_len);
	else
		s_len = ft_strlcpy(dst + d_len, src, 0);
	if (size < d_len)
		return (s_len + size);
	else
		return (s_len + d_len);
}
