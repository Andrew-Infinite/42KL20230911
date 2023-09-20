/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_negative.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atay <atay@42kl.edu.my>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 12:35:37 by atay              #+#    #+#             */
/*   Updated: 2023/09/20 09:26:57 by atay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_is_negative(int n)
{
	char	x;

	if (n < 0)
	{
		x = 'N';
	}
	else
	{
		x = 'P';
	}
	write(1, &x, 1);
}

int main(){
	ft_is_negative(1);
	return 0;
}
