#include "../includes/libft.h"

int	ft_isascii(int d)
{
	if (d >= 0 && d <= 0177)
		return (1);
	return (0);
}
