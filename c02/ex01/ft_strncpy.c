char *ft_strncpy(char *dest, char *src, unsigned int n)
{
    int i;

    i=-1;
    while(++i< && src[i])
        dest[i] = src[i];
    while(++i<n)
        dest[i] = '\0';
    dest[n-1] = '\0';
    return dest;
}
