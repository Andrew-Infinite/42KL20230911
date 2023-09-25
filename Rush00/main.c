/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atay <atay@42kl.edu.my>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 11:50:58 by atay              #+#    #+#             */
/*   Updated: 2023/09/17 18:43:23 by zgoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);
void	rush(int x, int y);

void	my_print_string(char *str)
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
	write(1, str, count);
}

int	my_atoi(char *str)
{
	long	number;
	int		count;

	count = 0;
	number = 0;
	while (*str)
	{	
		if (*str < '0' || *str > '9')
		{
			return (-1);
		}
		number *= 10;
		number += (*str - '0');
		str++;
		count++;
		if (count > 10 || number > 2147483647)
		{
			return (-2);
		}
	}
	return (number);
}

int	main(int argc, char *argv[])
{
	int	x;
	int	y;

	if (argc != 3)
	{
		my_print_string("Error, please input exactly two argument. X and Y \n");
		return (-1);
	}
	x = my_atoi(argv[1]);
	y = my_atoi(argv[2]);
	if (x == -1 || y == -1)
	{
		my_print_string("Error, please input only valid numbers.\n");
		return (-1);
	}
	else if (x == -2 || y == -2)
	{
		my_print_string("Error, input exceeded integer limit.\n");
		return (-1);
	}
	rush(x, y);
	return (0);
}
