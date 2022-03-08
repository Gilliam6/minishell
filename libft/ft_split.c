/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 17:39:12 by rstephan          #+#    #+#             */
/*   Updated: 2022/03/08 17:39:14 by rstephan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_count_w(char const *str, char c)
{
	size_t	res;
	char	*f;
	char	*s;

	res = 0;
	s = (char *)str;
	f = ft_strchr(s, c);
	while (f)
	{
		if (!*f)
			break ;
		if (s == f)
			f++;
		else
			res++;
		s = f;
		f = ft_strchr(s, c);
	}
	if (ft_strlen(s))
		res++;
	return (res);
}

static void	*free_mem(char **arr)
{
	while (*arr)
	{
		free(*arr);
		*arr = *arr + 1;
	}
	free(arr);
	return (0);
}

static void	get_pos(char const *s, char c, size_t *b, size_t *e)
{
	while (s[*b] == c)
		*b = *b + 1;
	*e = *b;
	while (s[*e] != c && s[*e] != 0)
		*e = *e + 1;
	return ;
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	size_t	count;
	size_t	i;
	size_t	b;
	size_t	e;

	if (!s)
		return (0);
	i = -1;
	count = get_count_w(s, c);
	res = malloc(sizeof(void *) * (count + 1));
	if (!res)
		return (0);
	e = -1;
	while (++i < count)
	{
		b = e + 1;
		get_pos(s, c, &b, &e);
		res[i] = ft_substr(s, b, e - b);
		if (!res)
			return (free_mem(res));
	}
	res[i] = 0;
	return (res);
}
