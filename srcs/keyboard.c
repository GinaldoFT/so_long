#include "so_long.h"

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == ESC)
		exit(0);
	if (keycode == W)
		vars->y -= STEP;
	if (keycode == S)
		vars->y += STEP;
	if (keycode == A)
		vars->x -= STEP;
	if (keycode == D)
		vars->x += STEP;
	mlx_clear_window(vars->mlx, vars->win);
    draw_map(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img_player, vars->x, vars->y);

	return (0);
}