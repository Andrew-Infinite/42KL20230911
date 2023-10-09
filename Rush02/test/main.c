#include <unistd.h>

void    my_print_string(char *str)
{
    int count;
    char *ptr;
    
    ptr = str;
    count = 0;
    while (*ptr)
    {
        count++;
        ptr++;
    }
    write(1,str,count);
}

int	ft_strlen(char *str)
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
	return (count);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	char			*ptr;
	unsigned int	i;
	unsigned int	size2;

	i = 0;
	ptr = dest;
	while (*ptr)
	{
		ptr++;
		i++;
	}
	size2 = i + ft_strlen(src);
	while (*src && ++i < size)
	{
		*ptr++ = *src++;
	}
	dest[size - 1] = '\0';
	return (size2);
}

int is_not_zero(char *chr, int len)
{
    while(--len >= 0)
    {
        if(chr[len] != '0')
            return 1;
    }
    return 0;
}

char *blockofwords(char *nbr, int size, char *map)
{
    int i;
    char *str_now;
    char *str_prev;

    i = -1;
    while(nbr[++i] && i < size)
    {
        //cat(str,map(nbr[(size)])) //dest, src. if dest '\0', create a malloc with src size;
    }
    return str;
}

char *ft_rev_str(char *tab, int size)
{
	int	i;
	char	temp;

	i = -1;
	while (++i < size / 2)
	{
		temp = tab[i];
		tab[i] = tab[size - i - 1];
		tab[size - i - 1] = temp;
	}
    return tab;
}

//1020323
int break_down(char *nbr_rev, int size, char *map, char *output){
    int i;
    int done;
    char *output;

    i = 0;
    while(++i<=size)//fix
    {
        if(i>3 && i%3 == 1){
            while(nbr_rev[i] && !is_not_zero(nbr_rev[i],3))
                i+=3;
            //output = cat(low nearest to nbr[i],output) //dest,src, malloc done inside, return size;
        }
        //no leading zero, must have output
        //output = cat(blockofwords(&nbr[i],3,map),output)
        i++;
    }
}
//1000212
int main(int argc,char *argv[]){
    if(argc >3 || argc <2)
        my_print_string("Error");
    return 0;
}