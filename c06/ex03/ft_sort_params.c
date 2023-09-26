/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atay <atay@42kl.edu.my>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 20:13:45 by atay              #+#    #+#             */
/*   Updated: 2023/09/26 20:13:46 by atay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strcmp(char *str, char *str2)
{
	while (*str || *str2)
	{
		if (*str != *str2)
			return ((int)(*str - *str2));
		str++;
		str2++;
	}
	return (0);
}

void	ft_str_sort(char **argv, int argc)
{
	int		i;
	int		end;
	char	*temp;

	end = argc;
	while (--end > 0)
	{
		i = 0;
		while (++i <= end)
		{
			if (ft_strcmp(argv[i - 1], argv[i]) > 0)
			{
				temp = argv[i - 1];
				argv[i - 1] = argv[i];
				argv[i] = temp;
			}
		}
	}
}

int	ft_strlen(char *str)
{
	int	count;

	count = 0;
	while (*str++)
		count++;
	return (count);
}

int	main(int argc, char *argv[])
{
	int	i;

	i = 0;
	ft_str_sort(argv, argc);
	while (++i < argc)
	{
		write(1, argv[i], ft_strlen(argv[i]));
		write(1, "\n", 1);
	}
	return (0);
}
