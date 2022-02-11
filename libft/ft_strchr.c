/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 11:25:46 by msimon            #+#    #+#             */
/*   Updated: 2021/04/26 12:51:27 by msimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	void	*ch;
	size_t	i;
	char	*p;

	i = -1;
	ch = &c;
	p = (char *)s;
	while (s[++i] != 0)
		if (s[i] == *((char *)ch))
			return (p + i);
	if (*((char *)ch) == 0)
		return (p + i);
	else
		return (0);
}
