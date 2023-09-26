/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atay <atay@42kl.edu.my>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 19:27:14 by atay              #+#    #+#             */
/*   Updated: 2023/09/26 19:27:15 by atay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	i;
	int	num;

	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	i = -1;
	num = 1;
	while (++i < power)
		num = num * nb;
	return (num);
}
