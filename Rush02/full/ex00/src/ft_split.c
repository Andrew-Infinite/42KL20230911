/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honglim <honglim@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 15:44:43 by honglim           #+#    #+#             */
/*   Updated: 2023/10/01 15:45:07 by honglim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_rush.h"

int	is_sep(char c, char *charset)
{
	int	i;

	i = 0;
	if (c == '\0')
		return (1);
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

int	count_strings(char *str, char *charset)
{	
	int	i;
	int	string_count;

	i = 0;
	string_count = 0;
	while (str[i])
	{
		if (!is_sep(str[i], charset)
			&& is_sep(str[i + 1], charset))
			string_count++;
		i++;
	}
	return (string_count);
}

void	copy_string(char *dest, char *src, char *charset)
{
	int	i;

	i = 0;
	while (!is_sep(src[i], charset))
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

void	split_strings(char **arrays, char *str, char *charset)
{
	int	i;
	int	j;
	int	pos;

	i = 0;
	pos = 0;
	while (str[i])
	{
		if (is_sep(str[i], charset))
		{
			i++;
		}
		else
		{	
			j = 0;
			while (!is_sep(str[i + j], charset))
				j++;
			arrays[pos] = (char *)malloc(sizeof(char) * (j + 1));
			copy_string(arrays[pos], str + i, charset);
			i += j;
			pos++;
		}
	}
}

char	**ft_split(char *str, char *charset)
{	
	char	**arrays;
	int		string_count;

	string_count = count_strings(str, charset);
	arrays = (char **)malloc(sizeof(char *) * string_count + 1);
	arrays[string_count] = 0;
	split_strings(arrays, str, charset);
	return (arrays);
}
