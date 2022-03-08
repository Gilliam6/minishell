/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 17:29:02 by rstephan          #+#    #+#             */
/*   Updated: 2022/03/08 17:29:06 by rstephan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	long_nb(long int z)
{
	if (z > 0)
		return (-1);
	else
		return (0);
}

int	ft_atoi(const char *str)
{
	long int	res;
	long int	i;
	long int	z;

	res = 0;
	i = 0;
	z = 1;
	while ((*str > 8 && *str < 14) || *str == 32)
		str++;
	if (*str == 45)
	{
		z = -1;
		str++;
	}
	else if (*str == 43)
		str++;
	while (*str > 47 && *str < 58)
	{
		res = (res * 10) + *str - 48;
		if (i > res)
			return (long_nb(z));
		i = res;
		str++;
	}
	return ((int)(res * z));
}
