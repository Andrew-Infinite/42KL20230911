/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honglim <honglim@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 15:37:19 by honglim           #+#    #+#             */
/*   Updated: 2023/10/01 15:44:24 by honglim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_rush.h"

int	valid_nbr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
		{
			return (0);
		}
		i++;
	}
	return (1);
}

int	valid_dict(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < ' ' || str[i] > 125)
		{
			return (0);
		}
		i++;
	}
	return (1);
}

void	print_error_message(void)
{
	write(1, "Error input\n", 12);
}

int	valid_input(int argc, char **argv)
{
	if (argc == 2 || argc == 3)
	{
		if (argc == 2)
		{
			if (!valid_nbr(argv[1]))
				return (0);
		}
		else if (argc == 3)
		{
			if (!valid_nbr(argv[2]) || !valid_dict(argv[1]))
				return (0);
		}
	}
	else
	{
		return (0);
	}
	return (1);
}
