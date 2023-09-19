char *ft_strncpy(char *dest, char *src, unsigned int n)
{
    int i;
    i=-1;
    while(++i<n)
    {
        dest[i] = src[i];
    }
    dest[n-1]='\0';
    return dest;
}
