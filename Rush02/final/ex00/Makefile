CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCS = src/main.c src/print_words.c src/libft.c src/get_words.c src/get_dict.c src/ft_split.c src/check_input.c
OBJS = $(SRCS:.c=.o)
NAME = rush-02

all: ${NAME}

${NAME}: ${OBJS}
	${CC} ${CFLAGS} ${SRCS} -Iinclude -o ${NAME}

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean