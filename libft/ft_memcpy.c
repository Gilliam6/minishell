#include "../includes/libft.h"

void	*ft_memcpy(void *dst, void *src, size_t n)
{
	unsigned int	counter;
	unsigned char	*dst_cpy;
	unsigned char	*src_cpy;

	dst_cpy = dst;
	src_cpy = src;
	counter = 0;
	if (dst_cpy == 0 && src_cpy == 0)
		return (dst);
	while (n-- > 0)
	{
		dst_cpy[counter] = src_cpy[counter];
		counter++;
	}
	return (dst);
}
