/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atay <atay@42kl.edu.my>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 19:28:09 by atay              #+#    #+#             */
/*   Updated: 2023/09/26 19:28:10 by atay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int binary_guess(int nb, int upper, int lower)
{
	int mid;
	
	mid = (int)((upper - lower)/2 + lower);
	if(upper > lower + 1)
	{
		if( nb%mid == 0 && nb/mid == mid)
			return mid;
		else if((nb/mid) < mid)
			mid = binary_guess(nb,mid,lower);
		else if((nb/mid) >= mid)
			mid = binary_guess(nb,upper,mid);
	}
	else
		return upper;
	return mid;
}

int	ft_sqrt(int nb)
{
	if(nb<10)
		return nb/2;
	return binary_guess(nb,nb,0);
}

int	ft_is_prime(int nb)
{
	int	i;
	int upper;

	upper = ft_sqrt(nb);
	if (nb < 2)
		return (0);
	i = 2;
	while (i <= upper)
	{
		if (nb % i == 0)
			return (0);
		i++;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	while (ft_is_prime(nb) != 1)
		nb++;
	return (nb);
}

// #include <stdio.h>
// int main (){
// 	printf("%d, ",ft_find_next_prime(0));
// 	printf("%d, ",ft_find_next_prime(3));
// 	printf("%d, ",ft_find_next_prime(4));
// 	printf("%d, ",ft_find_next_prime(103));
// 	printf("%d, ",ft_find_next_prime(104));
// }