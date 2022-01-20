#include "../includes/libft.h"

static void	ft_free(char **spliter, unsigned int i)
{
	unsigned int	d;

	d = 0;
	while (d < i)
	{
		free(spliter[d]);
		d++;
	}
	free(spliter);
}

static unsigned int	ft_pieces(char const *s, char c)
{
	unsigned int	counter;
	unsigned int	delen;

	delen = 0;
	counter = 0;

	while (s[counter] && s[counter] == c)
		counter++;
	while (s[counter])
	{
		counter++;
		if (s[counter] && s[counter] == c)
		{
			delen++;
			while (s[counter] == c)
				counter++;
		}
	}
	if (counter != 0 && s[counter - 1] != c)
		delen++;
	return (delen);
}

static unsigned int	ft_cache(const char *s, char c)
{
	unsigned int	i;

	i = 0;
	while (*s && *s == c)
		s++;
	while (*s && *s != c)
	{
		i++;
		s++;
	}
	return (i);
}

static char	**ft_filler(const char **s, char **spliter, char c, unsigned int i)
{
	unsigned int	counter;

	counter = 0;
	while (**s && **s == c)
		(*s)++;
	while ((*s)[counter] && (*s)[counter] != c)
	{
		spliter[i][counter] = (*s)[counter];
		counter++;
	}
	spliter[i][counter] = 0;
	(*s) += counter;
	return (spliter);
}

char	**ft_split(char const *s, char c)
{
	unsigned int	delen;
	unsigned int	i;
	char			**spliter;
	unsigned int	str_len;

	delen = ft_pieces(s, c);
	spliter = (char **)malloc(sizeof(char *) * (delen + 1));
	if (!spliter)
		return (0);
	i = 0;
	while (i < delen)
	{
		str_len = ft_cache(s, c);
		spliter[i] = (char *)malloc(sizeof(char) * (str_len + 1));
		if (!(spliter[i]))
		{
			ft_free(spliter, i);
			return (0);
		}
		spliter = ft_filler(&s, spliter, c, i);
		i++;
	}
	spliter[i] = 0;
	return (spliter);
}
