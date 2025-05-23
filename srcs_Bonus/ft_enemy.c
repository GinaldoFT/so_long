/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_enemy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ginfranc <ginfranc@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 14:50:58 by ginfranc          #+#    #+#             */
/*   Updated: 2025/05/23 14:51:03 by ginfranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	moviment2(t_vars *vars)
{
	if (vars->wall2 == 0)
	{
		if (vars->map[(vars->enemy_y / TILE_SIZE) + 1][vars->enemy_x / TILE_SIZE] == '1')
			vars->wall2 = 1;
		else
		{
			draw_tile(vars, vars->enemy_x, vars->enemy_y);
			vars->enemy_y += 32;
			draw_trans_img(vars, vars->img_enemy[vars->anim], vars->enemy_x, vars->enemy_y);
		}
	}
	else if (vars->wall2 == 1)
	{
		if (vars->map[(vars->enemy_y / TILE_SIZE) - 1][vars->enemy_x / TILE_SIZE] == '1')
			vars->wall2 = 0;
		else
		{
			draw_tile(vars, vars->enemy_x, vars->enemy_y);
			vars->enemy_y -= 32;
			draw_trans_img(vars, vars->img_enemy[vars->anim], vars->enemy_x, vars->enemy_y);
		}
	}
}

void	moviment(t_vars *vars)
{
	if (vars->wall == 0)
	{
		if (vars->map[vars->enemy_y / TILE_SIZE][(vars->enemy_x / TILE_SIZE) + 1] == '1')
			vars->wall = 1;
		else
		{
			draw_tile(vars, vars->enemy_x, vars->enemy_y);
			vars->enemy_x += 32;
			draw_trans_img(vars, vars->img_enemy[vars->anim], vars->enemy_x, vars->enemy_y);
		}
	}
	else if (vars->wall == 1)
	{
		if (vars->map[vars->enemy_y / TILE_SIZE][(vars->enemy_x / TILE_SIZE) - 1] == '1')
			vars->wall = 0;
		else
		{
			draw_tile(vars, vars->enemy_x, vars->enemy_y);
			vars->enemy_x -= 32;
			draw_trans_img(vars, vars->img_fenemy[vars->anim], vars->enemy_x, vars->enemy_y);
		}
	}
	if (vars->map[vars->enemy_y / TILE_SIZE][(vars->enemy_x / TILE_SIZE) - 1] == '1'\
	&& vars->map[vars->enemy_y / TILE_SIZE][(vars->enemy_x / TILE_SIZE) + 1] == '1')
		moviment2(vars);
}
