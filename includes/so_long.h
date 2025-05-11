#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include "mlx.h"
# include "ft_printf.h"

# define STEP 10
# define ESC 65307
# define W 119
# define A 97
# define S 115
# define D 100

typedef struct	s_vars
{
	void	*mlx;
	void	*win;
	void	*img;
	int	img_width;
	int	img_height;
	int	x;
	int	y;
} t_vars;

#endif
