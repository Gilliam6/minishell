/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_recognizer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 17:24:23 by rstephan          #+#    #+#             */
/*   Updated: 2022/03/08 17:24:25 by rstephan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int	words_calculator(char *s, char c)
{
	int	n_words;
	int	index;

	n_words = 0;
	index = 0;
	while (s[index] && s[index] == c)
		index++;
	while (s[index])
	{
		index++;
		if (s[index] && s[index] == c && !quotes(s, index))
		{
			n_words++;
			while (s[index] == c)
				index++;
		}
	}
	if (index != 0 && s[index - 1] != c)
		n_words++;
	return (n_words);
}

static unsigned int	ft_cache(const char *s, char c)
{
	unsigned int	i;
	unsigned int	result;

	i = 0;
	result = 0;
	while (s[i] && s[i] == c)
		i++;
	while (s[i] && (s[i] != c || quotes((char *)s, i)))
	{
		i++;
		result++;
	}
	return (i);
}

void	ft_filler(const char **s, char **spliter, char c, unsigned int i)
{
	unsigned int	counter;
	unsigned int	str_index;

	counter = 0;
	str_index = 0;
	while (**s && **s == c)
		(*s)++;
	while ((*s)[counter] && ((*s)[counter] != c || quotes((char *)(*s),
																counter)))
	{
		if ((*s)[counter] == '\"' || (*s)[counter] == '\'')
			counter++;
		else
		{
			spliter[i][str_index] = (*s)[counter];
			counter++;
			str_index++;
		}
	}
	spliter[i][str_index] = 0;
	(*s) += counter;
}

char	**ft_mega_custom_split(char const *s, char c, t_garbage **garbage)
{
	int		num_words;
	int		i;
	char	**split;

	num_words = words_calculator((char *)s, c);
	split = save_malloc((num_words + 1) * sizeof(char *), garbage);
	i = 0;
	while (i < num_words)
	{
		split[i] = save_malloc(ft_cache(s, c) + 1, garbage);
		ft_filler(&s, split, c, i);
		i++;
	}
	split[i] = 0;
	return (split);
}
