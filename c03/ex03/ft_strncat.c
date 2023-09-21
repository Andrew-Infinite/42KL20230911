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

//check for the def
char *ft_strncat(char *dest, char *src, unsigned int nb)
{
    char *ptr;
    int i;
    
    i=-1;
    ptr = dest;
    while(*ptr)
        ptr++;
    while(*src&&++i<nb)
    {
        *ptr++ = *src++;
    }
    ptr = '\0';
    
    return dest;
}
