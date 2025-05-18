/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ginfranc <ginfranc@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 15:50:24 by ginfranc          #+#    #+#             */
/*   Updated: 2025/05/18 09:23:10 by ginfranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

unsigned int    get_pixel_color(void *img, int x, int y)
{
    int         bpp;
    int         size_line;
    int         endian;
    char        *data;
    int         offset;

    data = mlx_get_data_addr(img, &bpp, &size_line, &endian);
    offset = (y * size_line) + (x * (bpp / 8));
    return (*(unsigned int *)(data + offset));
}

void    draw_trans_img(t_vars *vars, void *img, int posx, int posy)
{
        int x;
        int y;
        unsigned int    color;
        unsigned int    trans_color;

        trans_color = 0x00FF00;
        y = 0;
        while (y < TILE_SIZE)
        {
            x = 0;
            while (x < TILE_SIZE)
            {
                color = get_pixel_color(img, x, y);
                if (color != trans_color)
                    mlx_pixel_put(vars->mlx, vars->win, posx + x, posy +y, color);
                x++;
            }
            y++;
        }
}