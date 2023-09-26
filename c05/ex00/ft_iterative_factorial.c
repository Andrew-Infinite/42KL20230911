int	ft_iterative_factorial(int nb)
{
	int	i;
	int	fac;

	if (nb < 0)
		return (0);
	i = 0;
	fac = 1;
	while (++i <= nb)
		fac = fac * i;
	return (fac);
}
