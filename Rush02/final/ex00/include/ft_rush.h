/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rush.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zliow <zliow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 16:09:20 by zliow             #+#    #+#             */
/*   Updated: 2023/10/01 16:12:13 by zliow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_RUSH_H
# define FT_RUSH_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_dict 
{
	char	*key;
	char	*value;
} t_dict;

int		valid_nbr(char *str);
int		valid_dict(char *str);
int		valid_input(int ac, char **av);
void	print_error_message(void);
void	ft_putstr(char *str);
int		is_whitespace(char str);
int		num_to_index(char *str);
char	*ft_strncpy(char *dest, char *src, int size);
char	*ft_strndup(char *src, int size);
int		is_sep(char c, char *charset);
int		count_strings(char *str, char *charset);
char	**ft_split(char *str, char *charset);
int		open_file(char *dict_name);
t_dict	**get_dict(char *dict_name);
void	get_word_by_map(t_dict *dict, int i);
int		ft_strlen(char *str);
int		is_zero(char *chr, int len);
void	blockofoutput(char *nbr, int size, t_dict **dict, int prt_whtsp);
void	print_text(char *nbr, int size, t_dict **dict);
void	ft_deconstructor(t_dict **dict);

#endif
