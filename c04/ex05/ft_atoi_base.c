int	is_sign(char str)
{
	if (str == '+' || str == '-')
	{
		return (1);
	}
	return (0);
}

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

int	ft_atoi_base(char *str, char *base)
{
	int temp;
	int sign;
	int map[256];
	int size;

	sign = 1;
	temp = 0;
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
		temp = temp * size + sign * map[(int)*str];
		str++;
	}
	return (temp);
}