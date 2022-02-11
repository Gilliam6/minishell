/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 21:51:14 by msimon            #+#    #+#             */
/*   Updated: 2021/04/27 18:20:57 by msimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	l;

	if (!s)
		return (0);
	l = ft_strlen(s);
	if (start >= l)
		len = 0;
	else
	{
		l = l - start;
		if (l < len)
			len = l;
	}
	res = malloc(len + 1);
	if (!res)
		return (0);
	if (len > 0)
		ft_memcpy(res, &s[start], len);
	res[len] = 0;
	return (res);
}
