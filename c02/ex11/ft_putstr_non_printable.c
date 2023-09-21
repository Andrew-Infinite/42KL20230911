/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atay <atay@42kl.edu.my>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 08:21:33 by atay              #+#    #+#             */
/*   Updated: 2023/09/21 08:21:35 by atay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	is_printable(char *str)
{
	if (*str < 32 || *str > 126)
	{
		return (0);
	}
	return (1);
}

void	num_to_hex(char num, char *hex_string)
{
	char	upper;
	char	lower;

	upper = ((num & 0xF0) >> 4);
	lower = (num & 0x0F);
	if (upper > 9)
		hex_string[1] = upper - 10 + 'a';
	else
		hex_string[1] = upper + '0';
	if (lower > 9)
		hex_string[2] = lower - 10 + 'a';
	else
		hex_string[2] = lower + '0';
}

void	ft_putstr_non_printable(char *str)
{
	char	buffer[4];

	buffer[0] = '\\';
	while (*str)
	{
		if (!is_printable(str))
		{
			num_to_hex(*str, buffer);
			write(1, buffer, 3);
		}
		else
			write(1, str, 1);
		str++;
	}
}
