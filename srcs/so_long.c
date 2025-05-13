/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ginfranc <ginfranc@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 15:35:05 by ginfranc          #+#    #+#             */
/*   Updated: 2025/05/13 12:41:34 by ginfranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_map(t_vars *vars)
{
	int		y;
	int		x;
	char	**mapa;
/*	char *mapa[] = {
    "11111111",
    "1P0000E1",
    "10000001",
    "11111111",
    NULL
};
*/
	mapa = vars->map;
	y = 0;
	while (mapa[y])
	{
		x = 0;
		while (mapa[y][x])
		{
			if (mapa[y][x] == '1')
				mlx_put_image_to_window(vars->mlx, vars->win, vars->img_wall,
					x * TILE_SIZE, y * TILE_SIZE);
			else if (mapa[y][x] == '0' || mapa[y][x] == 'P')
				mlx_put_image_to_window(vars->mlx, vars->win, vars->img_floor,
					x * TILE_SIZE, y * TILE_SIZE);
			else if (mapa[y][x] == 'C')
				mlx_put_image_to_window(vars->mlx, vars->win, vars->img_coin,
					x * TILE_SIZE, y * TILE_SIZE);
			else if (mapa[y][x] == 'E')
				mlx_put_image_to_window(vars->mlx, vars->win, vars->img_exit,
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
	ft_printf("teste");
	while (1)
	{
		buffer = get_next_line(fd);
		if (!buffer)
			break;
		tmp = maps;
		maps = ft_strjoin(tmp, buffer);
		tmp = maps;
		maps = ft_strjoin(tmp, "!");
	}
	vars->map = ft_split(maps, '!');
}

int	main(int ac, char *av[])
{
	int	fd;

	if (ac != 2)
		return (1);
	t_vars vars;

	fd = open(av[1], O_RDONLY);
	create_map(fd, &vars);
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 256, 128, "so_long");
	vars.x = 32;
	vars.y = 32;

	vars.img_player = mlx_xpm_file_to_image(vars.mlx, "sprites/player.xpm", &vars.img_width, &vars.img_height);
	if (!vars.img_player)
		ft_printf("Erro ao Carregar Player!");
	vars.img_floor = mlx_xpm_file_to_image(vars.mlx, "sprites/floor.xpm", &vars.img_width, &vars.img_height);
	if (!vars.img_floor)
		ft_printf("Erro ao Carregar floor!");
	vars.img_wall = mlx_xpm_file_to_image(vars.mlx, "sprites/wall.xpm", &vars.img_width, &vars.img_height);
	if (!vars.img_wall)
		ft_printf("Erro ao Carregar wall!");
	vars.img_exit = mlx_xpm_file_to_image(vars.mlx, "sprites/exit.xpm", &vars.img_width, &vars.img_height);
	if (!vars.img_exit)
		ft_printf("Erro ao Carregar exit!");
	vars.img_coin = mlx_xpm_file_to_image(vars.mlx, "sprites/Coin_1.xpm", &vars.img_width, &vars.img_height);
	if (!vars.img_coin)
		ft_printf("Erro ao Carregar coin!");
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_loop(vars.mlx);
}
