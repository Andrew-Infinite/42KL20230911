#include <unistd.h>

int	ft_strlen(char *str)
{
	int		count;
	char	*ptr;

	ptr = str;
	count = 0;
	while (*ptr)
	{
		count++;
		ptr++;
	}
	return (count);
}

int	is_zero(char *chr, int len)
{
	while (--len >= 0)
	{
		if (chr[len] != '0')
			return (0);
	}
	return (1);
}

// hundred -> 1 ~ 9, tens -> 2 ~ 9, ones -> 1 ~ 9,
void	blockofoutput(char *nbr, int size, char **map)
{
	int	i;
	int	rev_i;

	i = -1;
	while (nbr[++i] && i < size)
	{
		if (nbr[i] > '0' && nbr[i] <= '9')
		{
			rev_i = size - i;
			if (rev_i == 3)
			{
                //rev_i == 3 -> 3 digit
                //map[nbr[i]-'0'], if map['9'-'0'] -> write(1,"nine",4)
				write(1, map[nbr[i] - '0'], ft_strlen(map[nbr[i] - '0']));
				write(1, " ", 1);
                //map[30] is "hundred"
				write(1, map[30], ft_strlen(map[30]));
			}
			else if (rev_i == 2 && nbr[i] > '1')
                //rev_i == 2 -> 2 digit, but only those which is >= 20
                //map[2+20] -> "twenty", map[3+20] -> "thirty"
				write(1, map[(nbr[i] - '0') + 20], ft_strlen(map[(nbr[i] - '0') + 20]));
			else if (rev_i == 2 && nbr[i++] == '1')
                //rev_i == 2 -> 2 digit, but <=19 (actually no need check for '1', but I need the i++ xDDDDD)
                //map[10 + ('5'-'0')] -> fifteen
				write(1, map[10 + (nbr[i] - '0')], ft_strlen(map[10 + (nbr[i] - '0')]));
			else
                //rev_i == 1 -> 1 digits
                //map['4'-'0'] -> "four"
				write(1, map[nbr[i] - '0'], ft_strlen(map[nbr[i] - '0']));
			write(1, " ", 1);
		}
	}
}

void	print_text(char *nbr, int size, char **map)
{
	int	i;
	int	rev_i;
	int	offset;

	if (nbr[0] == '0' && size == 1)
	{
		write(1, map[0], ft_strlen(map[0]));
		return ;
	}
	i = 0;
	while (i < size)
	{
        //if there is block of zero, eg 1 000 121, skip the 000
		while (nbr[i] && is_zero(&nbr[i], 3))
			i += 3;
		rev_i = size - i;
        //rev_i a.k.a. reverse_i, represent number of digit counting from the least significant
        //offset would be usual 3, except for the leading digit.
        //eg: 15 321, then first offset would be 2.
        //there is 7 digits, offset = 5 % 3 + (5 % 3 == 0) * 3 = (2 + 0 * 3) = 2
        //the (rev_i % 3 == 0) *3, is for when rev_i is diversable by 3
        //eg: 231, 3 digits, offset = 3 % 3 + (3 % 3 == 0) * 3 = (0 + 1 * 3) = 3
		offset = rev_i % 3 + (rev_i % 3 == 0) * 3;
		blockofoutput(&nbr[i], offset, map);
		if (rev_i > 3)
		{
            //if there more than 3 digits, I have to print the postfix, like ("thousand","million"...)
            //eg: 5 212,      rev_i = 4, offset = 1, map[30 + 3] -> "thousand"
            //eg: 23 123 423, rev_i = 8, offset = 2, map[30 + 6] -> "million"
			write(1, map[30 + rev_i - offset], ft_strlen(map[30 + rev_i - offset]));
			write(1, " ", 1);
		}
		i += offset;
	}
}

int is_whitespace(char str)
{
	if(str == ' ' || str == 9 || (str >= 11 && str <= 13))
		return 1;
	return 0;
}

int size_with_error(char *str, char *delimit)
{
	int i;
	int size;

	size = 0;
	while(str[size] && str[size] != ':')
		size++;
	while(is_whitespace(str[size-1]))
		size--;

	i = -1;
	while(++i<size)
	{
		if(str[i]<'0' || str[i]>'9')
			return (-1);
	}
	return size;
}

int num_to_index(char *str, char *delimit)
{
	int size;
	
	while(is_whitespace(*str))
		str++;
	while(*str == '0')
		str++;
	size = size_with_error(str,delimit);
	if(size <= 0)
		return (-1);
	if(size >= 4)
		return 30 + size - 1;
	if(size == 3)
		return 30;
	if(size == 2 && str[0] > '1')
		return 20 + str[0] - '0';
	if(size == 2)
		return 10 + str[1] - '0';
	return str[0] - '0';
}

#include <stdio.h>
int	main(int argc, char *argv[])
{
	char *map[1001] = {"zero", "one", "two", "three", "four", "five", "six",
		"seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen",
		"fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
	map[22] = "twenty";
	map[23] = "thirty";
	map[24] = "forty";
	map[25] = "fifty";
	map[26] = "sixty";
	map[27] = "seventy";
	map[28] = "eighty";
	map[29] = "ninety";
	map[30] = "hundred";
	map[30 + 3] = "thousand";
	map[30 + 6] = "million";
	map[30 + 9] = "billion";
	map[30 + 12] = "trillion";
	map[30 + 15] = "quadrillion";
	map[30 + 18] = "quintillion";
	map[30 + 21] = "sextillion";
	map[30 + 24] = "septillion";
	map[30 + 27] = "octillion";
	map[30 + 30] = "nonillion";
	map[30 + 33] = "decillion";
	map[30 + 36] = "undecillion";

	char *ptr = "1231231279472356";
	//print_text(ptr, ft_strlen(ptr), map);
	printf("%d",num_to_index("   000100   ", ":"));
}