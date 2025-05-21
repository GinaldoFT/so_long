#include "so_long.h"

void    flood_fill(int x, int y, t_vars *vars)
{
    if (vars->clone_map[y][x] == '1' || vars->clone_map[y][x] == 'X')
        return ;
    vars->clone_map[y][x] = 'X';
    flood_fill(x + 1, y, vars);
    flood_fill(x - 1, y, vars);
    flood_fill(x, y + 1, vars);
    flood_fill(x, y - 1, vars);
}

int clone_map(t_vars *vars, t_rules *rules)
{
    int lines;
    size_t index;

    lines = 1;
	while (lines < rules->last)
	{
		index = 1;
		while (index < rules->len)
		{
			if (vars->clone_map[lines][index] == 'P' ||\
                vars->clone_map[lines][index] == 'E' ||\
                vars->clone_map[lines][index] == 'C')
			{
				return (1);
			}
            index++;
		}
		lines++;
	}
	return (0);
}

int path(t_vars *vars, t_rules *rules)
{
    int x;
    int y;

    x = vars->x / TILE_SIZE;
    y = vars->y / TILE_SIZE;
    flood_fill(x,  y, vars);
    if (clone_map(vars, rules) == 1)
    {
        ft_putstr_fd("\nError\nSem caminho valido", 2);
        return (1);
    }
    return (0);
}