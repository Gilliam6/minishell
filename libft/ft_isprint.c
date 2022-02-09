#include "../includes/libft.h"

int	ft_isprint(int d)
{
	if (d >= 32 && d <= 126)
		return (1);
	return (0);
}
