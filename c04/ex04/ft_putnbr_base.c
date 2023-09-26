/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atay <atay@42kl.edu.my>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 16:14:16 by atay              #+#    #+#             */
/*   Updated: 2023/09/26 16:14:26 by atay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	is_sign(char str)
{
	if (str == '+' || str == '-')
	{
		return (1);
	}
	return (0);
}

int	map_init(char *base, int *map, int map_size)
{
	int	count;

	if (base == 0 || *base == '\0')
		return (0);
	count = -1;
	while (++count < map_size)
		map[count] = -1;
	count = -1;
	while (base[++count])
	{
		if (is_sign(base[count]) || map[(int)base[count]] > -1)
			return (0);
		map[(int)base[count]] = count;
	}
	return (count);
}

void	recurse_base(long nbr, char *base, int size)
{
	if (nbr / size > 0)
		recurse_base(nbr / size, base, size);
	write(1, &base[nbr % size], 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	long	num;
	int		size;
	int		map[256];

	num = (long)nbr;
	size = map_init(base, map, 256);
	if (size <= 1)
		return ;
	if (size && nbr < 0)
	{
		write(1, "-", 1);
		num = -num;
	}
	recurse_base(num, base, size);
}
