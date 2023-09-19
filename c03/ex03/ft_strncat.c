//check for the def
char *ft_strncat(char *dest, char *src, unsigned int nb)
{
    char *ptr;
    int i;
    
    i=-1;
    ptr = dest;
    while(*ptr)
        ptr++;
    while(*src&&++i<nb)
    {
        *ptr++ = *src++;
    }
    ptr = '\0';
    
    return dest;
}
