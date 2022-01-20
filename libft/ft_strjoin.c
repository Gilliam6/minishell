#include "../includes/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		counter;
	char	*mem;

	mem = (char *)malloc(ft_strlen((char*)s1) + ft_strlen((char*)s2) + 1);
	if (!mem)
		return (0);
	counter = 0;
	while (*s1)
		mem[counter++] = *s1++;
	while (*s2)
		mem[counter++] = *s2++;
	mem[counter] = 0;
	return (mem);
}
