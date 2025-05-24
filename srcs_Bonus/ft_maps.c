/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_maps.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ginfranc <ginfranc@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 08:54:20 by ginfranc          #+#    #+#             */
/*   Updated: 2025/05/24 15:29:33 by ginfranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_map_utils(t_vars *vars, int y, int x)
{
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img_floor, x * TILE_SIZE, y * TILE_SIZE);
	if (vars->map[y][x] == 'P')
	{
		vars->x = x * TILE_SIZE;
		vars->y = y * TILE_SIZE;
	}
	else if (vars->map[y][x] == '1')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img_wall, x * TILE_SIZE, y * TILE_SIZE);
	else if (vars->map[y][x] == 'C')
		draw_trans_img(vars, vars->img_coin[0], x * TILE_SIZE, y * TILE_SIZE);
	else if (vars->map[y][x] == 'E')
	{
		draw_trans_img(vars, vars->img_exit[0], x * TILE_SIZE, y * TILE_SIZE);
	}
	else if (vars->map[y][x] == 'M')
	{
		vars->enemy_x = x * TILE_SIZE;
		vars->enemy_y = y * TILE_SIZE;
		vars->map[y][x] = '0';
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
	vars->moves = 0;
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
