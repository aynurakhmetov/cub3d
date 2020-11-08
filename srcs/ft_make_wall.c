/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_wall.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarva <gmarva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 13:46:53 by gmarva            #+#    #+#             */
/*   Updated: 2020/11/08 17:46:06 by gmarva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/cub3d.h"

int		ft_get_num_of_texture(t_all *all)
{
	int textnum;

	textnum = 0;
	if (all->new_dir == 'N')
		textnum = 1;
	if (all->new_dir == 'S')
		textnum = 2;
	if (all->new_dir == 'W')
		textnum = 3;
	if (all->new_dir == 'E')
		textnum = 4;
	return (textnum);
}

float	ft_get_hit(t_all *all, t_wall wall)
{
	float hit;

	if (all->new_dir == 'N' || all->new_dir == 'S')
		hit = fmod(wall.x_draw, SCALE) / SCALE;
	if (all->new_dir == 'W' || all->new_dir == 'E')
		hit = fmod(wall.y_draw, SCALE) / SCALE;
	return (hit);
}

int		ft_get_wall_color(t_all *all, t_wall wall, int i)
{
	int		h;
	int		w;
	float	hit;
	int		textnum;
	char	*color;

	h = 0;
	w = 0;
	textnum = ft_get_num_of_texture(all);
	hit = ft_get_hit(all, wall);
	w = all->text[textnum].img_width * hit;
	while (wall.start < wall.end)
	{
		if (wall.start >= 0)
		{
			color = ft_get_texture_color(all, (h *
			all->text[textnum].img_height) / wall.height, w, textnum);
			ft_draw(all, wall.start, i, *(int *)color);
		}
		h++;
		wall.start++;
	}
	return (0);
}

t_wall	ft_get_wall_info(t_all *all, t_plr ray, int i)
{
	t_wall wall;

	all->new_dir = ft_get_new_dir(ray, all);
	wall.y_draw = ray.y;
	wall.x_draw = ray.x;
	wall.angle = ray.start;
	wall.distance = sqrt(pow(wall.x_draw - all->plr->x, 2) +
		pow(wall.y_draw - all->plr->y, 2)) * cos(wall.angle - all->plr->dir);
	all->dist_wall[i] = wall.distance;
	wall.perpendicular = (all->mapinfo->xrendersize / 2.0) / tan(FOV / 2);
	wall.height = (SCALE / wall.distance) * wall.perpendicular;
	wall.start = all->mapinfo->yrendersize / 2.0 - wall.height / 2.0;
	wall.end = wall.height + wall.start;
	if (wall.end > all->mapinfo->yrendersize)
		wall.end = all->mapinfo->yrendersize;
	return (wall);
}

void	ft_draw_wall(t_all *all, t_plr ray, int i)
{
	t_wall	wall;
	int		j;

	wall = ft_get_wall_info(all, ray, i);
	j = 0;
	while (j < wall.start)
	{
		ft_draw(all, j, i, all->mapinfo->ceilingcolor);
		j++;
	}
	wall.wall_color = ft_get_wall_color(all, wall, i);
	while (wall.end < all->mapinfo->yrendersize)
	{
		ft_draw(all, wall.end, i, all->mapinfo->floorcolor);
		wall.end++;
	}
}
