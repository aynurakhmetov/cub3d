/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_sprite.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 18:12:14 by gmarva            #+#    #+#             */
/*   Updated: 2020/11/07 18:12:20 by gmarva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/cub3d.h"

void ft_draw_sprites(t_all *all)
{
	int i;
	int j;

	i = 0;
	t_sprite tmp;
	int len = all->sprites[0].len;
	while (i < len)
	{
		all->sprites[i].dist = sqrt(pow(all->sprites[i].x - all->plr->x, 2) + pow(all->sprites[i].y - all->plr->y, 2));
		tmp = all->sprites[i];
		i++;
	}
	i = 0;
	while (i < len)
	{
		j = 0;
		while (j < len)
		{
			if (all->sprites[i].dist > all->sprites[j].dist)
			{
				tmp = all->sprites[i];
				all->sprites[i] = all->sprites[j];
				all->sprites[j] = tmp;
			}
			j++;
		}
		i++;
	}

	i = 0;
	while (i < len)
	{
		all->text[0].y = all->sprites[i].y;
		all->text[0].x = all->sprites[i].x;
		ft_draw_sprite_2(all);
		i++;
	}

}

void ft_draw_sprite_2(t_all *all)
{   
	float sprite_dir;
	char *color;

	sprite_dir = atan2(all->text[0].y - all->plr->y, all->text[0].x - all->plr->x);
	while (sprite_dir - all->plr->dir >  M_PI) sprite_dir -= 2*M_PI; 
    while (sprite_dir - all->plr->dir < -M_PI) sprite_dir += 2*M_PI;
	sprite_dir -= all->plr->dir;
    float sprite_dist = sqrt(pow(all->text[0].x - all->plr->x, 2) + pow(all->text[0].y - all->plr->y, 2)); 
    float sprite_screen_size = (SCALE / sprite_dist) * (all->mapinfo->xrendersize / 2) / tan(FOV/2);
	int h_offset = all->mapinfo->xrendersize/ (FOV * (180 / M_PI)) * ((180 / M_PI * sprite_dir) + 30) - sprite_screen_size / 2;
    int v_offset = all->mapinfo->yrendersize / 2 - sprite_screen_size / 2;
	float j = 0;
	float i = 0;
	float step; 
	step = all->text[0].img_height / sprite_screen_size;
	int				tex_y;
	int				tex_x;
	float			tex_pos = 0;
	tex_pos = 0;

	while (i < sprite_screen_size)
	{
        if (h_offset + i < 0 || h_offset + i >= all->mapinfo->xrendersize || all->dist_wall[(int)(h_offset + i)] < sprite_dist )
		{
			i++;
			continue;
		}
		tex_x = i / sprite_screen_size * all->text[0].img_width;
		tex_pos = 0;
		j = 0;
        while (j < sprite_screen_size) 
		{
			tex_y = (unsigned int)tex_pos & (all->text[0].img_height - 1);
			color = all->text[0].addr + ((int)tex_y * all->text[0].line_length + ((int)(tex_x ) * (all->text[0].bits_per_pixel/ 8)));
            if (v_offset + j < 0 || v_offset + j > all->mapinfo->yrendersize)
			{
				j++;
				continue;
			}
			tex_pos += step;
        	if (*(int *)color)
			{
				ft_draw(all,  v_offset + j, h_offset +  i, *(int *)color);
			}	
			j++;
        }
		i++;
	}
}
