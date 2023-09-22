#include <unistd.h>

int	ft_strlen(char *str)
{
	int	count;

	count = 0;
	while (*str++)
		count++;
	return (count);
}

int	main(int argc, char *argv[])
{
	int	i;

	i = 0;
	while (++i < argc)
	{
		write(1, argv[i], ft_strlen(argv[i]));
		write(1, "\n", 1);
	}
	return (0);
}
