#include "../includes/libft.h"

static int	ft_diglen(int n)
{
	int	counter;

	counter = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		counter++;
	while (n)
	{
		counter++;
		n /= 10;
	}
	return (counter);
}

static char	*ft_filler(char *itoa, int n, int diglen)
{
	itoa[diglen] = 0;
	diglen--;
	if (n < 0)
	{
		itoa[0] = '-';
		if (n == -2147483648)
		{
			itoa[diglen] = 56;
			n /= 10;
			diglen--;
		}
		n = -n;
	}
	if (n == 0)
		itoa[0] = 48;
	while (n)
	{
		itoa[diglen] = n % 10 + 48;
		n /= 10;
		diglen--;
	}
	return (itoa);
}

char	*ft_itoa(int n)
{
	int		diglen;
	char	*itoa;

	diglen = ft_diglen(n);
	itoa = (char *)malloc(diglen + 1);
	if (!itoa)
		return (0);
	itoa = ft_filler(itoa, n, diglen);
	return (itoa);
}
