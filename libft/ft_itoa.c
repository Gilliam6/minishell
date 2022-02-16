/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 11:28:53 by msimon            #+#    #+#             */
/*   Updated: 2021/04/27 22:28:06 by msimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_len(int n, unsigned int *un)
{
	size_t			res;
	unsigned int	n_;

	res = 1;
	if (n < 0)
	{
		res++;
		*un = n * -1;
	}
	else
		*un = n;
	n_ = *un / 10;
	while (n_ > 0)
	{
		n_ = n_ / 10;
		res++;
	}
	return (res);
}

char	*ft_itoa(int n)
{
	char			*res;
	unsigned int	un;
	size_t			len;

	len = get_len(n, &un);
	res = malloc(len + 1);
	if (!res)
		return (0);
	res[len] = 0;
	res[len - 1] = 48;
	if (n < 0)
		res[0] = '-';
	while (un > 0)
	{
		res[--len] = (un % 10) + 48;
		un = un / 10;
	}
	return (res);
}
