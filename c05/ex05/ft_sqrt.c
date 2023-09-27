/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atay <atay@42kl.edu.my>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 19:27:38 by atay              #+#    #+#             */
/*   Updated: 2023/09/26 19:27:39 by atay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	i;

	i = 1;
	while (i * i < nb)
		i++;
	if (i * i == nb)
		return (i);
	return (0);
}

// #include <stdio.h>
// int main (){
// 	printf("%d \n",ft_sqrt(200));
// 	printf("%d \n",ft_sqrt(400));
// 	printf("%d \n",ft_sqrt(0));
// 	printf("%d \n",ft_sqrt(10));
// 	printf("%d \n",ft_sqrt(49));
// 	printf("%d \n",ft_sqrt(-100));
// }