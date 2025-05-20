#include "so_long.h"

void    load_imgs_bonus(t_vars *vars, t_anims *anims)
{
    anims->coin2 = mlx_xpm_file_to_image(vars->mlx, COIN2, &vars->img_w, &vars->img_h);
	if (!anims->coin2)
		ft_printf("Erro ao Carregar Coin2!");
	anims->coin3 = mlx_xpm_file_to_image(vars->mlx, COIN3, &vars->img_w, &vars->img_h);
	if (!anims->coin3)
		ft_printf("Erro ao Carregar Coin3!");
	anims->coin4 = mlx_xpm_file_to_image(vars->mlx, COIN4, &vars->img_w, &vars->img_h);
	if (!anims->coin4)
		ft_printf("Erro ao Carregar Coin4!");
	
}

void    animation_coin(t_vars *vars, t_anims *anims, int x, int y)
{
    if (vars->map[y][x] == 'C')
    {
        draw_trans_img(vars, vars->img_coin, x * TILE_SIZE, y * TILE_SIZE);
        draw_trans_img(vars, anims->coin2, x * TILE_SIZE, y * TILE_SIZE);
        draw_trans_img(vars, anims->coin3, x * TILE_SIZE, y * TILE_SIZE);
        draw_trans_img(vars, anims->coin4, x * TILE_SIZE, y * TILE_SIZE);
    }
}