#include "../include/ft_rush.h"

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

void	blockofoutput(char *nbr, int size, t_dict **dict, int prt_whtsp)
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
				get_word_by_map(dict[nbr[i] - '0'], 1);
				get_word_by_map(dict[30], 1);
			}
			else if (rev_i == 2 && nbr[i] > '1')
				get_word_by_map(dict[(nbr[i] - '0') + 20], 1);
			else if (rev_i == 2 && nbr[i++] == '1')
				get_word_by_map(dict[10 + (nbr[i] - '0')], prt_whtsp);
			else
				get_word_by_map(dict[nbr[i] - '0'], prt_whtsp);
		}
	}
}

void	print_text(char *nbr, int size, t_dict **dict)
{
	int	i;
	int	rev_i;
	int	offset;

	if (nbr[0] == '0' && size == 1)
	{
		get_word_by_map(dict[0], 1);
		return ;
	}
	i = 0;
	while (i < size)
	{
		while (nbr[i] && is_zero(&nbr[i], 3))
			i += 3;
		rev_i = size - i;
		offset = rev_i % 3 + (rev_i % 3 == 0) * 3;
		if (rev_i > 3)
		{
			blockofoutput(&nbr[i], offset, dict, 1);
			get_word_by_map(dict[30 + rev_i - offset], 1);
		}
		else
			blockofoutput(&nbr[i], offset, dict, 0);
		i += offset;
	}
}
