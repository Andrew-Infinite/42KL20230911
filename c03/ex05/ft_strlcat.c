/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <string.h>

unsigned int ft_strlcat(char *dest, char *src, unsigned int size)
{
    char *ptr;
    int i;

    i=0;
    ptr = dest;
    while(*ptr)
    {
        ptr++;
        i++;
    }
    while(*src&& ++i < size)
    {
        *ptr++ = *src++;
    }
    ptr = '\0';

    return i+1;
}
int main()
{
    char str[7] = "123";
    char str2[] = "sdf";
    printf("%d \n",ft_strlcat(str,str2,6));
    printf("%s",str);

    return 0;
}

