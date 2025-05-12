CC = cc

CFLAGS = -Wall -Werror -Wextra

CFILES = \
		ft_printf.c ft_putstr.c ft_putnbr.c \
		ft_putnbr_u.c ft_putchar.c ft_hexasecimal.c\
		ft_hexasecimal_upper.c

OFILES = $(CFILES:.c=.o)

NAME = libftprintf.a

all: $(NAME)

$(NAME): $(OFILES)
		ar rcs $(NAME) $(OFILES)

clean:
		rm -f $(OFILES)

fclean: clean
		rm -f $(NAME)

re: fclean all

run: $(NAME)
	$(CC) $(CFLAGS) ft_printf.c libftprintf.a -o ./run.out
	./run.out

.PHONY: all clean fclean re