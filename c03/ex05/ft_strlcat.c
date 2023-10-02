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

	i = ft_strlen(dest);
	ptr = &dest[i];
	size2 = i + ft_strlen(src);
	if(size < i)
		return (size + ft_strlen(src));
	i = 0;
	while (*src && ++i < (size-1))
	{
		*ptr++ = *src++;
	}
	*ptr = '\0';
	return (size2);
}