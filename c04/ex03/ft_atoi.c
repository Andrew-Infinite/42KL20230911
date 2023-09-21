/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atay <atay@42kl.edu.my>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 08:25:27 by atay              #+#    #+#             */
/*   Updated: 2023/09/21 08:25:29 by atay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_sign(char str)
{
	if (str == '+' || str == '-')
	{
		return (1);
	}
	return (0);
}

int	is_number(char str)
{
	if (str < '0' || str > '9')
	{
		return (0);
	}
	return (1);
}

int	ft_atoi(char *str)
{
	long	temp;
	int		sign;

	sign = 1;
	temp = 0;
	while (*str == ' ')
		str++;
	while (is_sign(*str))
	{
		if (*str == '-')
			sign = -sign;
		str++;
	}
	while (is_number(*str))
	{
		temp = temp * 10 + sign * (*str - '0');
		str++;
	}
	return (temp);
}
