/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 17:39:23 by rstephan          #+#    #+#             */
/*   Updated: 2022/03/08 17:39:24 by rstephan         ###   ########.fr       */
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
