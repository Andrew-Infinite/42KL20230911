/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_dict.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honglim <honglim@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 15:45:24 by honglim           #+#    #+#             */
/*   Updated: 2023/10/01 15:57:38 by zliow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/ft_rush.h"

int	open_file(char *dict_name)
{
	int	success;

	success = open(dict_name, O_RDONLY);
	return (success);
}

char	*ft_strndup2(char *src, int size)
{
	char	*dest;
	int		i;
	int		j;

	i = 0;
	j = 0;
	dest = (char *)malloc(size + 1);
	while (src[i] && i < size)
	{
		if (src[i] != ' ')
			dest[j++] = src[i];
		else if (i > 0 && src[i - 1] != ' ')
			dest[j++] = ' ';
		i++;
	}
	dest[j] = '\0';
	return (dest);
}

void	copy_line(char *line, t_dict *dict)
{
	int	size;

	while (*line && *line != ':')
		line++;
	line++;
	while (is_whitespace(*line))
		line++;
	size = ft_strlen(line);
	while (is_whitespace(line[size - 1]))
		size--;
	dict->value = ft_strndup2(line, size);
}

t_dict	**get_dict(char *dict_name)
{
	t_dict	**dict;
	char	words[1024];
	char	**dict_array;
	int		dict_num;
	int		i;

	i = 0;
	if (read(open_file(dict_name), words, sizeof(words)) < 0)
	{
		write(1, "Dict error, unable to read file\n", 32);
		return (NULL);
	}
	dict_num = count_strings(words, "\n");
	dict = (t_dict **)malloc(sizeof(t_dict *) * (100 + 1));
	dict[100] = NULL;
	dict_array = ft_split(words, "\n");
	while (i < dict_num)
	{
		dict[num_to_index(dict_array[i])] = (t_dict *)malloc(sizeof(t_dict));
		copy_line(dict_array[i], dict[num_to_index(dict_array[i])]);
		i++;
	}
	free(dict_array);
	close(open_file(dict_name));
	return (dict);
}
