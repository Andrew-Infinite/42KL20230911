#ifndef MY_STRING_H
# define MY_STRING_H
# define INT_MAX 2147483647
# define UINT_MAX 4294967295

int	map_init(char *charset, char *map, int map_size);
char	*ft_strdup(char *src, int size);
int	ft_word_count(char *str, char *map, char **ptr);
void	destructor_ft_split(char **ptr);
char	**ft_split(char *str, char *charset);

#endif