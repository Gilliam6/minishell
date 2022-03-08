/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 17:40:44 by rstephan          #+#    #+#             */
/*   Updated: 2022/03/08 17:40:45 by rstephan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	ln;
	size_t	i;

	i = -1;
	ln = ft_strlen(little);
	if (little[0] == 0)
		return ((char *)big);
	while (big[++i] != 0 && len-- >= ln)
	{
		if (ft_memcmp((char *)&big[i], little, ln) == 0)
			return ((char *)&big[i]);
	}
	return (0);
}
