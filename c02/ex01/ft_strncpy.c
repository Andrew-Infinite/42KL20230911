char *ft_strncpy(char *dest, char *src, unsigned int n)
{
    int i;
    
    i=-1;
    while(++i<n && src[i])
        dest[i] = src[i];
	while(dest[i]!='\0')
	{	
		dest[i] = '\0';
		i++;
	}
    return dest;
}

