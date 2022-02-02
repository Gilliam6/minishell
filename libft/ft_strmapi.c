/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fuserwyn <fuserwyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 19:12:00 by fuserwyn          #+#    #+#             */
/*   Updated: 2021/08/15 19:12:02 by fuserwyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	ft_len(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strmapi(char const *s, char(*f)(unsigned int, char))
{
	unsigned int	i;
	unsigned char	*dst;

	i = 0;
	if (!s)
		return (NULL);
	dst = (unsigned char *)malloc(sizeof(unsigned char)
			* ft_len((char *)s) + 1);
	if (dst == NULL)
		return (NULL);
	while (s[i])
	{
		dst[i] = (*f)(i, (char)s[i]);
		i++;
	}
	dst[i] = '\0';
	return ((char *)dst);
}
