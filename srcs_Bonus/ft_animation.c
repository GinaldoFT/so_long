/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_animation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ginfranc <ginfranc@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 10:02:26 by ginfranc          #+#    #+#             */
/*   Updated: 2025/05/23 11:51:42 by ginfranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    load_imgs_bonus(t_vars *vars)
{
	int	w;
	int	h;

    vars->img_coin[1] = mlx_xpm_file_to_image(vars->mlx, COIN2, &w, &h);
	vars->img_coin[2] = mlx_xpm_file_to_image(vars->mlx, COIN3, &w, &h);
	vars->img_coin[3] = mlx_xpm_file_to_image(vars->mlx, COIN4, &w, &h);
	vars->img_p[1] = mlx_xpm_file_to_image(vars->mlx, "sprites/player2.xpm", &w, &h);
	vars->img_p[2] = mlx_xpm_file_to_image(vars->mlx, "sprites/player3.xpm", &w, &h);
	vars->img_p[3] = mlx_xpm_file_to_image(vars->mlx, "sprites/player4.xpm", &w, &h);
	vars->img_enemy[0] = mlx_xpm_file_to_image(vars->mlx, "sprites/enemy.xpm", &w, &h);
	vars->img_enemy[1] = mlx_xpm_file_to_image(vars->mlx, "sprites/enemy_2.xpm", &w, &h);
	vars->img_enemy[2] = mlx_xpm_file_to_image(vars->mlx, "sprites/enemy_3.xpm", &w, &h);
	vars->img_enemy[3] = mlx_xpm_file_to_image(vars->mlx, "sprites/enemy_4.xpm", &w, &h);
	vars->img_fenemy[0] = mlx_xpm_file_to_image(vars->mlx, "sprites/fenemy.xpm", &w, &h);
	vars->img_fenemy[1] = mlx_xpm_file_to_image(vars->mlx, "sprites/fenemy_2.xpm", &w, &h);
	vars->img_fenemy[2] = mlx_xpm_file_to_image(vars->mlx, "sprites/fenemy_3.xpm", &w, &h);
	vars->img_fenemy[3] = mlx_xpm_file_to_image(vars->mlx, "sprites/fenemy_4.xpm", &w, &h);
}

void	draw_animation(t_vars *vars)
{
	int		y;
	int		x;

	y = 0;
	while (vars->map[y])
	{
		x = 0;
		while (vars->map[y][x])
		{
			if (vars->map[y][x] == 'C')
			{
				draw_trans_img(vars, vars->img_floor, x * TILE_SIZE, y * TILE_SIZE);
				draw_trans_img(vars, vars->img_coin[vars->anim], x * TILE_SIZE, y * TILE_SIZE);
			}
			x++;
		}
		y++;
	}
	draw_trans_img(vars, vars->img_floor, vars->x, vars->y);
	draw_trans_img(vars, vars->img_p[vars->anim], vars->x, vars->y);
	draw_trans_img(vars, vars->img_floor, vars->enemy_x, vars->enemy_y);
	if (vars->wall == 1)
		draw_trans_img(vars, vars->img_fenemy[vars->anim], vars->enemy_x, vars->enemy_y);
	else
		draw_trans_img(vars, vars->img_enemy[vars->anim], vars->enemy_x, vars->enemy_y);
}

int    animation_coin(t_vars *vars)
{
	vars->count ++;
	if (vars->count == 15000)
	{
    	if (vars->anim + 1 == 4)
			vars->anim = 0;
		else
			vars->anim++;
		draw_animation(vars);
	}
	if (vars->count == 15000 && vars->anim == 3)
		moviment(vars);
	if (vars->x == vars->enemy_x && vars->y == vars->enemy_y)
	{
		ft_printf("Voce Perdeu!");
		ft_close(vars, 3);
	}
	if (vars->count > 15000)
		vars->count = 0;
	return (0);
}