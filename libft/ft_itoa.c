/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fuserwyn <fuserwyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 19:09:56 by fuserwyn          #+#    #+#             */
/*   Updated: 2021/08/15 19:09:58 by fuserwyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_sign(int n)
{
	size_t	nb;

	nb = n;
	if (n < 0)
		return (-nb);
	return (n);
}

static	size_t	ft_lh(size_t n)
{
	size_t	l;
	size_t	nb;

	nb = ft_sign(n);
	l = 1;
	while (nb >= 10)
	{
		nb = nb / 10;
		l++;
	}
	return (l);
}

static size_t	ft_circle(char *s, size_t nb, size_t l)
{
	size_t	i;

	i = 1;
	while (i <= l)
	{
		if (s[l - i] != '-')
			s[l - i] = '0' + (nb % 10);
		nb = nb / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*s;
	size_t	i;
	size_t	l;
	size_t	nb;

	nb = ft_sign(n);
	l = ft_lh(n);
	if (n < 0)
		l++;
	s = (char *)malloc(sizeof(char) * (l + 1));
	if (!s)
		return (NULL);
	if (n < 0)
		s[0] = '-';
	if (n == 0)
		s[0] = '0';
	i = ft_circle(s, nb, l);
	s[l] = '\0';
	return (s);
}
