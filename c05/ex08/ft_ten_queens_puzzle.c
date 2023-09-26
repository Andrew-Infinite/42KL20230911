#include <unistd.h>

int	is_valid(char *map, int x, int y)
{
	int	j;

	j = y;
	while (--j >= 0)
		if (map[j] == x + '0')
			return (0);
	j = y;
	while (--j >= 0)
		if (j - y == map[j] - (x + '0') || y - j == map[j] - (x + '0'))
			return (0);
	return (1);
}

void	ft_solver(char *map, int y, int *ans_count)
{
	int	i;

	if (y >= 10)
	{
		write(1, map, 10);
		write(1, "\n", 1);
		*ans_count += 1;
	}
	i = -1;
	while (++i < 10)
	{
		if (is_valid(map, i, y))
		{
			map[y] = i + '0';
			ft_solver(map, y + 1, ans_count);
			map[y] = '-';
		}
	}
}

int	ft_ten_queens_puzzle(void)
{
	char	map[11];
	int		i;
	int		ans_count;

	ans_count = 0;
	i = -1;
	while (++i < 10)
		map[i] = '0';
	map[10] = '\0';
	ft_solver(map, 0, &ans_count);
	return (ans_count);
}

// int main (){
// 	int x = ft_ten_queens_puzzle();
// 	printf("%d",x);
// }
