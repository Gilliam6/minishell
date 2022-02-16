/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 14:08:35 by msimon            #+#    #+#             */
/*   Updated: 2021/04/27 18:18:47 by msimon           ###   ########.fr       */
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
