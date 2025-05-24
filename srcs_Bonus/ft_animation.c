/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_animation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ginfranc <ginfranc@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 10:02:26 by ginfranc          #+#    #+#             */
/*   Updated: 2025/05/24 16:29:20 by ginfranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_imgs(t_vars *vars)
{
	int	h;
	int	w;

	vars->img_p[0] = mlx_xpm_file_to_image(vars->mlx, PLAYER, &w, &h);
	if (!vars->img_p[0])
		ft_putstr_fd("Error\nFailed to load player!", 2);
	vars->img_floor = mlx_xpm_file_to_image(vars->mlx, FLOOR, &w, &h);
	if (!vars->img_floor)
		ft_putstr_fd("Error\nFailed to load floor", 2);
	vars->img_wall = mlx_xpm_file_to_image(vars->mlx, WALL, &w, &h);
	if (!vars->img_wall)
		ft_putstr_fd("Error\nFailed to load wall!", 2);
	vars->img_exit[0] = mlx_xpm_file_to_image(vars->mlx, EXIT, &w, &h);
	if (!vars->img_exit[0])
		ft_putstr_fd("Error\nFailed to load exit!", 2);
	vars->img_coin[0] = mlx_xpm_file_to_image(vars->mlx, COIN, &w, &h);
	if (!vars->img_coin[0])
		ft_putstr_fd("Error\nFailed to load coin!", 2);
	vars->img_exit[1] = mlx_xpm_file_to_image(vars->mlx, EXITT, &w, &h);
	if (!vars->img_exit[1])
		ft_putstr_fd("Error\nFailed to load exit2!", 2);
	draw_map(vars);
	load_imgs_bonus(vars);
}

void	load_imgs_bonus(t_vars *vars)
{
	int	w;
	int	h;

	vars->img_coin[1] = mlx_xpm_file_to_image(vars->mlx, COIN2, &w, &h);
	vars->img_coin[2] = mlx_xpm_file_to_image(vars->mlx, COIN3, &w, &h);
	vars->img_coin[3] = mlx_xpm_file_to_image(vars->mlx, COIN4, &w, &h);
	vars->img_p[1] = mlx_xpm_file_to_image(vars->mlx, PLAYER2, &w, &h);
	vars->img_p[2] = mlx_xpm_file_to_image(vars->mlx, PLAYER3, &w, &h);
	vars->img_p[3] = mlx_xpm_file_to_image(vars->mlx, PLAYER4, &w, &h);
	vars->img_enemy[0] = mlx_xpm_file_to_image(vars->mlx, ENEMY, &w, &h);
	vars->img_enemy[1] = mlx_xpm_file_to_image(vars->mlx, ENEMY2, &w, &h);
	vars->img_enemy[2] = mlx_xpm_file_to_image(vars->mlx, ENEMY3, &w, &h);
	vars->img_enemy[3] = mlx_xpm_file_to_image(vars->mlx, ENEMY4, &w, &h);
	vars->img_fenemy[0] = mlx_xpm_file_to_image(vars->mlx, FENEMY, &w, &h);
	vars->img_fenemy[1] = mlx_xpm_file_to_image(vars->mlx, FENEMY2, &w, &h);
	vars->img_fenemy[2] = mlx_xpm_file_to_image(vars->mlx, FENEMY3, &w, &h);
	vars->img_fenemy[3] = mlx_xpm_file_to_image(vars->mlx, FENEMY4, &w, &h);
}

void	draw_animation_utils(t_vars *vars, int i)
{
	draw_trans_img(vars, vars->img_floor, vars->x, vars->y);
	draw_trans_img(vars, vars->img_p[i], vars->x, vars->y);
	if (vars->enemy == 1)
	{
		draw_trans_img(vars, vars->img_floor, vars->enemy_x, vars->enemy_y);
		if (vars->horizontal_dir == 1)
			draw_trans_img(vars, vars->img_fenemy[i], \
			vars->enemy_x, vars->enemy_y);
		else
			draw_trans_img(vars, vars->img_enemy[i], \
			vars->enemy_x, vars->enemy_y);
	}
}

void	draw_animation(t_vars *vars)
{
	int		y;
	int		x;
	int		i;

	y = 0;
	i = vars->anim;
	while (vars->map[y])
	{
		x = 0;
		while (vars->map[y][x])
		{
			if (vars->map[y][x] == 'C')
			{
				draw_trans_img(vars, vars->img_floor, x * 32, y * 32);
				draw_trans_img(vars, vars->img_coin[i], x * 32, y * 32);
			}
			x++;
		}
		y++;
	}
	draw_animation_utils(vars, i);
}

int	animation_coin(t_vars *vars)
{
	vars->count++;
	if (vars->count == 15000)
	{
		if (vars->anim + 1 == 4)
			vars->anim = 0;
		else
			vars->anim++;
		draw_animation(vars);
	}
	if (vars->count == 15000 && vars->anim == 3 && vars->enemy == 1)
		move_enemy_horizontal(vars);
	if (vars->x == vars->enemy_x && vars->y == vars->enemy_y)
	{
		ft_printf("GAME OVER!");
		ft_close(vars, 3);
	}
	if (vars->count > 15000)
		vars->count = 0;
	return (0);
}
