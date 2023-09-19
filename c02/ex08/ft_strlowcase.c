char *ft_strlowcase(char *str)
{
    char *ptr;
    
    ptr = str;
    while(*ptr)
    {
        
        if(*ptr>='A'&&*ptr<='Z')
        {
            *ptr = *ptr +'a' - 'A';
        }
        ptr++;
    }
    return str;
}
