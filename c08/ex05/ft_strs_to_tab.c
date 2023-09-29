#include "ft_strs_to_tab.h"
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	count;

	count = 0;
	while (*str++)
		count++;
	return (count);
}

char	*ft_strdup(char *src)
{
	int		i;
	int		size;
	char	*ptr_dup;

	i = -1;
	size = ft_strlen(src) + 1;
	ptr_dup = (char *)malloc(size * sizeof(char));
	while (src[++i])
	{
		ptr_dup[i] = src[i];
	}
	ptr_dup[size - 1] = '\0';
	return (ptr_dup);
}

void	destructor(t_stock_str *ptr, int ac)
{
	int	i;

	i = -1;
	while (++i < ac && ptr)
	{
		free(ptr[i].copy);
		ptr[i].copy = 0;
	}
	free(ptr);
	ptr = 0;
}

void	constructor(t_stock_str *ptr, int size, char *str, char *copy)
{
	ptr->size = size;
	ptr->str = str;
	ptr->copy = copy;
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*ptr;
	int			i;

	i = -1;
	if (ac <= 0)
		return (0);
	ptr = (t_stock_str *)malloc((ac + 1) * sizeof(t_stock_str));
	if (ptr == 0 || av == 0)
		return (0);
	ptr[ac].str = 0;
	while (++i < ac)
	{
		if (av[i] == 0)
		{
			destructor(ptr, ac + 1);
			return (0);
		}
		constructor(&ptr[i], ft_strlen(av[i]), av[i], ft_strdup(av[i]));
		if (ptr[i].copy == 0)
		{
			destructor(ptr, ac + 1);
			return (0);
		}
	}
	return (ptr);
}

// int main(){
// 	char *x[] = {"asdf",'\0',"qweasd"};
// 	t_stock_str *temp = ft_strs_to_tab(3,x);
// 	destructor(temp,3+1);
// }