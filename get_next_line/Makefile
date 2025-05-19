CC = cc

#CFLAGS = -Wall -Werror -Wextra

CFILES = \
		get_next_line.c get_next_line_utils.c

OFILES = $(CFILES:.c=.o)

NAME = get_next_line.a

all: $(NAME)

$(NAME): $(OFILES)
		ar rcs $(NAME) $(OFILES)

clean:
		rm -f $(OFILES)

fclean: clean
		rm -f $(NAME)

re: fclean all

run: $(NAME)
	$(CC) get_next_line.c get_next_line.a -o ./run.out
	./run.out

.PHONY: all clean fclean re