/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atay <atay@42kl.edu.my>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 20:14:40 by atay              #+#    #+#             */
/*   Updated: 2023/09/26 20:17:32 by atay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_ultimate_range(int **range, int min, int max)
{
	int	count;
	int	*ptr_num;

	count = 0;
	if ((max - min) <= 0)
	{
		*range = 0;
		return (-1);
	}
	ptr_num = (int *)malloc((max - min) * sizeof(int));
	while (min < max)
		ptr_num[count++] = min++;
	*range = ptr_num;
	return (count);
}
