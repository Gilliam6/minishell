#include "../includes/libft.h"

static int	ft_char_valid(char s1, char const *set)
{
	int	counter;

	counter = 0;
	while (set[counter])
	{
		if (set[counter] == s1)
			return (1);
		counter++;
	}
	return (0);
}

static size_t	ft_memcounter(char const *s1, char const *set)
{
	size_t	counter;
	size_t	index;
	char	*p;

	p = (char *)s1;
	counter = 0;
	while (((*p < 32 || *p > 126) || ft_char_valid(*p, set)) && *p)
	{
		if (ft_char_valid(*p, set))
			counter++;
		p++;
	}
	if (*p == 0)
		return (0);
	while (*p)
		p++;
	while ((*p < 32 || *p > 126) || ft_char_valid(*p, set))
	{
		if (ft_char_valid(*p, set))
			counter++;
		p--;
	}
	index = ft_strlen((char *)s1);
	return (index - counter);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		counter;
	char	*mem;
	int		index;

	if (!s1 || !set)
		return (0);
	index = 0;
	counter = ft_memcounter(s1, set);
	mem = (char *)malloc(counter + 1);
	if (!mem)
		return (0);
	while (((*s1 < 32 || *s1 > 126) || ft_char_valid(*s1, set)) && *s1)
		s1++;
	while (counter)
	{
		mem[index] = *s1;
		index++;
		s1++;
		counter--;
	}
	mem[index] = 0;
	return (mem);
}
