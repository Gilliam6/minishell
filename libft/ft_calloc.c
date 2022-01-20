#include "../includes/libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	index;
	void	*mass;

	index = 0;
	mass = malloc(count * size);
	if (!mass)
		return (0);
	while (index < count * size)
	{
		((char *)mass)[index] = 0;
		index++;
	}
	return (mass);
}
