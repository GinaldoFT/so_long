/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_rules.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ginfranc <ginfranc@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 08:54:10 by ginfranc          #+#    #+#             */
/*   Updated: 2025/05/24 11:33:53 by ginfranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

int	first_and_last(t_vars *vars, t_rules *rules)
{
	while (vars->map[0][rules->i])
	{
		if (vars->map[0][rules->i] != '1' && vars->map[0][rules->i] != '\n')
			return (1);
		rules->i++;
	}
	while (vars->map[rules->last][rules->end])
	{
		if (vars->map[rules->last][rules->end] != '1' && vars->map[rules->last][rules->end] != '\n')
			return (1);
		rules->end++;
	}
	return (0);
}

int	line_letter_utils(t_vars *vars, t_rules *rules)
{
	if (vars->map[rules->lines][rules->index] == 'P')
	{
		vars->x = rules->index * TILE_SIZE;
		vars->y = rules->lines * TILE_SIZE;
		rules->player++;
	}
	else if (vars->map[rules->lines][rules->index] == 'E')
	{
		vars->ey = rules->lines * TILE_SIZE;
		vars->ex = rules->index * TILE_SIZE;
		rules->exit++;
	}
	else if (vars->map[rules->lines][rules->index] == 'M')
		rules->enemy++;
	else if (vars->map[rules->lines][rules->index] == 'C')
		vars->coins++;
	else if (vars->map[rules->lines][rules->index] != '1' && \
	vars->map[rules->lines][rules->index] != '0')
	{
		ft_printf("caractarer invalido %c", vars->map[rules->lines][rules->index]);
		return (1);
	}
	return (0);
}

int	line_letter(t_vars *vars, t_rules *rules)
{
	rules->player = 0;
	rules->enemy = 0;
	vars->coins = 0;
	rules->exit = 0;
	rules->lines = 1;
	while (rules->lines < rules->last)
	{
		rules->index = 1;
		while (rules->index < rules->len)
		{
			if (line_letter_utils(vars, rules) == 1)
				return (1);
			rules->index++;
		}
		rules->lines++;
	}
	return (0);
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
	if (rules->enemy > 1)
	{
		ft_putstr_fd("Error\nOnly one enemy is allowed.", 2);
		return (1);
	}
	return (0);
}

int	rule_map(t_vars *vars)
{
	t_rules	rules;

	rules.i = 0;
	rules.end = 0;
	rules.last = (vars->map_y / 32) - 1;
	if (len_line(vars, &rules) == 1)
		return (3);
	if (first_and_last(vars, &rules) == 1)
		return (2);
	if (line_letter(vars, &rules) == 1 || number_carac(vars, &rules) == 1)
		return (1);
	rules.l = 1;
	rules.i -= 2;
	while (rules.last > rules.l)
	{
		if (vars->map[rules.j][0] != '1')
			return (2);
		else if (vars->map[rules.j][rules.i] != '1')
			return (2);
		rules.l++;
		rules.j++;
	}
	if (path(vars, &rules) == 1)
		return (1);
	return (0);
}
