/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atay <atay@42kl.edu.my>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 08:19:49 by atay              #+#    #+#             */
/*   Updated: 2023/09/21 08:19:49 by atay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_str_is_printable(char *str)
{
    while(*str)
    {
        if(*str<32 || *str>126)
        {
            return 0;
        }
        str++;
    }
    return 1;
}
