/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atay <atay@42kl.edu.my>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 08:24:17 by atay              #+#    #+#             */
/*   Updated: 2023/09/21 08:24:19 by atay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int		count;
	char	*ptr;

	ptr = str;
	count = 0;
	while (*ptr)
	{
		count++;
		ptr++;
	}
	return (count);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	char			*ptr;
	unsigned int	i;
	unsigned int	size2;

	i = 0;
	ptr = dest;
	while (*ptr)
	{
		ptr++;
		i++;
	}
	size2  = i + ft_strlen(src);
	while (*src && ++i < size)
	{
		*ptr++ = *src++;
	}
	dest[size-1] = '\0';
	return (size2);
}
