/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 17:40:54 by rstephan          #+#    #+#             */
/*   Updated: 2022/03/08 17:40:56 by rstephan         ###   ########.fr       */
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
