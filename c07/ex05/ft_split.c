#include <stdio.h>
#include <stdlib.h>
int	map_init(char *charset, char *map, int map_size)
{
	int	count;

	if (charset == 0 || *charset == '\0')
		return (0);
	count = -1;
	while (++count < map_size)
		map[count] = -1;
	count = -1;
	while (charset[++count])
		map[(int)charset[count]] = count+1;
    map[0] = 0;
	return (count);
}

char	*ft_strdup(char *src, char size)
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

int ft_word_count(char *str, char *charset, char **ptr)
{
    int count;
    int i;
    char map[256];
    
    count = 0;
    i = 0;
    if (map_init(charset,map,256) == 0)
        return 1;
    while(map[*str]>0)
        str++;
    while(*str)
    {
        if (map[str[i]] >= 0)
        {
            if(ptr != 0)
                ptr[count] = ft_strdup(str, i);
            while(map[str[i]] > 0)
                i++;
            str = str + i;
            i = 0;
            count++;
        }
        else
            i++;
    }
    return count;
}
char **ft_split(char *str, char *charset)
{
    int size;
    char **ptr;
    size = ft_word_count(str,charset,0);

    ptr = (char **) malloc((size+1) * sizeof(char *));
    ft_word_count(str,charset,ptr);
    ptr[size] = 0;
    return ptr;
}

int main(){
    char *x = "asdf  andrew apple idiot aaaaaaAAAAA";
    char **a = ft_split(x," a");
    for(int i = 0;a[i]!=0;i++){
        printf("%s\n",a[i]);
    }
}