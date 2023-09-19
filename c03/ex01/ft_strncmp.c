int ft_strncmp(char *s1, char *s2, unsigned int n)
{
    int i;
    
    i=-1;
    while( ++i<n && *s1 || *s2)
    {
        if(*s1>*s2)
            return -1;
        else if(*s1<*s2)
            return 1;
        s1++;
        s2++;
    }
    return 0;
}
