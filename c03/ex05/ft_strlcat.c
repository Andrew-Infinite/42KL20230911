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

unsigned int ft_strlcat(char *dest, char *src, unsigned int size)
{
    char *ptr;
    int i;

    i=0;
    ptr = dest;
    while(*ptr)
    {
        ptr++;
        i++;
    }
    while(*src&& ++i < size)
    {
        *ptr++ = *src++;
    }
    ptr = '\0';

    return i+1;
}
