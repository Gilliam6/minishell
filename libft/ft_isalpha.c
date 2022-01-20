#include "../includes/libft.h"

int	ft_isalpha(int d)
{
	if ((d >= 65 && d <= 90) || (d >= 97 && d <= 122))
		return (1);
	return (0);
}
