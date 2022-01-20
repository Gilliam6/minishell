#include "../includes/libft.h"

static unsigned int	ft_check_memory(char const *s, unsigned int start,
									 size_t len)
{
	unsigned int	counter;

	counter = 0;
	if (ft_strlen((char *)s) < (int)start)
		return (0);
	while (s[start])
	{
		start++;
		counter++;
	}
	if (counter < len || !counter)
		return (counter);
	else
		return (len);
}

char	*ft_substr(char const *s, unsigned int start,
				size_t len)
{
	char			*mem;
	unsigned int	counter;

	if (!s)
		return (0);
	counter = ft_check_memory(s, start, len);
	mem = (char *)malloc(counter + 1);
	if (!mem)
		return (0);
	if (!counter)
	{
		mem[0] = 0;
		return (mem);
	}
	counter = 0;
	while (len-- && s[start])
	{
		mem[counter] = s[start];
		counter++;
		start++;
	}
	mem[counter] = 0;
	return (mem);
}
