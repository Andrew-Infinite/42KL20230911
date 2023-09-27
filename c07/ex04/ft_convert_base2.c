int	in_range_int(long nbr)
{
	if (nbr > 2147483647 || nbr < -2147483648)
		return (0);
	return (1);
}

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
		if (is_sign(base[count]) || map[(int)base[count]] > -1)
			return (0);
		map[(int)base[count]] = count;
	}
	return (count);
}
