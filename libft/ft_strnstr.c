/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fuserwyn <fuserwyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 19:12:07 by fuserwyn          #+#    #+#             */
/*   Updated: 2021/08/15 19:12:08 by fuserwyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;
	size_t	l;
	char	*str1;

	i = 0;
	str1 = (char *)s1;
	l = ft_strlen(s2);
	if (l == 0 || s1 == s2)
		return (str1);
	while (str1[i] != '\0' && i < n)
	{
		j = 0;
		while (str1[i + j] != '\0' && s2[j] != '\0'
			&& str1[i + j] == s2[j] && i + j < n)
			j++;
		if (j == l)
			return (str1 + i);
		i++;
	}
	return (0);
}
