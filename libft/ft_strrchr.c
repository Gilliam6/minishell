/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fuserwyn <fuserwyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 19:12:10 by fuserwyn          #+#    #+#             */
/*   Updated: 2021/08/15 19:12:12 by fuserwyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*chr;
	size_t	i;

	i = 0;
	chr = NULL;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			chr = ((char *)&s[i]);
		i++;
	}
	if (s[i] == (char)c)
		chr = ((char *)&s[i]);
	return (chr);
}
