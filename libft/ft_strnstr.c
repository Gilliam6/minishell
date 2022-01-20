#include "../includes/libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int		counter;

	if (needle[0] == 0 || haystack == needle)
		return ((char *)haystack);
	while (*haystack && len)
	{
		if (*haystack == *needle)
		{
			counter = 0;
			while (haystack[counter] && needle[counter] == haystack[counter]
				&& len--)
				counter++;
			if (needle[counter] == 0)
				return ((char *)haystack);
			len += counter;
		}
		haystack++;
		len--;
	}
	return (0);
}
