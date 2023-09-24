#include <unistd.h>

int	index2dto1d(int x, int y, int n)
{
	return (y * n + x);
}

void	my_print_string(char *str)
{
	int		count;
	char	*ptr;

	ptr = str;
	count = 0;
	while (*ptr)
	{
		count++;
		ptr++;
	}
	write(1, str, count);
}

void	print_map(int *map, int size)
{
	for (int i = 0; i < size * size; i++)
	{
		printf("%d ", map[i]);
		if (i % size == size - 1)
		{
			printf("\n");
		}
	}
	printf("\n");
}