/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atay <atay@42kl.edu.my>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 19:28:01 by atay              #+#    #+#             */
/*   Updated: 2023/09/26 19:28:03 by atay             ###   ########.fr       */
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

#include <stdio.h>
int main (){
	for(int i = 0; i < 200;i++){
		if (ft_is_prime(i)>0)
			printf("%d, ",i);
	}
}