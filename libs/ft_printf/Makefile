NAME = libftprintf.a
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I include

SRCS = ./srcs/ft_printf.c ./srcs/ft_cnumber.c ./srcs/ft_putstr_len.c

OBJS = ft_printf.o ft_cnumber.o ft_putstr_len.o

all: $(NAME)

$(NAME):
	cc $(CFLAGS) $(INCLUDES) -c $(SRCS)
	ar rc $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
