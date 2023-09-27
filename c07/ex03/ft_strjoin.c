#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	count;

	count = 0;
	while (*str++)
		count++;
	return (count);
}

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	length;

	i = 0;
	while (i < (size - 1) && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	length = i;
	while (i < size)
	{
		dest[i] = '\0';
		i++;
	}
	dest[size - 1] = '\0';
	return (length);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*ptr;
	int		i;
	int		length;
	int		length2;

	if (size == 0)
		return (malloc(0));
	i = -1;
	length = 0;
	while (++i < size)
		length += ft_strlen(strs[i]);
	length = length + ft_strlen(sep) * (size - 1) + 1;
	ptr = malloc((length) * sizeof(char));
	i = -1;
	length2 = 0;
	while (++i < (size - 1))
	{
		length2 += ft_strlcpy(ptr + length2, strs[i], length);
		length2 += ft_strlcpy(ptr + length2, sep, length);
	}
	length2 += ft_strlcpy(ptr + length2, strs[i], length);
	ptr[length - 1] = '\0';
	return (ptr);
}
