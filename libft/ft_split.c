/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fuserwyn <fuserwyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 19:11:09 by fuserwyn          #+#    #+#             */
/*   Updated: 2021/08/15 19:11:11 by fuserwyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_counter(const char *s, char c)
{
	int	i;
	int	w;

	w = 0;
	i = 0;
	while (s[i] == c)
		i++;
	if (s[i] == '\0')
		return (0);
	while (s[i] != '\0')
	{
		if (s[i] == c && s[i + 1] != '\0' && s[i - 1] != c)
			w++;
		i++;
	}
	return (w + 1);
}

static	size_t	ft_len(const char *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0' && s[i] != c)
		i++;
	return (i);
}

static char	**ft_free(char **r)
{
	size_t	i;

	i = 0;
	while (r[i])
	{
		free(r[i]);
		i++;
	}
	free (r);
	return (NULL);
}

static size_t	ft_pass(char const *s, char c, size_t i)
{
	while (s[i] == c && s[i])
		i++;
	return (i);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	if (!s)
		return (NULL);
	arr = (char **)malloc(sizeof(char *) * (ft_counter(s, c) + 1));
	if (!arr)
		return (NULL);
	i = ft_pass(s, c, i);
	while (j < ft_counter(s, c) && s[i])
	{
		arr[j] = ft_substr(s, i, ft_len(&s[i], c));
		if (!arr)
			return (ft_free(&arr[j]));
		i = i + ft_len(&s[i], c);
		j++;
		i = ft_pass(s, c, i);
	}
	arr[j] = NULL;
	return (arr);
}
