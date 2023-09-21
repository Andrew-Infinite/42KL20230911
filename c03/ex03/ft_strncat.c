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

// check for the def
char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	char			*ptr;
	unsigned int	i;

	i = 0;
	ptr = dest;
	while (*ptr)
		ptr++;
	ptr[nb] = '\0';
	while (*src && i < nb)
	{
		*ptr++ = *src++;
		i++;
	}
	return (dest);
}
