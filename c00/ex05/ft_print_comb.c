#include <unistd.h>

void	number_printer(int hundreds, int tens, int ones)
{
	char	output[3];
	char	comma[2];

	output[0] = '0' + hundreds;
	output[1] = '0' + tens;
	output[2] = '0' + ones;
	comma[0] = ',';
	comma[1] = ' ';
	write(1, &output, 3);
	if (!(hundreds == 7 && tens == 8 && ones == 9))
	{
		write(1, &comma, 2);
	}
}
void	ft_print_comb(void)
{
	int i;
	int j;
	int k;
	i = 0;
	j = 1;
	k = 2;
	while (i <= 7)
	{
		while (j <= 8)
		{
			while (k <= 9)
			{
				number_printer(i, j, k);
				k++;
			}
			j++;
			k = j + 1;
		}
		i++;
		j = i + 1;
	}
	number_printer(7, 8, 9);
}