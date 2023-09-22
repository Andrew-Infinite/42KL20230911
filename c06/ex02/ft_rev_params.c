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
	while (--argc > 0)
	{
		write(1, argv[argc], ft_strlen(argv[argc]));
		write(1, "\n", 1);
	}
	return (0);
}
