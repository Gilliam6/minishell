#include "../includes/libft.h"

void	ft_bzero(void *s, size_t n)
{
	while (n-- > 0)
	{
		*(unsigned char *)s = 0;
		s++;
	}
}
