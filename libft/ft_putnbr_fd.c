/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 17:38:51 by rstephan          #+#    #+#             */
/*   Updated: 2022/03/08 17:38:52 by rstephan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	write_nbr(unsigned int n, int fd)
{
	if (n > 9)
	{
		ft_putchar_fd(write_nbr(n / 10, fd), fd);
		return ((char)(n % 10) + 48);
	}
	else
		return ((char)(n + 48));
}

void	ft_putnbr_fd(int n, int fd)
{
	int	z;

	if (n < 0)
	{
		z = -1;
		ft_putchar_fd('-', fd);
	}
	else
		z = 1;
	ft_putchar_fd(write_nbr(n * z, fd), fd);
	return ;
}
