#include <unistd.h>

void	my_print(char *str, int length)
{
	write(1, str, length);
}

int	my_strcmp(char *a, char *b)
{
	while (*a || *b)
	{
		if (*a < *b)
		{
			return (-1);
		}
		else if (*a > *b)
		{
			return (1);
		}
		*a++;
		*b++;
	}
	return (0);
}

char	roof(int i, int size)
{
	return ('9' - (size - 1 - i));
}

void	increment_with_roof(char *str, int n)
{
	int	i;

	i = n - 1;
	if (str[n - 1] < '9')
	{
		str[n - 1]++;
	}
	else
	{
		str[n - 1]++;
		while (i >= 0 && str[i] > roof(i, n))
		{
			str[i - 1]++;
			str[i] = str[i - 1] + 1;
			i--;
		}
		while (i++ < n)
		{
			str[i] = str[i - 1] + 1;
		}
	}
}

void	init_min(char *ptr, int size)
{
	int	i;

	i = -1;
	while (++i < size)
	{
		ptr[i] = i + '0';
	}
}

void	init_max(char *ptr, int size)
{
	int	i;

	i = -1;
	while (++i < size)
	{
		ptr[i] = roof(i, size);
	}
}
void	print_all(int n)
{
	char	string[n];
	char	max[n];
	int		i;
	int		a;

	init_min(string, n);
	init_max(max, n);
	i = n - 1;
	while (my_strcmp(string, max) < 0)
	{
		my_print(string, n);
		my_print(", ", 2);
		increment_with_roof(string, n);
	}
	my_print(string, n);
	a = 1;
}

int main(){
	print_all(4);
	return 0;
}
