/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 21:20:44 by msimon            #+#    #+#             */
/*   Updated: 2021/04/30 11:11:08 by msimon           ###   ########.fr       */
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
