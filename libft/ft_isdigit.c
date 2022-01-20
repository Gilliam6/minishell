#include "../includes/libft.h"

int	ft_isdigit(int d)
{
	if (d < 48 || d > 57)
		return (0);
	return (1);
}
