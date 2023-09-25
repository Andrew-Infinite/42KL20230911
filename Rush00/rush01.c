/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atay <atay@42kl.edu.my>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 10:19:16 by atay              #+#    #+#             */
/*   Updated: 2023/09/17 18:40:59 by zgoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);
void	rush(int x, int y);
void	my_rush(int x, int y, char *corner, char *link);

char	char_selector(int *current, int *boundary, char *corner, char *link)
{
	if (current[0] == 0 && current[1] == 0)
	{
		return (corner[0]);
	}
	else if (current[0] == 0 && current[1] == boundary[1])
	{
		return (corner[1]);
	}
	else if (current[0] == boundary[0] && current[1] == 0)
	{
		return (corner[2]);
	}
	else if (current[0] == boundary[0] && current[1] == boundary[1])
	{
		return (corner[3]);
	}
	else if (current[0] == 0 || current[0] == boundary[0])
	{
		return (link[0]);
	}
	else if (current[1] == 0 || current[1] == boundary[1])
	{
		return (link[1]);
	}
	return (' ');
}

void	my_rush(int x, int y, char *corner, char *link)
{
	int		i;
	int		j;
	int		current[2];
	int		boundary[2];
	char	output;

	boundary[0] = x - 1;
	boundary[1] = y - 1;
	i = 0;
	j = 0;
	while (j < y)
	{
		while (i < x)
		{
			current[0] = i;
			current[1] = j;
			output = char_selector(current, boundary, corner, link);
			ft_putchar(output);
			i++;
		}
		i = 0;
		j++;
		ft_putchar('\n');
	}
}

void	rush(int x, int y)
{
	my_rush(x, y, "/\\\\/", "**");
}
