/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atay <atay@42kl.edu.my>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 19:27:05 by atay              #+#    #+#             */
/*   Updated: 2023/09/26 19:27:07 by atay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_factorial(int nb)
{
	if (nb < 0)
		return (0);
	if (nb == 0)
		return (1);
	return (nb * ft_recursive_factorial(nb - 1));
}

// #include <stdio.h>
// int main (){
// 	printf("%d \n",ft_recursive_factorial(-4));
// 	printf("%d \n",ft_recursive_factorial(-1));
// 	printf("%d \n",ft_recursive_factorial(0));
// 	printf("%d \n",ft_recursive_factorial(5));
// 	printf("%d \n",ft_recursive_factorial(8));
// }