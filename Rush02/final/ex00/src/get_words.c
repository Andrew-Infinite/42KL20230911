/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_words.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zliow <zliow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 15:58:08 by zliow             #+#    #+#             */
/*   Updated: 2023/10/01 15:58:28 by zliow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_rush.h"

void	get_word_by_map(t_dict *dict, int i)
{
	ft_putstr(dict->value);
	if (i == 1)
	{
		write(1, " ", 1);
	}
}

int	size_with_error(char *str)
{
	int	i;
	int	size;

	size = 0;
	while (str[size] && str[size] != ':')
		size++;
	while (is_whitespace(str[size - 1]))
		size--;
	i = -1;
	while (++i < size)
	{
		if (str[i] < '0' || str[i] > '9')
			return (-1);
	}
	return (size);
}

int	is_whitespace(char str)
{
	if (str == ' ' || str == 9 || (str >= 11 && str <= 13))
		return (1);
	return (0);
}

int	num_to_index(char *str)
{
	int	size;

	while (is_whitespace(*str))
		str++;
	size = size_with_error(str);
	if (size <= 0)
		return (-1);
	if (size >= 4)
		return (30 + size - 1);
	if (size == 3)
		return (30);
	if (size == 2 && str[0] > '1')
		return (20 + str[0] - '0');
	if (size == 2)
		return (10 + str[1] - '0');
	return (str[0] - '0');
}
