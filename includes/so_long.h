#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include "mlx.h"
# include "ft_printf.h"
# include <stdio.h>

# define STEP 32
# define ESC 65307
# define W 119
# define A 97
# define S 115
# define D 100
# define TILE_SIZE 32

typedef struct	s_vars
{
	void	*mlx;
	void	*win;
	void	*img_player;
	void	*img_wall;
	void	*img_floor;
	void	*img_coin;
	void	*img_exit;
	int	img_width;
	int	img_height;
	int	x;
	int	y;
} t_vars;

int	key_hook(int keycode, t_vars *vars);
void	draw_map(t_vars *vars);

#endif
