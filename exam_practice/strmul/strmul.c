#include "str.h"
#include "stdlib.h"
#include "unistd.h"
#include "stdio.h"


int main (int argc, char *argv[])
{
	if(sizeof(unsigned long long) == 1 || argc != 3)
		return -1;

	//the maximum num of digit of multiplication is the sum of num of two digit.
	//eg. 99*9 = 891, which is 2 digit + 1 digit = 3 digit.
	if(sizeof(unsigned long long) * 0.5 < sizeof(unsigned int))
		MAX_UINT_DIGIT = (unsigned int)(sizeof(unsigned long long)*8*0.3*0.5);
	else
		MAX_UINT_DIGIT = (unsigned int)(sizeof(unsigned int)*8*0.3);
	MAX_UINT_LIMIT = ft_recursive_power(10,MAX_UINT_DIGIT);

	//remember to block for input, like not integer case.	
	//remember to free the memory as well once end the program.
	unsigned int *ptr;
	unsigned int *ptr2;
	unsigned int *output;
	char *str_output;
	int size_a = ft_atoi_sp(argv[1],&ptr);
	int size_b = ft_atoi_sp(argv[2],&ptr2);
	int size_c = hex_mul(ptr,size_a,ptr2,size_b,&output);
	str_output = ft_itoa_sp(output,size_c);
	printf("%s\n",str_output);

	return 0;
}
