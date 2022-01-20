#include "../includes/libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int	k;

	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else
	{
		if (n < 0)
		{
			write(fd, "-", 1);
			n = -n;
		}
		if (n > 9)
		{
			k = (n % 10) + '0';
			ft_putnbr_fd(n / 10, fd);
			write(fd, &k, 1);
		}
		if (n <= 9)
		{
			k = (n % 10) + '0';
			write(fd, &k, 1);
		}
	}
}
