#include <unistd.h>

void    my_print_string(char *str);

int index2dto1d(int x, int y, int n);

int valid_check_left(int *map, int constraint, int y, int size);

int valid_check_right(int *map, int constraint, int y, int size);

int valid_check_up(int *map, int constraint, int x, int size);

int valid_check_bottom(int *map, int constraint, int x, int size);

int valid_down(int *map, int x, int size, int height);

void	print_map(int *map, int size);

int	back_tracking(int *map, int y, int size, int height, int *constraint)
{
	int	i;
	int	temp;

	i = -1;
	if (height < 1 && y >= size - 1)
	{
		y = -1;
		while (++i < size)
			while (++y < size)
				if (!valid_check_bottom(map, constraint[size + i], i, size)
					|| !valid_check_right(map, constraint[size * 3 + y], y,
						size))
					return (0);
		// print_map(map);
		return (1);
	}
	if (height < 1)
	{
		return (back_tracking(map, y + 1, size, size, constraint));
	}
	while (++i < size)
	{
		if (map[index2dto1d(i, y, size)] <= 0 && valid_down(map, i, size,
				height) == 1 && valid_check_up(map, constraint[i], i, size)
			&& valid_check_left(map, constraint[size * 2 + y], y, size))
		{
			map[index2dto1d(i, y, size)] = height;
			temp = back_tracking(map, y, size, height - 1, constraint);
			if (temp > 0)
				return (1);
			map[index2dto1d(i, y, size)] = 0;
		}
	}
	return (0);
}

int	main(void)
{
	int size = 4;
	// int constraint[16] = {4, 3, 2, 1, 1, 2, 2, 2, 4, 3, 2, 1, 1, 2, 2, 2};
	int constraint[16] = {3, 2, 1, 2, 1, 2, 2, 3, 3, 2, 2, 1, 2, 1, 2, 3};
	int map[16];
	for (int i = 0; i < size * size; i++)
	{
		map[i] = 0;
	}
	back_tracking(map, 0, size, size, constraint);
	print_map(map, 4);
	return (0);
}
