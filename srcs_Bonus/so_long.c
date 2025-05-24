/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ginfranc <ginfranc@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 15:35:05 by ginfranc          #+#    #+#             */
/*   Updated: 2025/05/24 14:39:07 by ginfranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	file_ber(char *file, int fd)
{
	const char	*ext;
	size_t		len;

	if (!file)
		return ;
	ext = ft_strrchr(file, '.');
	if (!ext)
		return ;
	len = ft_strlen(ext);
	if (ft_strncmp(ext, ".ber", len) != 0)
	{
		close(fd);
		ft_putstr_fd("Error\nInvalid map file extension.", 2);
		exit(0);
	}
}

void	print_move_count(t_vars *vars)
{
	char	*str;
	char	*full_str;

	str = ft_itoa(vars->moves);
	full_str = ft_strjoin("Moves: ", str);
	free(str);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img_wall, 32, 0);
	mlx_string_put(vars->mlx, vars->win, 0, 16, 0xFFFFFF, full_str);
	free(full_str);
}

int	main(int ac, char *av[])
{
	t_vars	vars;

	if (ac != 2)
	{
		if (ac > 2)
			ft_putstr_fd("Error\nToo many arguments.", 2);
		else if (ac < 2)
			ft_putstr_fd("Error\nMap is necessary.", 2);
		return (1);
	}
	check_fd(&vars, av[1]);
	create_map(vars.fd, &vars);
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, vars.map_x, vars.map_y, "so_long");
	load_imgs(&vars);
	mlx_key_hook(vars.win, ft_key_hook, &vars);
	mlx_loop_hook(vars.mlx, animation_coin, &vars);
	mlx_hook(vars.win, 17, 0, ft_close, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
