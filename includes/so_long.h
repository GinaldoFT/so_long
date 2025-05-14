/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ginfranc <ginfranc@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 15:31:01 by ginfranc          #+#    #+#             */
/*   Updated: 2025/05/14 16:05:31 by ginfranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include "mlx.h"
# include "ft_printf.h"
# include <stdio.h>
# include <fcntl.h>

# define ESC 65307
# define W 119
# define A 97
# define S 115
# define D 100
# define TILE_SIZE 32
# define PLAYER "sprites/player.xpm"

typedef struct	s_vars
{
	void	*mlx;
	void	*win;
	void	*img_p;
	void	*img_p2;
	void	*img_wall;
	void	*img_floor;
	void	*img_coin;
	void	*img_exit;
	int		img_w;
	int		img_h;
	int		x;
	int		y;
	char	**map;
	int		map_x;
	int		map_y;
} t_vars;

int				key_hook(int keycode, t_vars *vars);
void			draw_map(t_vars *vars);
void			ft_windown_size(t_vars *vars);
void			load_imgs(t_vars *vars);
void			create_map(int fd, t_vars *vars);
unsigned int	get_pixel_color(void *img, int x, int y);
void			draw_trans_img(t_vars *vars, void *img, int posx, int posy);

#endif
