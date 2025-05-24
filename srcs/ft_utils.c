/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ginfranc <ginfranc@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 15:05:40 by ginfranc          #+#    #+#             */
/*   Updated: 2025/05/24 15:05:51 by ginfranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_windown_size(t_vars *vars)
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
	if (vars->map_x > 1920 || vars->map_y > 1024)
	{
		ft_putstr_fd("Error\nMap is too large.", 2);
		free_all(vars->map, vars->map_y / 32);
		exit(0);
	}
}

void	ft_error(t_vars *vars)
{
	int	error;

	ft_windown_size(vars);
	error = rule_map(vars);
	if (error == 0)
		return ;
	if (error == 2)
		ft_putstr_fd("Error\nThe map must be enclosed by walls.", 2);
	if (error == 3)
		ft_putstr_fd("Error\nMap is not rectangular.", 2);
	free_all(vars->map, vars->map_y / 32);
	free_all(vars->clone_map, vars->map_y / 32);
	exit(0);
}

int	number_carac(t_vars *vars, t_rules *rules)
{
	rules->j = 1;
	if (rules->player != 1)
	{
		ft_putstr_fd("Error\nThere must be at least one player.", 2);
		return (1);
	}
	if (rules->exit != 1)
	{
		ft_putstr_fd("Error\nOnly one door is allowed.", 2);
		return (1);
	}
	if (vars->coins < 1)
	{
		ft_putstr_fd("Error\nThere must be at least one coin.", 2);
		return (1);
	}
	return (0);
}

int	len_line(t_vars *vars, t_rules *rules)
{
	int	i;

	i = 1;
	rules->len = ft_strlen(vars->map[0]);
	while (i < rules->last)
	{
		if (ft_strlen(vars->map[i]) != rules->len)
			return (1);
		i++;
	}
	rules->len -= 1;
	if (ft_strlen(vars->map[rules->last]) != rules->len)
		return (1);
	return (0);
}
