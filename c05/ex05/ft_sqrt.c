/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atay <atay@42kl.edu.my>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 19:27:38 by atay              #+#    #+#             */
/*   Updated: 2023/09/26 19:27:39 by atay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	binary_guess(int nb, int upper, int lower)
{
	int	mid;

	mid = (int)((upper - lower) / 2 + lower);
	if (upper > lower + 1)
	{
		if (nb % mid == 0 && nb / mid == mid)
			return (mid);
		else if ((nb / mid) < mid)
			mid = binary_guess(nb, mid, lower);
		else if ((nb / mid) >= mid)
			mid = binary_guess(nb, upper, mid);
	}
	else
		return (0);
	return (mid);
}

int	ft_sqrt(int nb)
{
	if (nb < 4 && nb != 1)
		return (0);
	if (nb == 1)
		return (1);
	return (binary_guess(nb, nb, 0));
}

/*#include <stdio.h>

int	main(void)
{
	int j = 1;
	for (int i = 0; i < 2147483647; i++)
	{
		int temp = ft_sqrt(i);
		if (temp > 0)
		{
			if ((i % temp != 0 || i / temp != temp))
			{
				printf("%d %d %d\n", temp, i, j);
			}
		}
	}
}*/
