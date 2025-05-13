/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ginfranc <ginfranc@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 15:35:05 by ginfranc          #+#    #+#             */
/*   Updated: 2025/05/13 17:51:39 by ginfranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_map(t_vars *vars)
{
	int		y;
	int		x;
	char	**mapa;

	mapa = vars->map;
	y = 0;
	while (mapa[y])
	{
		x = 0;
		while (mapa[y][x])
		{
			mlx_put_image_to_window(vars->mlx, vars->win, vars->img_floor,
					x * TILE_SIZE, y * TILE_SIZE);
			if (mapa[y][x] == '1')
				mlx_put_image_to_window(vars->mlx, vars->win, vars->img_wall,
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
		vars->map_x += 1;
	}
	if (maps)
	{
		vars->map = ft_split(maps, '!');
		free(maps);
	}
}

void	load_imgs(t_vars *vars)
{
	vars->img_player = mlx_xpm_file_to_image(vars->mlx, PLAYER, &vars->img_w, &vars->img_h);
	if (!vars->img_player)
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
}

int	main(int ac, char *av[])
{
	int	fd;
	t_vars vars;

	vars.x = 32;
	vars.y = 32;
	if (ac != 2)
	{
		ft_putstr_fd("Error: Muitos Argumentos", 2);
		return (1);
	} 

	fd = open(av[1], O_RDONLY);
	create_map(fd, &vars);
	vars.map_x *= TILE_SIZE;
	vars.map_y = TILE_SIZE * ft_strlen(vars.map[0]);
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, vars.map_y, vars.map_x - 32, "so_long");

	load_imgs(&vars);
	draw_map(&vars);
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_loop(vars.mlx);
	close(fd);
	return (0);
}
