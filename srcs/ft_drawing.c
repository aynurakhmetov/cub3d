/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drawing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 18:11:28 by gmarva            #+#    #+#             */
/*   Updated: 2020/11/07 18:11:43 by gmarva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/cub3d.h"

void    ft_draw(t_all *all, float i, float j, int color)
{
    unsigned int   *dst;

    dst = all->win->addr + ((int)i * all->win->line_length + (int)j * (all->win->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

void    ft_cub_2d(t_all *all)
{
    float i;
    float j;
    int sc;

    i = 0;
    sc = 10;
    while (all->map[(int)(i / sc)])
    {
        j = 0;
        while (all->map[(int)(i / sc)][(int)(j / sc)])
        {
            if (all->map[(int)(i / sc)][(int)(j / sc)] == '1')
                ft_draw(all, i, j, 0x000000FF);
            if (all->map[(int)(i / sc)][(int)(j / sc)] == '2')
                ft_draw(all, i, j, 0x0000FFFF);
            if (all->map[(int)(i / sc)][(int)(j / sc)] >= 'E' && all->map[(int)(i / sc)][(int)(j / sc)] <= 'W')
                ft_draw(all, i, j, 0x0000FF88);
            j++;
        }
        i++;
    }
    ft_draw(all, all->plr->y / (6.4), all->plr->x / (6.4), 0x00AA00FF);
    float x = all->plr->x / (6.4);
    float y = all->plr->y / (6.4);
    float x_end = x + 64;
    float y_end = y + 64;
    while (y < y_end)
    {
        x = all->plr->x;
        while (x < x_end)
        {
            ft_draw(all, y, x, 0x00AA00FF);
            x++;
        }
        y++;
    }
}