#include <stdlib.h>

int		is_sign(char str);

int		map_init(char *base, int *map, int map_size);

int		in_range_int(long nbr);

int	ft_atoi_base(char *str, char *base, long *num)
{
	int	sign;
	int	map[256];
	int	size;

	sign = 1;
	*num = 0;
	size = map_init(base, map, 256);
	if (size <= 1)
		return (0);
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	while (is_sign(*str))
	{
		if (*str == '-')
			sign = -sign;
		str++;
	}
	while (map[(int)*str] >= 0)
	{
		if (in_range_int(*num * size + sign * map[(int)*str]))
			*num = *num * size + sign * map[(int)*str];
		str++;
	}
	return (1);
}

int	ft_strlen_base(long nbr, char *base, int size, char *ptr)
{
	int	count;

	count = 1;
	if (nbr / size > 0)
		count += ft_strlen_base(nbr / size, base, size, ptr);
	if (ptr != 0)
		ptr[count - 1] = base[nbr % size];
	return (count);
}

char	*ft_itoa_base(long nbr, char *base)
{
	int		size;
	int		mallocsize;
	int		map[256];
	char	*ptr;

	size = map_init(base, map, 256);
	if (size <= 1)
		return (0);
	if (nbr < 0)
		mallocsize = ft_strlen_base(-nbr, base, size, 0) + 2;
	else
		mallocsize = ft_strlen_base(nbr, base, size, 0) + 1;
	ptr = (char *)malloc(mallocsize * sizeof(char));
	ptr[mallocsize - 1] = '\0';
	if (nbr < 0)
	{
		ptr[0] = '-';
		ft_strlen_base(-nbr, base, size, ptr + 1);
	}
	else
		ft_strlen_base(nbr, base, size, ptr);
	return (ptr);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	long	num;

	if (ft_atoi_base(nbr, base_from, &num) == 0)
		return (0);
	return (ft_itoa_base(num, base_to));
}

// #include <stdio.h>
// int main(){
// 	char *x = ft_convert_base("2147483648","0123456789","0123456789ABCDEF");
// 	printf("%s\n",x);
// }