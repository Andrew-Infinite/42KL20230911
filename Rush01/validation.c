/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_validity.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zliow <zliow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 18:36:54 by zliow             #+#    #+#             */
/*   Updated: 2023/09/24 18:44:50 by zliow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	valid_check_left(int *map, int constraint, int y, int size)
{
	int	i;
	int	count;
	int	max;

	i = -1;
	count = 0;
	max = 0;
	while (++i < size)
	{
		if (max < map[index2Dto1D(i, y, size)])
		{
			max = map[index2Dto1D(i, y, size)];
			count++;
		}
		if (count > constraint)
		{
			return (0);
		}
	}
	return (1);
}

int	valid_check_right(int *map, int constraint, int y, int size)
{
	int	i;
	int	count;
	int	max;

	i = size;
	count = 0;
	max = 0;
	while (--i >= 0)
	{
		if (max < map[index2Dto1D(i, y, size)])
		{
			max = map[index2Dto1D(i, y, size)];
			count++;
		}
		if (count > constraint)
		{
			return (0);
		}
	}
	return (1);
}

int	valid_check_up(int *map, int constraint, int x, int size)
{
	int	j;
	int	count;
	int	max;

	j = -1;
	count = 0;
	max = 0;
	while (++j < size)
	{
		if (max < map[index2Dto1D(x, j, size)])
		{
			max = map[index2Dto1D(x, j, size)];
			count++;
		}
		if (count > constraint)
		{
			return (0);
		}
	}
	return (1);
}

int	valid_check_bottom(int *map, int constraint, int x, int size)
{
	int	j;
	int	count;
	int	max;

	j = size;
	count = 0;
	max = 0;
	while (--j >= 0)
	{
		if (max < map[index2Dto1D(x, j, size)])
		{
			max = map[index2Dto1D(x, j, size)];
			count++;
		}
		if (count > constraint)
		{
			return (0);
		}
	}
	return (1);
}

int	valid_down(int *map, int x, int size, int height)
{
	int j;

	j = -1;
	while (++j < size)
	{
		if (map[index2Dto1D(x, j, size)] == height)
		{
			return (0);
		}
	}
	return (1);
}