/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarva <gmarva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 17:16:15 by gmarva            #+#    #+#             */
/*   Updated: 2020/11/09 18:56:39 by gmarva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/cub3d.h"

char	ft_find_new_dir(t_all *all, t_plr test_plr, t_plr ray, char *dir)
{
	t_plr test;
	t_plr test2;

	if (all->map[(int)(ray.y / SCALE)][(int)(test_plr.x / SCALE)] == '1')
		return (dir[0]);
	if (all->map[(int)(test_plr.y / SCALE)][(int)(ray.x / SCALE)] == '1')
		return (dir[1]);
	if (all->map[(int)(ray.y / SCALE)][(int)(ray.x / SCALE)] == '1')
		return (dir[0]);
	if (all->map[(int)(ray.y / (SCALE))][(int)(ray.x / (SCALE))] == '0')
	{
		test.x = ray.x - cos(ray.start);
		test.y = ray.y + sin(ray.start);
		test2.x = ray.x + cos(ray.start);
		test2.y = ray.y - sin(ray.start);
		if (all->map[(int)(test.y / (SCALE))][(int)(test.x / (SCALE))] == '1'
	&& all->map[(int)(test2.y / (SCALE))][(int)(test2.x / (SCALE))] == '1')
			return (dir[0]);
	}
	return (all->plr->dir);
}

t_plr	ft_get_new_coordinates(t_plr ray)
{
	t_plr test_plr;
	float k;

	k = 1;
	if (sin(ray.start) <= 0 && cos(ray.start) <= 0)
	{
		test_plr.x = ray.x + k;
		test_plr.y = ray.y + k;
	}
	if (sin(ray.start) <= 0 && cos(ray.start) >= 0)
	{
		test_plr.x = ray.x - k;
		test_plr.y = ray.y + k;
	}
	if (sin(ray.start) >= 0 && cos(ray.start) >= 0)
	{
		test_plr.x = ray.x - k;
		test_plr.y = ray.y - k;
	}
	if (sin(ray.start) >= 0 && cos(ray.start) <= 0)
	{
		test_plr.x = ray.x + k;
		test_plr.y = ray.y - k;
	}
	return (test_plr);
}

char	ft_get_new_dir(t_plr ray, t_all *all)
{
	t_plr test_plr;
	float new_dir;

	new_dir = all->plr->dir;
	test_plr = ft_get_new_coordinates(ray);
	if (sin(ray.start) <= 0 && cos(ray.start) <= 0)
		new_dir = ft_find_new_dir(all, test_plr, ray, "NW");
	if (sin(ray.start) <= 0 && cos(ray.start) >= 0)
		new_dir = ft_find_new_dir(all, test_plr, ray, "NE");
	if (sin(ray.start) >= 0 && cos(ray.start) >= 0)
		new_dir = ft_find_new_dir(all, test_plr, ray, "SE");
	if (sin(ray.start) >= 0 && cos(ray.start) <= 0)
		new_dir = ft_find_new_dir(all, test_plr, ray, "SW");
	return (new_dir);
}

int		ft_slit_check(t_plr ray, t_all *all, int i)
{
	t_plr test;
	t_plr test2;

	if (all->map[(int)(ray.y / (SCALE))][(int)(ray.x / (SCALE))] == '0')
	{
		test.x = ray.x - cos(ray.start);
		test.y = ray.y + sin(ray.start);
		test2.x = ray.x + cos(ray.start);
		test2.y = ray.y - sin(ray.start);
		if (all->map[(int)(test.y / (SCALE))][(int)(test.x / (SCALE))] == '1'
	&& all->map[(int)(test2.y / (SCALE))][(int)(test2.x / (SCALE))] == '1')
		{
			ft_draw_wall(all, ray, i);
			return (0);
		}
	}
	return (1);
}

void	ft_cast_rays(t_all *all)
{
	t_plr	ray;
	int		i;

	ray = *all->plr;
	ray.start = ray.dir - ((FOV) / 2);
	ray.end = ray.dir + ((FOV) / 2);
	i = 0;
	while (ray.start <= ray.end && i < all->mapinfo->xrendersize)
	{
		ray.x = all->plr->x;
		ray.y = all->plr->y;
		while (all->map[(int)(ray.y / (SCALE))][(int)(ray.x / (SCALE))] != '1'
			&& all->map[(int)(ray.y / (SCALE))][(int)(ray.x / (SCALE))] != '2'
			&& ft_slit_check(ray, all, i) != 0)
		{
			ray.x += cos(ray.start);
			ray.y += sin(ray.start);
		}
		if (all->map[(int)(ray.y / (SCALE))][(int)(ray.x / (SCALE))] == '2')
			ft_draw_wall_after_sprite(all, ray, i);
		else
			ft_draw_wall(all, ray, i);
		i++;
		ray.start += FOV / (all->mapinfo->xrendersize);
	}
}
