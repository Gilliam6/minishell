/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fuserwyn <fuserwyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 19:11:44 by fuserwyn          #+#    #+#             */
/*   Updated: 2021/08/15 19:11:49 by fuserwyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	char	*s;
	size_t	i;
	size_t	res;
	size_t	j;
	size_t	k;

	s = (char *)src;
	j = ft_strlen(dst);
	k = ft_strlen(s);
	res = 0;
	i = 0;
	if (size > j)
		res = j + k;
	else
		res = k + size;
	while (s[i] && (j + 1) < size)
	{
		dst[j] = s[i];
		j++;
		i++;
	}
	dst[j] = '\0';
	return (res);
}
