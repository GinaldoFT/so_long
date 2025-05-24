/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_enemy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ginfranc <ginfranc@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 14:50:58 by ginfranc          #+#    #+#             */
/*   Updated: 2025/05/24 16:27:52 by ginfranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_enemy(t_vars *vars, int dx, int dy, void *img)
{
	draw_tile(vars, vars->enemy_x, vars->enemy_y);
	vars->enemy_x += dx;
	vars->enemy_y += dy;
	draw_trans_img(vars, img, vars->enemy_x, vars->enemy_y);
}

void	move_enemy_vertical(t_vars *vars)
{
	int tile_x;
	int tile_y;

	tile_x = vars->enemy_x / TILE_SIZE;
	tile_y = vars->enemy_y / TILE_SIZE;
	if (vars->vertical_dir == 0)
	{
		if (vars->map[tile_y + 1][tile_x] == '1')
			vars->vertical_dir = 1;
		else
			move_enemy(vars, 0, TILE_SIZE, vars->img_enemy[vars->anim]);
	}
	else if (vars->vertical_dir == 1)
	{
		if (vars->map[tile_y - 1][tile_x] == '1')
			vars->vertical_dir = 1;
		else
			move_enemy(vars, 0, -TILE_SIZE, vars->img_enemy[vars->anim]);
	}
}

void	move_enemy_horizontal(t_vars *vars)
{
	int tile_x;
	int tile_y;

	tile_x = vars->enemy_x / TILE_SIZE;
	tile_y = vars->enemy_y / TILE_SIZE;
	if (vars->horizontal_dir == 0)
	{
		if (vars->map[tile_y][tile_x + 1] == '1')
			vars->horizontal_dir = 1;
		else
			move_enemy(vars, TILE_SIZE, 0, vars->img_enemy[vars->anim]);
	}
	else if (vars->horizontal_dir == 1)
	{
		if (vars->map[tile_y][tile_x - 1] == '1')
			vars->horizontal_dir = 1;
		else
			move_enemy(vars, -TILE_SIZE, 0, vars->img_enemy[vars->anim]);
	}
	if (vars->map[tile_y][tile_x - 1] == '1' && \
	vars->map[tile_y][tile_x + 1] == '1')
		move_enemy_vertical(vars);
}
