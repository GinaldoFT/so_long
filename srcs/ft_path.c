#include "so_long.h"

int    path(t_vars *vars)
{
    int x;
    int i;
    int y;
    int coins;

    coins = 0;
    x = vars->x / TILE_SIZE;
    y = vars->y / TILE_SIZE;

    i = 0;
    while (1)
    {
        while (vars->clone_map[y][x] == '0')
        {
            if (vars->clone_map[y][x + 1] != '1')
                x++;
            else if (vars->clone_map[y][x - 1] != '1')
                x--;
            else if (vars->clone_map[y + 1][x] != '1')
                y++;
            else if (vars->clone_map[y - 1][x] != '1')
                y--;
        }
        if (vars->clone_map[y][x] == 'C')
        {
            coins++;
            vars->clone_map[y][x] = '0';
        }
        if (vars->clone_map[y][x] == 'E' && coins == vars->coins)
            return (0);
        if (i > 500)
            return (0);
        i++;
    }
    return (0);
}