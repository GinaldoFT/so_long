/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ginfranc <ginfranc@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 08:08:50 by ginfranc          #+#    #+#             */
/*   Updated: 2025/05/24 14:57:49 by ginfranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*free_all(char **map, int i)
{
	while (--i >= 0)
		free(map[i]);
	free(map);
	return (NULL);
}

void	ft_close_imgs(t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->img_coin[1]);
	mlx_destroy_image(vars->mlx, vars->img_coin[2]);
	mlx_destroy_image(vars->mlx, vars->img_coin[3]);
	mlx_destroy_image(vars->mlx, vars->img_p[1]);
	mlx_destroy_image(vars->mlx, vars->img_p[2]);
	mlx_destroy_image(vars->mlx, vars->img_p[3]);
	mlx_destroy_image(vars->mlx, vars->img_enemy[0]);
	mlx_destroy_image(vars->mlx, vars->img_enemy[1]);
	mlx_destroy_image(vars->mlx, vars->img_enemy[2]);
	mlx_destroy_image(vars->mlx, vars->img_enemy[3]);
	mlx_destroy_image(vars->mlx, vars->img_fenemy[0]);
	mlx_destroy_image(vars->mlx, vars->img_fenemy[1]);
	mlx_destroy_image(vars->mlx, vars->img_fenemy[2]);
	mlx_destroy_image(vars->mlx, vars->img_fenemy[3]);
}

int	ft_close(t_vars *vars, int n)
{
	mlx_clear_window(vars->mlx, vars->win);
	mlx_destroy_image(vars->mlx, vars->img_coin[0]);
	mlx_destroy_image(vars->mlx, vars->img_exit[0]);
	mlx_destroy_image(vars->mlx, vars->img_exit[1]);
	mlx_destroy_image(vars->mlx, vars->img_p[0]);
	mlx_destroy_image(vars->mlx, vars->img_wall);
	mlx_destroy_image(vars->mlx, vars->img_floor);
	mlx_destroy_window(vars->mlx, vars->win);
	ft_close_imgs(vars);
	mlx_destroy_display(vars->mlx);
	free_all(vars->map, vars->map_y / TILE_SIZE);
	free_all(vars->clone_map, vars->map_y / TILE_SIZE);
	free(vars->mlx);
	close(vars->fd);
	if (n == 2)
	{
		ft_printf("YOU WIN!");
		exit(0);
	}
	if (n == 3)
		exit(0);
	ft_printf("Closed");
	exit(0);
	return (0);
}

void	check_fd(t_vars *vars, char *str)
{
	int		i;
	char	buffer[1];

	vars->moves = 0;
	vars->coinsc = 0;
	vars->counter = 0;
	vars->count = 0;
	vars->anim = 0;
	vars->wall = 0;
	vars->wall2 = 0;
	vars->fd = open(str, O_RDONLY);
	if (vars->fd == -1)
	{
		ft_putstr_fd("Error\nMap file could not be opened.", 2);
		exit(0);
	}
	i = read(vars->fd, buffer, 1);
	if (i == 0)
	{
		close(vars->fd);
		ft_putstr_fd("Error\nEmpty File.", 2);
		exit(0);
	}
	close(vars->fd);
	vars->fd = open(str, O_RDONLY);
	file_ber(str, vars->fd);
}
