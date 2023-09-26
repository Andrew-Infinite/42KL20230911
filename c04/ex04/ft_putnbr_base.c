#include <unistd.h>

int	map_init(char *base, int *map, int map_size)
{
	int	count;

	if (base == 0 || *base == '\0')
		return (0);
	count = -1;
	while (++count < map_size)
		map[count] = -1;
	count = -1;
	while (base[++count])
	{
		if (base[count] == '+' || base[count] == '-' || map[(int)base[count]] >
			-1)
			return (0);
		map[(int)base[count]] = count;
	}
	return (count);
}

void	recurse_base(long nbr, char *base, int size)
{
	if (nbr / size > 0)
		recurse_base(nbr / size, base, size);
	write(1, &base[nbr % size], 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	long	num;
	int		size;
	int		map[256];

	num = (long)nbr;
	size = map_init(base, map, 256);
	if (size <= 1)
		return ;
	if (size && nbr < 0)
	{
		write(1, "-", 1);
		num = -num;
	}
	recurse_base(num, base, size);
}