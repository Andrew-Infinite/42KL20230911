/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atay <atay@42kl.edu.my>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 20:14:28 by atay              #+#    #+#             */
/*   Updated: 2023/09/26 20:14:30 by atay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	*ft_range(int min, int max)
{
	int	i;
	int	*ptr_num;

	i = 0;
	if ((max - min) <= 0)
		return (0);
	ptr_num = (int *)malloc((max - min) * sizeof(int));
	while (min < max)
		ptr_num[i++] = min++;
	return (ptr_num);
}
