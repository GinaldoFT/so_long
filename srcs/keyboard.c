/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ginfranc <ginfranc@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 15:31:10 by ginfranc          #+#    #+#             */
/*   Updated: 2025/05/13 17:51:41 by ginfranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_hook(int keycode, t_vars *vars)
{
	int	old_x;
	int	old_y;

	old_x = vars->x;
	old_y = vars->y;
	if (keycode == ESC)
		exit(0);
	if (keycode == W || keycode == 65362)
		vars->y -= TILE_SIZE;
	if (keycode == S || keycode == 65364)
		vars->y += TILE_SIZE;
	if (keycode == A || keycode == 65361)
		vars->x -= TILE_SIZE;
	if (keycode == D || keycode == 65363)
		vars->x += TILE_SIZE;
		
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img_player, vars->x, vars->y);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img_floor,
		old_x, old_y);

	return (0);
}