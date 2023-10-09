#include <stdlib.h>
#include "../my_string.h"

unsigned int	ft_strlen(char *str)
{
	unsigned int	count;

	count = 0;
	while (str && *str++)
		count++;
	return (count);
}

char *malloc_with_error(unsigned long size)
{
    if(size<UINT_MAX)
    {
        return (char *)malloc(size * sizeof(char));
    }
    return 0;
}

//error, output size overflow, due to unsigned int overflow.
char	*ft_strdupcat(char *dest, char *src)
{
    int     i;
	char    *ptr;
    unsigned int size;

    i = -1;
    size = ft_strlen(dest) + ft_strlen(src) + 1;
    ptr = malloc_with_error(size);
	while (ptr && dest && dest[++i])
        ptr[i] = dest[i];
	while (ptr && src && *src)
		ptr[i++] = *src++;
    if(ptr)
	    ptr[size - 1] = '\0';
	return (ptr);
}

char *blockofwords(char *nbr, int size, char *map)
{
    int i;
    char *str_now;
    char *str_prev;

    i = -1;
    str_now = 0;
    while(nbr[++i] && i < size)
    {
        str_prev = ft_strdupcat("wqab ",str_now);
        free(str_now);
        str_now = str_prev;
    }
    return str_now;
}

// #include <stdio.h>
// int main()
// {
//     char *x = blockofwords("321",3,0);
//     printf("%s \n",x);
//     free(x);
// }