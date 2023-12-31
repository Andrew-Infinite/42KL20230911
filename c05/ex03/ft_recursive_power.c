/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atay <atay@42kl.edu.my>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 19:27:21 by atay              #+#    #+#             */
/*   Updated: 2023/09/26 19:27:23 by atay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_power(int nb, int power)
{
	int	val;

	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	val = ft_recursive_power(nb, power / 2);
	if ((power % 2) == 1)
		return (val * val * nb);
	else
		return (val * val);
}

// #include <stdio.h>
// int main (){
// 	printf("%d \n",ft_recursive_power(20,-1));
// 	printf("%d \n",ft_recursive_power(0,0));
// 	printf("%d \n",ft_recursive_power(-1,0));
// 	printf("%d \n",ft_recursive_power(50,2));
// 	printf("%d \n",ft_recursive_power(5,3));
// 	printf("%d \n",ft_recursive_power(1,20));
// 	printf("%d \n",ft_recursive_power(-20,3));
// 	printf("%d \n",ft_recursive_power(2,16));
// }