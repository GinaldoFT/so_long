#include "so_long.h"

void    load_imgs_bonus(t_vars *vars)
{
    vars->img_coin[1] = mlx_xpm_file_to_image(vars->mlx, COIN2, &vars->img_w, &vars->img_h);
	if (!vars->img_coin[1])
		ft_printf("Erro ao Carregar Coin2!");
	vars->img_coin[2] = mlx_xpm_file_to_image(vars->mlx, COIN3, &vars->img_w, &vars->img_h);
	if (!vars->img_coin[2])
		ft_printf("Erro ao Carregar Coin3!");
	vars->img_coin[3] = mlx_xpm_file_to_image(vars->mlx, COIN4, &vars->img_w, &vars->img_h);
	if (!vars->img_coin[3])
		ft_printf("Erro ao Carregar Coin4!");
	
}

void    animation_coin(t_vars *vars, int x, int y)
{
    if (vars->count++ == x + y)
    {
        
    }
}