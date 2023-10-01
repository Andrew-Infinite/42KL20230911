/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush-02.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zliow <zliow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 16:05:25 by zliow             #+#    #+#             */
/*   Updated: 2023/10/01 16:05:27 by zliow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_rush.h"

int	main(int argc, char *argv[])
{
	t_dict	**dict;

	if (!valid_input(argc, argv))
	{	
		print_error_message();
		return (1);
	}
	else
	{	
		if (argc == 3)
		{
			dict = get_dict(argv[1]);
			if (dict == NULL)
				return (1);
			print_text(argv[2], ft_strlen(argv[2]), dict);
		}
		else
		{
			dict = get_dict("numbers.dict");
			print_text(argv[1], ft_strlen(argv[1]), dict);
		}
		ft_deconstructor(dict);
	}
	return (0);
}
