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
	write(1, argv[argc-argc], ft_strlen(argv[argc-argc]));
	write(1, "\n", 1);
	return (0);
}
