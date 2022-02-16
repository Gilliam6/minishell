/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 11:36:39 by msimon            #+#    #+#             */
/*   Updated: 2021/04/29 17:32:03 by msimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	void	*ch;
	size_t	i;
	char	*p;

	i = ft_strlen(s) + 1;
	ch = &c;
	p = (char *)s;
	while (i-- > 0)
		if (s[i] == *((char *)ch))
			return (p + i);
	return (0);
}
