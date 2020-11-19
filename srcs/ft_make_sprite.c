/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_sprite.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarva <gmarva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 18:12:14 by gmarva            #+#    #+#             */
/*   Updated: 2020/11/09 18:58:10 by gmarva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/cub3d.h"

void			ft_sprite_sorting(t_all *all, int len)
{
	int			i;
	int			j;
	t_sprite	tmp;

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
}

t_spriteinfo	ft_get_one_sprite_info(t_all *all)
{
	t_spriteinfo	sprite;

	sprite.dir = atan2(all->text[0].y - all->plr->y,
		all->text[0].x - all->plr->x);
	while (sprite.dir - all->plr->dir > M_PI)
		sprite.dir -= 2 * M_PI;
	while (sprite.dir - all->plr->dir < (-M_PI))
		sprite.dir += 2 * M_PI;
	sprite.dir -= all->plr->dir;
	sprite.distance = sqrt(pow(all->text[0].x - all->plr->x, 2)
	+ pow(all->text[0].y - all->plr->y, 2));
	sprite.screen_size = (SCALE / sprite.distance)
	* (all->mapinfo->xrendersize / 2) / tan(FOV / 2);
	if (sprite.screen_size > all->mapinfo->yrendersize)
		sprite.screen_size = all->mapinfo->yrendersize;
	sprite.h_offset = all->mapinfo->xrendersize / (FOV * (180 / M_PI))
	* ((180 / M_PI * sprite.dir) + 30) - sprite.screen_size / 2;
	sprite.v_offset = all->mapinfo->yrendersize / 2 - sprite.screen_size / 2;
	sprite.step = all->text[0].img_height / sprite.screen_size;
	sprite.pos = 0;
	return (sprite);
}

void			ft_j_count(t_all *all, t_spriteinfo *sprite, float i)
{
	char	*color;
	float	j;

	j = 0;
	sprite->x = i / sprite->screen_size * all->text[0].img_width;
	sprite->pos = 0;
	while (j < sprite->screen_size)
	{
		sprite->y = (unsigned int)sprite->pos & (all->text[0].img_height - 1);
		color = ft_get_texture_color(all, sprite->y, sprite->x, 0);
		if (sprite->v_offset + j < 0 || sprite->v_offset + j
			> all->mapinfo->yrendersize)
		{
			j++;
			continue;
		}
		if (*(int *)color)
			ft_draw(all, sprite->v_offset + j, sprite->h_offset + i,
			*(int *)color);
		sprite->pos += sprite->step;
		j++;
	}
}

void			ft_draw_one_sprite(t_all *all)
{
	float			i;
	t_spriteinfo	sprite;

	i = 0;
	sprite = ft_get_one_sprite_info(all);
	while (i < sprite.screen_size)
	{
		if (sprite.h_offset + i < 0 || sprite.h_offset + i
		>= all->mapinfo->xrendersize ||
		all->dist_wall[(int)(sprite.h_offset + i)] < sprite.distance)
		{
			i++;
			continue;
		}
		ft_j_count(all, &sprite, i);
		i++;
	}
}

void			ft_draw_sprites(t_all *all)
{
	int i;
	int len;

	i = 0;
	len = all->spritelen;
	while (i < len)
	{
		all->sprites[i].dist = sqrt(pow(all->sprites[i].x - all->plr->x, 2) +
			pow(all->sprites[i].y - all->plr->y, 2));
		i++;
	}
	ft_sprite_sorting(all, len);
	i = 0;
	while (i < len)
	{
		all->text[0].y = all->sprites[i].y;
		all->text[0].x = all->sprites[i].x;
		ft_draw_one_sprite(all);
		i++;
	}
}
