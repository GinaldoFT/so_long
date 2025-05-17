#include "so_long.h"

int    rule_map(t_vars *vars)
{
    int i;
    int end;
    int last;
    int j;
    int l;

    i = 0;
    end = 0;
    last = (vars->map_y / 32) - 1;
    
    while (vars->map[0][i])
	{
		if (vars->map[0][i] != '1' && vars->map[0][i] != '\n')
			return (1);
		i++;
	}
    j = 1;
    l = 1;
    i -= 2;
    while (last > l)
    {
        if (vars->map[j][0] != '1')
        {
            ft_printf("if 1");
            return (1);
        }
        else if (vars->map[j][i] != '1')
        {
            ft_printf("if 2\n%i", i);
            return (1);
        }
        l++;
        j++;
    }
    while (vars->map[last][end])
	{
		if (vars->map[last][end] != '1' && vars->map[last][end] != '\n')
			return (1);
		end++;
	}
	return (0);
}