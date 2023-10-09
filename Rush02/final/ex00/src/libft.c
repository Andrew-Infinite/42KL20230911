/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zliow <zliow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 15:58:45 by zliow             #+#    #+#             */
/*   Updated: 2023/10/01 15:59:12 by zliow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_rush.h"

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

char	*ft_strncpy(char *dest, char *src, int size)
{
	int	i;

	i = 0;
	while (src[i] && i < size)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strndup(char *src, int size)
{
	int		length;
	char	*dest;

	length = ft_strlen(src);
	dest = (char *)malloc(length + 1);
	ft_strncpy(dest, src, size);
	return (dest);
}

void	ft_deconstructor(t_dict **dict)
{
	int	i;

	i = 0;
	while (dict[i] != NULL)
	{
		free(dict[i]);
		i++;
	}
	free(dict);
}
