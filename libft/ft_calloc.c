/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fuserwyn <fuserwyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 19:09:33 by fuserwyn          #+#    #+#             */
/*   Updated: 2021/08/15 19:09:35 by fuserwyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char			*dest;

	dest = malloc(count * size);
	if (dest == NULL)
		return (NULL);
	ft_memset(dest, 0, count * size);
	return ((void *)dest);
}
