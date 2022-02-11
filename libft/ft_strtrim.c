/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 10:39:23 by msimon            #+#    #+#             */
/*   Updated: 2021/04/23 14:36:19 by msimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	fi;
	size_t	li;

	if (!s1 || !set)
		return (0);
	fi = 0;
	li = ft_strlen(s1);
	while (ft_strchr(set, s1[fi]))
		fi++;
	if (li > 0 && s1[fi])
	{
		li--;
		while (ft_strchr(set, s1[li]))
			li--;
		return (ft_substr(s1, fi, li - fi + 1));
	}
	return (ft_substr(s1, fi, 0));
}
