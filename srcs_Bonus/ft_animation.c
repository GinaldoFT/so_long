#include "so_long.h"

void    load_imgs_bonus(t_vars *vars)
{
    vars->img_coin[1] = mlx_xpm_file_to_image(vars->mlx, COIN2, &vars->img_w, &vars->img_h);
	vars->img_coin[2] = mlx_xpm_file_to_image(vars->mlx, COIN3, &vars->img_w, &vars->img_h);
	vars->img_coin[3] = mlx_xpm_file_to_image(vars->mlx, COIN4, &vars->img_w, &vars->img_h);
	vars->img_p[1] = mlx_xpm_file_to_image(vars->mlx, "sprites/player2.xpm", &vars->img_w, &vars->img_h);
	vars->img_p[2] = mlx_xpm_file_to_image(vars->mlx, "sprites/player3.xpm", &vars->img_w, &vars->img_h);
	vars->img_p[3] = mlx_xpm_file_to_image(vars->mlx, "sprites/player4.xpm", &vars->img_w, &vars->img_h);
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
	if (vars->count > 15000)
		vars->count = 0;
	return (0);
}