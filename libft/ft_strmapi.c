#include "../includes/libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*res;
	unsigned int	counter;

	if (!s)
		return (0);
	counter = 0;
	while (s[counter])
		counter++;
	res = (char *)malloc(counter + 1);
	if (!res)
		return (0);
	counter = 0;
	while (s[counter])
	{
		res[counter] = f(counter, s[counter]);
		counter++;
	}
	res[counter] = 0;
	return (res);
}
