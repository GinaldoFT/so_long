NAME = so_long
NAME_BONUS = so_long_bonus

CC = cc
CFLAGS = -Wall -Wextra -Werror -g

INCLUDES = -Iincludes -Ilibs/libft -Ilibs/ft_printf/include -Ilibs/mlx

SRC_DIR = srcs
BONUS_DIR = srcs_Bonus
LIB_DIR = libs

LIBFT_DIR = $(LIB_DIR)/libft
PRINTF_DIR = $(LIB_DIR)/ft_printf
MLX_DIR = $(LIB_DIR)/mlx

LIBFT = $(LIBFT_DIR)/libft.a
PRINTF = $(PRINTF_DIR)/libftprintf.a
MLX = -L$(MLX_DIR) -lmlx -lXext -lX11

SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(SRCS:.c=.o)

BONUS_SRCS = $(wildcard $(BONUS_DIR)/*.c)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

all: $(NAME)

$(NAME): $(LIBFT) $(PRINTF) $(MLX) $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) -o $(NAME) $(OBJS) $(LIBFT) $(PRINTF) $(MLX)

bonus: $(LIBFT) $(PRINTF) $(MLX) $(BONUS_OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) -o $(NAME_BONUS) $(BONUS_OBJS) $(LIBFT) $(PRINTF) $(MLX)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(PRINTF):
	$(MAKE) -C $(PRINTF_DIR)

$(MLX):
	$(MAKE) -C $(MLX_DIR)

clean:
	rm -f $(OBJS) $(BONUS_OBJS)
	$(MAKE) clean -C $(LIBFT_DIR)
	$(MAKE) clean -C $(PRINTF_DIR)
	$(MAKE) clean -C $(MLX_DIR)

fclean: clean
	rm -f $(NAME) $(NAME_BONUS)
	$(MAKE) fclean -C $(LIBFT_DIR)
	$(MAKE) fclean -C $(PRINTF_DIR)
	$(MAKE) clean -C $(MLX_DIR)

re: fclean all

.PHONY: all bonus clean fclean re
