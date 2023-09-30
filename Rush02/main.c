#include <unistd.h>

void    my_print_string(char *str)
{
    int count;
    char *ptr;
    
    ptr = str;
    count = 0;
    while (*ptr)
    {
        count++;
        ptr++;
    }
    write(1,str,count);
}

int isWhitespace(char chr)
{
    if((chr !='\n' && chr>=9 && chr<=13) || chr == ' '){
        return 1;
    }
    return 0;
}

int dict_init(char *data, char **dict){
    int size_below_hundred;
    size_below_hundred = 0;
    int i = 0;
    while(data[i])
    {
        while(isWhitespace(*data))
            data++;
        
        if(data == ':')

        i++;
    }

    return size_below_hundred;
}

char *dictionary(char **dict, int num, int num_zeros)
{
    if(num_zeros == 0)
        return dict[num];
    if()
}

int break_down(unsigned long long nbr, int size){
    
}

int convert(char *map){

}

int main(int argc,char *argv[]){
    if(argc >3 || argc <2)
        my_print_string("Error");
    return 0;
}