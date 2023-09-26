/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atay <atay@42kl.edu.my>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 20:14:16 by atay              #+#    #+#             */
/*   Updated: 2023/09/26 20:14:17 by atay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	count;

	count = 0;
	while (*str++)
		count++;
	return (count);
}

char	*ft_strdup(char *src)
{
	int		i;
	int		size;
	char	*ptr_dup;

	i = -1;
	size = ft_strlen(src) + 1;
	ptr_dup = (char *)malloc(size * sizeof(char));
	while (src[++i])
	{
		ptr_dup[i] = src[i];
	}
	ptr_dup[size - 1] = '\0';
	return (ptr_dup);
}
