/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fuserwyn <fuserwyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 19:12:16 by fuserwyn          #+#    #+#             */
/*   Updated: 2021/08/15 19:12:17 by fuserwyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	ft_len(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

static int	ft_find(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	char	*trim;
	size_t	j;
	size_t	l;

	i = 0;
	j = 0;
	if (!s1 || !set)
		return (NULL);
	while (s1[j] && ft_find(s1[j], set))
		j++;
	l = ft_len(s1);
	while (l > j && ft_find(s1[l - 1], set))
		l--;
	trim = malloc(sizeof(*s1) * (l - j + 1));
	if (trim == NULL)
		return (NULL);
	while (j < l)
	{
		trim[i] = s1[j];
		i++;
		j++;
	}
	trim[i] = '\0';
	return (trim);
}
