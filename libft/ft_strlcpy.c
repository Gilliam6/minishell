#include "../includes/libft.h"

size_t	ft_strlcpy(char *restrict dst, const char *restrict src, size_t
dstsize)
{
	int	counter;

	counter = 0;
	if (!dst || !src)
		return (0);
	if (dstsize > 0)
	{
		dstsize --;
		while (dstsize-- && src[counter])
		{
			dst[counter] = src[counter];
			counter++;
		}
		dst[counter] = 0;
	}
	while (src[counter])
		counter++;
	return (counter);
}
