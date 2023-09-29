#include "ft_strs_to_tab.h"
#include "unistd.h"

void	my_print_string(char *str)
{
	int		count;
	char	*ptr;

	ptr = str;
	count = 0;
	while (*ptr)
	{
		count++;
		ptr++;
	}
	write(1, str, count);
}

void	ft_putnbr(int n)
{
	char	*special;
	char	neg;
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

void	ft_show_tab(struct s_stock_str *par)
{
	while (par && par->str)
	{
		my_print_string(par->str);
		write(1, "\n", 1);
		ft_putnbr(par->size);
		write(1, "\n", 1);
		my_print_string(par->copy);
		write(1, "\n", 1);
		par++;
	}
}

// int main(){
// 	char *x[] = {"asdf","vcxv","qweasd"};
// 	t_stock_str *temp = ft_strs_to_tab(3,x);
// 	ft_show_tab(temp);
// 	destructor(temp,3+1);
// }