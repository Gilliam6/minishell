#include "../includes/libft.h"

char	*ft_strdup(const char *s1)
{
	char			*mem;
	unsigned int	counter;

	counter = 0;
	while (*s1)
	{
		s1++;
		counter++;
	}
	mem = (char *)malloc(counter + 1);
	if (!mem)
		return (0);
	mem[counter] = 0;
	s1--;
	while (counter--)
	{
		mem[counter] = *s1;
		s1--;
	}
	return (mem);
}
