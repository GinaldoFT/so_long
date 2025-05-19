/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ginfranc <ginfranc@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 15:35:05 by ginfranc          #+#    #+#             */
/*   Updated: 2025/05/19 12:46:45 by ginfranc         ###   ########.fr       */
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

int	ft_close(t_vars *vars, int n)
{
	mlx_clear_window(vars->mlx, vars->win);
	mlx_destroy_image(vars->mlx, vars->img_coin);
	mlx_destroy_image(vars->mlx, vars->img_exit);
	mlx_destroy_image(vars->mlx, vars->img_exitt);
	mlx_destroy_image(vars->mlx, vars->img_p);
	mlx_destroy_image(vars->mlx, vars->img_wall);
	mlx_destroy_image(vars->mlx, vars->img_floor);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	free_all(vars->map, vars->map_y / 32);
	free(vars->mlx);
	close(vars->fd);
	if (n == 2)
	{
		ft_printf("YOU WIN!");
		exit(0);
	}
	ft_printf("Closed");
	exit(0);
	return (0);
}

void file_ber(char *file, int fd)
{
	const char	*ext;
	size_t	len;

	if (!file)
		return ;
	ext = ft_strrchr(file, '.');
	if(!ext)
		return ;
	len = ft_strlen(ext);
	if (ft_strncmp(ext, ".ber", len) != 0)
	{
		close(fd);
		exit(0);
	}
}

int	main(int ac, char *av[])
{
	t_vars	vars;

	vars.moves = 0;
	vars.coinsc = 0;
	if (ac != 2)
	{
		if (ac > 2)
			ft_putstr_fd("Error: Muitos Argumentos", 2);
		else if (ac < 2)
			ft_putstr_fd("Error: Mapa Nescessario", 2);
		return (1);
	}
	vars.fd = open(av[1], O_RDONLY);
	if (vars.fd == -1)
		return (0);
	file_ber(av[1], vars.fd);
	create_map(vars.fd, &vars);
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, vars.map_x, vars.map_y, "so_long");
	load_imgs(&vars);
	mlx_key_hook(vars.win, ft_key_hook, &vars);
	mlx_hook(vars.win, 17, 0, ft_close, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
