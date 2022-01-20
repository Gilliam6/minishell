#include "../includes/libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*s2;

	s2 = (char *)s;
	while (*s2)
	{
		if (*s2 == (unsigned char)c)
			return (s2);
		s2++;
	}
	if (*s2 == (char)c)
		return (s2);
	return (s2 = 0);
}
