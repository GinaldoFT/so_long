#include "so_long.h"

void	draw_map(t_vars *vars)
{
	int		y;
	int		x;
	
	y = 0;
	while (vars->map[y])
	{
		x = 0;
		while (vars->map[y][x])
		{
			mlx_put_image_to_window(vars->mlx, vars->win, vars->img_floor,
					x * TILE_SIZE, y * TILE_SIZE);
			if (vars->map[y][x] == 'P')
			{
				vars->x = x * TILE_SIZE;
				vars->y = y * TILE_SIZE;
                draw_trans_img(vars, vars->img_p, x * TILE_SIZE, y * TILE_SIZE);
			}
			if (vars->map[y][x] == '1')
				mlx_put_image_to_window(vars->mlx, vars->win, vars->img_wall,
					x * TILE_SIZE, y * TILE_SIZE);	
			else if (vars->map[y][x] == 'C')
				draw_trans_img(vars, vars->img_coin, x * TILE_SIZE, y * TILE_SIZE);
			else if (vars->map[y][x] == 'E')
			{
				draw_trans_img(vars, vars->img_exit, x * TILE_SIZE, y * TILE_SIZE);
			}
			if (vars->map[y][x] == '0')
				mlx_put_image_to_window(vars->mlx, vars->win, vars->img_floor,
					x * TILE_SIZE, y * TILE_SIZE);
			x++;
		}
		y++;
	}
}

void	create_map(int fd, t_vars *vars)
{
	char	*maps;
	char	*buffer;
	char 	*tmp;
	
	maps = NULL;
	while (1)
	{
		buffer = get_next_line(fd);
		if (!buffer)
			break;
		if (!maps)
			maps = ft_strdup(buffer);
		else
		{
			tmp = maps;
			maps = ft_strjoin(tmp, buffer);
			free(tmp);
		}
		free(buffer);
		tmp = maps;
		maps = ft_strjoin(tmp, "!");
		free(tmp);
	}
	if (maps)
	{
		vars->map = ft_split(maps, '!');
		free(maps);
	}
	ft_windown_size(vars);
	if (rule_map(vars) == 1)
	{
		ft_printf("erro\n");
		ft_close(vars);
	}
}

void	load_imgs(t_vars *vars)
{
	vars->img_p = mlx_xpm_file_to_image(vars->mlx, PLAYER, &vars->img_w, &vars->img_h);
	if (!vars->img_p)
    ft_printf("Erro ao Carregar Player!");
	vars->img_floor = mlx_xpm_file_to_image(vars->mlx, "sprites/floor.xpm", &vars->img_w, &vars->img_h);
	if (!vars->img_floor)
		ft_printf("Erro ao Carregar floor!");
	vars->img_wall = mlx_xpm_file_to_image(vars->mlx, "sprites/wall.xpm", &vars->img_w, &vars->img_h);
	if (!vars->img_wall)
		ft_printf("Erro ao Carregar wall!");
	vars->img_exit = mlx_xpm_file_to_image(vars->mlx, "sprites/exit.xpm", &vars->img_w, &vars->img_h);
	if (!vars->img_exit)
		ft_printf("Erro ao Carregar exit!");
	vars->img_coin = mlx_xpm_file_to_image(vars->mlx, "sprites/Coin_1.xpm", &vars->img_w, &vars->img_h);
	if (!vars->img_coin)
		ft_printf("Erro ao Carregar coin!");
    vars->img_p2 = mlx_xpm_file_to_image(vars->mlx, "sprites/player2.xpm", &vars->img_w, &vars->img_h);
	if (!vars->img_p)
    ft_printf("Erro ao Carregar Player!");
	draw_map(vars);
}

void ft_windown_size(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (vars->map[i])
		i++;
	while (vars->map[0][j])
		j++;
	vars->map_x = (j * TILE_SIZE) - 32;
	vars->map_y = i * TILE_SIZE;
}