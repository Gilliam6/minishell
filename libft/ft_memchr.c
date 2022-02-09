#include "../includes/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned int	counter;
	unsigned char	*p;

	counter = 0;
	while (counter < n)
	{
		if (*((unsigned char *)s) == ((unsigned char)c))
		{
			p = ((unsigned char *)s);
			return (p);
		}
		s++;
		counter++;
	}
	return (p = 0);
}
