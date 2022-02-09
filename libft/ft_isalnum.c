#include "../includes/libft.h"

int	ft_isalnum(int d)
{
	if ((d < 48 || d > 57) && (d > 90 || d < 65) && (d > 122 || d < 97))
		return (0);
	return (1);
}
