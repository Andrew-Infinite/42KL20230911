#include <unistd.h>

void	ft_putnbr(int n)
{
		char *special;
		char neg;
	char	x;

	if (n == -2147483648)
	{
		special = "-2147483648";
		write(1, special, 11);
		return ;
	}
	if (n < 0)
	{
		neg = '-';
		write(1, &neg, 1);
		n = -n;
	}
	if (n / 10 > 0)
	{
		ft_putnbr(n / 10);
	}
	x = '0' + n % 10;
	write(1, &x, 1);
}
