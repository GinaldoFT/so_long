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
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, vars->x, vars->y);

	return (0);
}

int	main()
{
	t_vars vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 800, 600, "so_long");
	vars.x = 800 / 2;
	vars.y = 600 / 2;

	ft_printf("Tentando carregar a imagem: %s\n", "player.xpm");
	vars.img = mlx_xpm_file_to_image(vars.mlx, "sprites/player.xpm", &vars.img_width, &vars.img_height);
	if (!vars.img)
	{
		ft_putstr_fd("Erro ao carregar imagem XPM\n", 2);
		return (1);
	}
	mlx_put_image_to_window(vars.mlx, vars.win, vars.img, vars.x, vars.y);
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_loop(vars.mlx);
}
