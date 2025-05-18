/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_rules.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ginfranc <ginfranc@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 08:54:10 by ginfranc          #+#    #+#             */
/*   Updated: 2025/05/18 10:54:02 by ginfranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int len_line(t_vars *vars, t_rules *rules)
{
    int i;

    i = 1;
    rules->len = ft_strlen(vars->map[0]);
    while (i < rules->last)
    {
        if (ft_strlen(vars->map[i]) != rules->len)
            return(1);
        i++;
    }
    rules->len -= 1;
    if (ft_strlen(vars->map[rules->last]) != rules->len)
        return (1);
    return (0);
}

int first_and_last(t_vars *vars, t_rules *rules)
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

int line_letter(t_vars *vars, t_rules *rules)
{
    int lines;
    size_t i;

    lines = 1;
    while (lines < rules->last)
    {
        i = 1;
        while (i < rules->len)
        {
            if (vars->map[lines][i] != 'P' && vars->map[lines][i] != '1' && vars->map[lines][i] != 'E' && vars->map[lines][i] != 'C' && vars->map[lines][i] != '0' && vars->map[lines][i] != '\n')
            {
                ft_printf("Caracterer invalido: %c", vars->map[lines][i]);
                return (1);
            }
            i++;
        }
        lines++;
    }
    return (0);
}

int rule_map(t_vars *vars)
{
    t_rules rules;

    rules.i = 0;
    rules.end = 0;
    rules.last = (vars->map_y / 32) - 1;
    if (len_line(vars, &rules) == 1)
        return (3);
    if (first_and_last(vars, &rules) == 1)
        return (2);
    if (line_letter(vars, &rules) == 1)
        return (1);
    rules.j = 1;
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
	return (0);
}