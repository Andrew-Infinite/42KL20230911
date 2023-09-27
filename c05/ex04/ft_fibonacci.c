/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atay <atay@42kl.edu.my>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 19:27:30 by atay              #+#    #+#             */
/*   Updated: 2023/09/26 19:27:31 by atay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_fibonacci(int index)
{
	if (index < 0)
		return (-1);
	else if (index < 2)
		return (index);
	return (ft_fibonacci(index - 1) + ft_fibonacci(index - 2));
}

// #include <stdio.h>
// int main (){
// 	printf("%d \n",ft_fibonacci(-200));
// 	printf("%d \n",ft_fibonacci(-1));
// 	printf("%d \n",ft_fibonacci(0));
// 	printf("%d \n",ft_fibonacci(5));
// 	printf("%d \n",ft_fibonacci(8));
// 	printf("%d \n",ft_fibonacci(20));
// }