#include "../includes/libft.h"

void	*ft_memset(void *point, int c, size_t len)
{
	unsigned int	counter;

	counter = 0;
	c = (unsigned char)c;
	while (counter < len)
	{
		((unsigned char *)point)[counter] = c;
		counter++;
	}
	return (point);
}
