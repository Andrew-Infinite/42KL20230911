#include <unistd.h>
void brainfck(char *raw_str, char *str)
{
    while(*raw_str)
    {
        if(*raw_str == '>')
        {
            str++;
        }else if (*raw_str == '<')
        {
            str--;
        }else if(*raw_str == '+')
        {
            str[0]++;
        }
        else if(*raw_str == '-')
        {
            str[0]--;
        }
        else if(*raw_str == '[' && *str == 0)
        {
            int sum = 1;
            raw_str++;
            while(sum != 0)
            {
                if(*raw_str == '[')
                    sum++;
                else if (*raw_str == ']')
                {
                    sum--;
                }
                raw_str++;
            }
        }else if(*raw_str == ']' && *str != 0)
        {
            int sum = 1;
            raw_str--;
            while(sum != 0)
            {
                if(*raw_str == '[')
                    sum--;
                else if (*raw_str == ']')
                {
                    sum++;
                }
                raw_str--;
            }
        }
        else if(*raw_str == '.')
        {
            write(1,str,1);
        }
        
        raw_str++;
    }
}

int main(int argc, char *argv[])
{
    char arr[2048] = {0};
    char *ptr = argv[1];
    brainfck(ptr,arr);
    return 0;
}