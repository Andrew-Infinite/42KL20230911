/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atay <atay@42kl.edu.my>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 10:13:16 by atay              #+#    #+#             */
/*   Updated: 2023/09/20 15:12:48 by atay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	number_printer(int hundreds, int tens, int ones)
{
	char	output[3];
	char	comma[2];

	output[0] = '0' + hundreds;
	output[1] = '0' + tens;
	output[2] = '0' + ones;
	comma[0] = ',';
	comma[1] = ' ';
	write(1, &output, 3);
	if (!(hundreds == 7 && tens == 8 && ones == 9))
	{
		write(1, &comma, 2);
	}
}

void	ft_print_comb(void)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (i <= 7)
	{
		j = i + 1;
		while (j <= 8)
		{
			k = j + 1;
			while (k <= 9)
			{
				number_printer(i, j, k);
				k++;
			}
			j++;
		}
		i++;
	}
}
