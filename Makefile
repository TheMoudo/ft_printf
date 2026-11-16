NAME = libftprintf.a
SRCS = ft_printf.c put_char.c put_str.c put_nbr.c put_unsigned_nbr.c put_hex.c put_point.c
OBJS = $(SRCS:.c=.o)
RM = rm -f
CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re