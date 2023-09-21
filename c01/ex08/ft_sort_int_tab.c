/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atay <atay@42kl.edu.my>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 08:05:34 by atay              #+#    #+#             */
/*   Updated: 2023/09/21 08:05:36 by atay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	end;
	int	temp;

	end = size;
	while (--end > 0)
	{
		i = 0;
		while (++i <= end)
		{
			if (tab[i - 1] > tab[i])
			{
				temp = tab[i - 1];
				tab[i - 1] = tab[i];
				tab[i] = temp;
			}
		}
	}
}
