#include "../includes/libft.h"

int	ft_atoi(const char *str)
{
	long int	final;
	int			minus;

	minus = 1;
	final = 0;
	while ((*str >= 9 && *str <= 13) || (*str == 32))
		str++;
	if (*str == 43 || *str == 45)
	{
		if (*str == 45)
			minus = -1;
		str++;
	}
	while (*str >= 48 && *str <= 57)
	{
		final *= 10;
		final += *str - 48;
		str++;
	}
	return (final * minus);
}
