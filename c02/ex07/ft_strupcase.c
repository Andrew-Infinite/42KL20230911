char *ft_strupcase(char *str)
{
    char *ptr;
    
    ptr = str;
    while(*ptr)
    {
        
        if(*ptr>='a'&&*ptr<='z')
        {
            *ptr = *ptr +'A' - 'a';
        }
        ptr++;
    }
    return str;
}
