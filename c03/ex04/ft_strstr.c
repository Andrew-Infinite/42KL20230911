char *ft_strstr(char *str, char *to_find)
{
    int i;
    
    i=-1;
    while(str[++i] && to_find[i])
    {
        if(str[i] != to_find[i])
        {
            i=-1;
            str++;
        }
    }
    
    return str;
}
