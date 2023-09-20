void	ft_putstr(char *str)
{
	int count;
	char *ptr;

	ptr = str;
	count = 0;
	while (*ptr)
	{
		count++;
		ptr++;
	}
	write(1, str, count);
}