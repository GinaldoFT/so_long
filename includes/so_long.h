/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ginfranc <ginfranc@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 15:31:01 by ginfranc          #+#    #+#             */
/*   Updated: 2025/05/24 16:29:12 by ginfranc         ###   ########.fr       */
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
# define FLOOR "sprites/floor.xpm"
# define WALL "sprites/wall.xpm"
# define EXIT "sprites/exit.xpm"
# define EXITT "sprites/exit_2.xpm"
# define COIN "sprites/Coin_1.xpm"
# define COIN2 "sprites/Coin_2.xpm"
# define COIN3 "sprites/Coin_3.xpm"
# define COIN4 "sprites/Coin_4.xpm"
# define PLAYER2 "sprites/player2.xpm"
# define PLAYER3 "sprites/player3.xpm"
# define PLAYER4 "sprites/player4.xpm"
# define ENEMY "sprites/enemy.xpm"
# define ENEMY2 "sprites/enemy_2.xpm"
# define ENEMY3 "sprites/enemy_3.xpm"
# define ENEMY4 "sprites/enemy_4.xpm"
# define FENEMY "sprites/fenemy.xpm"
# define FENEMY2 "sprites/fenemy_2.xpm"
# define FENEMY3 "sprites/fenemy_3.xpm"
# define FENEMY4 "sprites/fenemy_4.xpm"

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	void	*img_p[4];
	void	*img_wall;
	void	*img_floor;
	void	*img_coin[4];
	void	*img_exit[2];
	void	*img_enemy[4];
	void	*img_fenemy[4];
	int		enemy_x;
	int		enemy_y;
	int		x;
	int		y;
	char	**map;
	int		map_x;
	int		map_y;
	int		moves;
	int		coins;
	int		coinsc;
	int		fd;
	int		ex;
	int		ey;
	char	**clone_map;
	int		count;
	int		anim;
	int		counter;
	int		horizontal_dir;
	int		vertical_dir;
	int		enemy;
}	t_vars;

typedef struct s_rules
{
	int		i;
	int		end;
	int		last;
	int		j;
	int		l;
	size_t	len;
	int		player;
	int		exit;
	int		lines;
	size_t	index;
}	t_rules;

int				ft_key_hook(int keycode, t_vars *vars);
void			draw_map(t_vars *vars);
void			ft_windown_size(t_vars *vars);
void			load_imgs(t_vars *vars);
void			create_map(int fd, t_vars *vars);
unsigned int	get_pixel_color(void *img, int x, int y);
void			draw_trans_img(t_vars *vars, void *img, int posx, int posy);
int				rule_map(t_vars *vars);
int				ft_close(t_vars *vars, int n);
void			*free_all(char **map, int i);
int				path(t_vars *vars, t_rules *rules);
int				animation_coin(t_vars *vars);
void			load_imgs_bonus(t_vars *vars);
void			print_move_count(t_vars *vars);
void			move_enemy_horizontal(t_vars *vars);
void			draw_tile(t_vars *vars, int x, int y);
void			check_fd(t_vars *vars, char *str);
void			file_ber(char *file, int fd);
int				len_line(t_vars *vars, t_rules *rules);
int				number_carac(t_vars *vars, t_rules *rules);
void			ft_error(t_vars *vars);

#endif
