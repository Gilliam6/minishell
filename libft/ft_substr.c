/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 17:41:14 by rstephan          #+#    #+#             */
/*   Updated: 2022/03/08 17:41:15 by rstephan         ###   ########.fr       */
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
