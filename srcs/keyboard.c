/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ginfranc <ginfranc@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 15:31:10 by ginfranc          #+#    #+#             */
/*   Updated: 2025/05/18 09:23:08 by ginfranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_tile(t_vars *vars, int x, int y)
{
	char	tile;

	tile = vars->map[y / TILE_SIZE][x / TILE_SIZE];
	if (tile == '0')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img_floor, x, y);
	else if (tile == 'C')
		draw_trans_img(vars, vars->img_floor, x, y);
	else if (tile == 'E')
	{
		draw_trans_img(vars, vars->img_floor, x, y);
		draw_trans_img(vars, vars->img_exit, x, y);
	}
	else if (tile == 'P')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img_floor, x, y);
}


int	ft_key_hook(int keycode, t_vars *vars)
{
	int	new_y;
	int	new_x;

	new_x = vars->x;
	new_y = vars->y;
	if (keycode == ESC)
		ft_close(vars);
	if (keycode == W || keycode == 65362)
		new_y -= TILE_SIZE;
	if (keycode == S || keycode == 65364)
		new_y += TILE_SIZE;
	if (keycode == A || keycode == 65361)
		new_x -= TILE_SIZE;
	if (keycode == D || keycode == 65363)
		new_x += TILE_SIZE;

	if (vars->map[new_y / TILE_SIZE][new_x / TILE_SIZE] != '1')
	{
		draw_tile(vars, vars->x, vars->y);
		vars->x = new_x;
		vars->y = new_y;
		draw_trans_img(vars, vars->img_p, vars->x, vars->y);
		vars->moves++;
	//	ft_printf("Moves: %i\n", vars->moves);
	}

	return (0);
}