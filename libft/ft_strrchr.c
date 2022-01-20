#include "../includes/libft.h"

char	*ft_strrchr(const char *s1, int c)
{
	char	*s2;

	s2 = (char *)s1;
	while (*s2)
		s2++;
	if (c == 0)
		return (s2);
	while (s2 != s1)
	{
		s2--;
		if (*s2 == c)
			return (s2);
	}
	return (s2 = 0);
}
