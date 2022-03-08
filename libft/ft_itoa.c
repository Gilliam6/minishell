/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 17:35:29 by rstephan          #+#    #+#             */
/*   Updated: 2022/03/08 17:35:30 by rstephan         ###   ########.fr       */
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
