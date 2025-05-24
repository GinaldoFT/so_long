/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_maps.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ginfranc <ginfranc@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 08:54:20 by ginfranc          #+#    #+#             */
/*   Updated: 2025/05/24 15:51:37 by ginfranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_map_utils(t_vars *vars, int y, int x)
{
	mlx_put_image_to_window(vars->mlx, vars->win, \
	vars->img_floor, x * TILE_SIZE, y * TILE_SIZE);
	if (vars->map[y][x] == 'P')
	{
		vars->x = x * TILE_SIZE;
		vars->y = y * TILE_SIZE;
	}
	else if (vars->map[y][x] == '1')
		mlx_put_image_to_window(vars->mlx, vars->win, \
	vars->img_wall, x * TILE_SIZE, y * TILE_SIZE);
	else if (vars->map[y][x] == 'C')
		draw_trans_img(vars, vars->img_coin[0], x * TILE_SIZE, y * TILE_SIZE);
	else if (vars->map[y][x] == 'E')
	{
		draw_trans_img(vars, vars->img_exit[0], x * TILE_SIZE, y * TILE_SIZE);
	}
}

void	draw_map(t_vars *vars)
{
	int	y;
	int	x;

	y = 0;
	while (vars->map[y])
	{
		x = 0;
		while (vars->map[y][x])
		{
			if (vars->map[y][x] == '\n')
				break ;
			draw_map_utils(vars, y, x);
			x++;
		}
		y++;
	}
}

void	create_maps_utils(t_vars *vars, char *maps)
{
	if (maps)
	{
		vars->clone_map = ft_split(maps, '!');
		vars->map = ft_split(maps, '!');
		free(maps);
	}
	ft_error(vars);
}

void	create_map(int fd, t_vars *vars)
{
	char	*maps;
	char	*buffer;
	char	*tmp;

	maps = NULL;
	while (1)
	{
		buffer = get_next_line(fd);
		if (!buffer)
			break ;
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
	create_maps_utils(vars, maps);
}

void	load_imgs(t_vars *vars)
{
	int	w;
	int	h;

	vars->img_p[0] = mlx_xpm_file_to_image(vars->mlx, PLAYER, &w, &h);
	if (!vars->img_p[0])
		ft_putstr_fd("Error\nFailed to load player!", 2);
	vars->img_floor = mlx_xpm_file_to_image(vars->mlx, FLOOR, &w, &h);
	if (!vars->img_floor)
		ft_putstr_fd("Error\nFailed to load floor", 2);
	vars->img_wall = mlx_xpm_file_to_image(vars->mlx, WALL, &w, &h);
	if (!vars->img_wall)
		ft_putstr_fd("Error\nFailed to load wall!", 2);
	vars->img_exit[0] = mlx_xpm_file_to_image(vars->mlx, EXIT, &w, &h);
	if (!vars->img_exit[0])
		ft_putstr_fd("Error\nFailed to load exit!", 2);
	vars->img_coin[0] = mlx_xpm_file_to_image(vars->mlx, COIN, &w, &h);
	if (!vars->img_coin[0])
		ft_putstr_fd("Error\nFailed to load coin!", 2);
	vars->img_exit[1] = mlx_xpm_file_to_image(vars->mlx, EXITT, &w, &h);
	if (!vars->img_exit[1])
		ft_putstr_fd("Error\nFailed to load exit2!", 2);
	draw_map(vars);
}
