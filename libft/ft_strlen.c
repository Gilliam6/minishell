#include "../includes/libft.h"

int	ft_strlen(char *str)
{
	unsigned long int	count;

	count = 0;
	while (str[count] != 0)
		count++;
	return (count);
}
