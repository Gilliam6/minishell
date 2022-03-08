/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 17:41:04 by rstephan          #+#    #+#             */
/*   Updated: 2022/03/08 17:41:06 by rstephan         ###   ########.fr       */
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
