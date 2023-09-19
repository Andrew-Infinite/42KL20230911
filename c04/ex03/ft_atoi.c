//NOT DONE
int isSign(char *str)
{
    if(*str == '+' || *str == '-')
    {
        return 1;
    }
    return 0;
}

int isNumber(char *str)
{
    if(*str<'0'||*str>'9')
    {
        return 0;
    }
    return 1;
}
int str_to_int(char *str, int start, int end, int sign)
{
    int temp;
    
    temp = 0;
    while(start<end)
    {
        temp = temp*10 + sign*(str[start]-'0');
        start++;
    }
    return temp;
}
int ft_atoi(char *str)
{
    int temp;
    int sign = 1;
    while(*str)
    {
        if(!isSign(*str) && !isNumber(*str))
            sign = 1;
        else if(*str == '-')
            sign=-sign;
        str++;
    }
}
