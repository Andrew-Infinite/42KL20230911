/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atay <atay@42kl.edu.my>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 10:13:28 by atay              #+#    #+#             */
/*   Updated: 2023/09/20 10:34:12 by atay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	number_printer2(int a, int b)
{
	char	data[2];

	data[0] = '0' + a / 10;
	data[1] = '0' + a % 10;
	write(1, &data, 2);
	data[0] = ',';
	data[1] = ' ';
	write(1, &data[1], 1);
	data[0] = '0' + b / 10;
	data[1] = '0' + b % 10;
	write(1, &data, 2);
	if (!(a == 98 && b == 99))
	{
		data[0] = ',';
		data[1] = ' ';
		write(1, &data, 2);
	}
}

void	ft_print_comb2(void)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (i <= 98)
	{
		while (j <= 99)
		{
			number_printer2(i, j);
			j++;
		}
		i++;
		j = i + 1;
	}
}
