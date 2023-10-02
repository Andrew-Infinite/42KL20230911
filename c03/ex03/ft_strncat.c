/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atay <atay@42kl.edu.my>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 08:23:32 by atay              #+#    #+#             */
/*   Updated: 2023/09/21 08:23:33 by atay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	char			*ptr;
	unsigned int	i;

	if(nb < 1)
		return (dest);
	i = 0;
	ptr = dest;
	while (*ptr)
		ptr++;
	while (*src && i < nb)
	{
		*ptr++ = *src++;
		i++;
	}
	*ptr = '\0';
	return (dest);
}

#include <stdio.h>
int main()
{
	char x[] = "asdf";
	for(int i = 5;i<10;i++){
		x[i] = -1;
	}
	printf("%s ",ft_strncat(x,"123",10));
	for(int i = 0;i<10;i++){
		printf("%d ",x[i]);
	}
	return 0;
}