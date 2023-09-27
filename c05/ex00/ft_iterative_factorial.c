/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atay <atay@42kl.edu.my>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 19:26:55 by atay              #+#    #+#             */
/*   Updated: 2023/09/26 19:26:57 by atay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	i;
	int	fac;

	if (nb < 0)
		return (0);
	i = 0;
	fac = 1;
	while (++i <= nb)
		fac = fac * i;
	return (fac);
}

// #include <stdio.h>
// int main (){
// 	printf("%d \n",ft_iterative_factorial(-4));
// 	printf("%d \n",ft_iterative_factorial(-1));
// 	printf("%d \n",ft_iterative_factorial(0));
// 	printf("%d \n",ft_iterative_factorial(5));
// 	printf("%d \n",ft_iterative_factorial(8));
// }