NAME = libft.a
TAGS = -Wall -Wextra -Werror
SRCS = *.c

all: $(NAME)

$(NAME):
	cc $(TAGS) libft.h -c $(SRCS)
	ar rc $(NAME) *.o

clean:
	rm -f *.o

fclean:	clean
	rm -f $(NAME)
	rm -f *.gch

re: fclean all
