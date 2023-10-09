#include <stdlib.h>
#include "my_string.h" 

int	map_init(char *charset, char *map, int map_size)
{
	int	count;

	count = -1;
	while (++count < map_size)
		map[count] = -1;
	map[0] = 0;
	if (charset == 0 || *charset == '\0')
		return (0);
	count = -1;
	while (charset[++count])
		map[(int)charset[count]] = count + 1;
	return (count);
}

char	*ft_strdup(char *src, int size)
{
	int		i;
	char	*ptr_dup;

	i = -1;
	ptr_dup = (char *)malloc((size + 1) * sizeof(char));
	while (src[++i] && i < size)
	{
		ptr_dup[i] = src[i];
	}
	ptr_dup[size] = '\0';
	return (ptr_dup);
}

int	ft_word_count(char *str, char *map, char **ptr)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (map[(int)*str] > 0)
		str++;
	while (*str)
	{
		if (map[(int)str[i]] >= 0)
		{
			if (ptr != 0)
				ptr[count] = ft_strdup(str, i);
			while (map[(int)str[i]] > 0)
				i++;
			str = str + i;
			i = 0;
			count++;
		}
		else
			i++;
	}
	return (count);
}

void	destructor_ft_split(char **ptr)
{
	int	i;

	i = -1;
	while (ptr[++i])
	{
		free(ptr[i]);
		ptr[i] = 0;
	}
	free(ptr);
	ptr = 0;
}

char	**ft_split(char *str, char *charset)
{
	int		size;
	char	**ptr;
	char	map[256];

	if (map_init(charset, map, 256) > 0)
		size = ft_word_count(str, map, 0);
	else
		size = 1;
	ptr = (char **)malloc((size + 1) * sizeof(char *));
	ft_word_count(str, map, ptr);
	ptr[size] = 0;
	return (ptr);
}