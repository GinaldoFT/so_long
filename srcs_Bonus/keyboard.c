/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ginfranc <ginfranc@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 15:31:10 by ginfranc          #+#    #+#             */
/*   Updated: 2025/05/24 11:35:57 by ginfranc         ###   ########.fr       */
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
		draw_trans_img(vars, vars->img_exit[0], x, y);
	}
	else if (tile == 'P')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img_floor, x, y);
}

void	count_coins(t_vars *vars, int x, int y)
{
	char	tile;

	tile = vars->map[y / TILE_SIZE][x / TILE_SIZE];
	if (tile == 'C')
	{
		vars->coinsc++;
		vars->map[y / TILE_SIZE][x / TILE_SIZE] = '0';
		draw_trans_img(vars, vars->img_floor, x, y);
	}
	else if (tile == 'E')
	{
		if (vars->coins == vars->coinsc)
			ft_close(vars, 2);
	}
	if (vars->coins == vars->coinsc)
		draw_trans_img(vars, vars->img_exit[1], vars->ex, vars->ey);
}

void	ft_key_hook2(t_vars *vars, int new_y, int new_x)
{
	if (vars->map[new_y / TILE_SIZE][new_x / TILE_SIZE] != '1')
	{
		if (new_x != vars->x || new_y != vars->y)
			vars->moves++;
		draw_tile(vars, vars->x, vars->y);
		vars->x = new_x;
		vars->y = new_y;
		count_coins(vars, vars->x, vars->y);
		draw_trans_img(vars, vars->img_p[vars->anim], vars->x, vars->y);
		print_move_count(vars);
	}
}

int	ft_key_hook(int keycode, t_vars *vars)
{
	int	new_y;
	int	new_x;

	new_x = vars->x;
	new_y = vars->y;
	if (keycode == ESC)
		ft_close(vars, 1);
	if (keycode == W || keycode == 65362)
		new_y -= TILE_SIZE;
	if (keycode == S || keycode == 65364)
		new_y += TILE_SIZE;
	if (keycode == A || keycode == 65361)
		new_x -= TILE_SIZE;
	if (keycode == D || keycode == 65363)
		new_x += TILE_SIZE;
	ft_key_hook2(vars, new_y, new_x);
	return (0);
}
