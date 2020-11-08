/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 17:16:15 by gmarva            #+#    #+#             */
/*   Updated: 2020/11/07 18:14:05 by gmarva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/cub3d.h"


char	ft_find_new_dir(t_all *all, t_plr test_plr, t_plr ray, char *dir)
{
	if (all->map[(int)(ray.y / SCALE)][(int)(test_plr.x / SCALE)] == '1')
		return (dir[0]);
	if (all->map[(int)(test_plr.y / SCALE)][(int)(ray.x / SCALE)] == '1')
		return (dir[1]);
	if (all->map[(int)(ray.y / SCALE)][(int)(ray.x / SCALE)] == '1')
		return (dir[0]);
	return (all->plr->dir);
}

t_plr 	ft_get_new_coordinates(t_plr ray)
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

void	ft_draw_wall_after_sprite(t_all *all, t_plr ray, int i)
{
	while (all->map[(int)(ray.y / SCALE)][(int)(ray.x / SCALE)] != '1')
	{
			ray.x += cos(ray.start);
			ray.y += sin(ray.start);
	}
	ft_draw_wall(all, ray, i);	
}

void	ft_cast_rays(t_all *all)
{
	t_plr	ray;
	int i;

	ray = *all->plr;
	ray.start = ray.dir - ((FOV)/2); 
    ray.end = ray.dir + ((FOV)/2); 
	i = 0;
    while (ray.start <= ray.end && i < all->mapinfo->xrendersize)
    {
		ray.x = all->plr->x;
		ray.y = all->plr->y;
		while (all->map[(int)(ray.y / SCALE)][(int)(ray.x / SCALE)] != '1'
			&& all->map[(int)(ray.y / SCALE)][(int)(ray.x / SCALE)] != '2')
		{
			ray.x += cos(ray.start);
			ray.y += sin(ray.start);
			//ft_draw(all, ray.y / (SCALE / 10.0), ray.x / (SCALE / 10.0), 0x00990099);
		} 
		if (all->map[(int)(ray.y / SCALE)][(int)(ray.x / SCALE)] == '2')
			ft_draw_wall_after_sprite(all, ray, i);
		else
			ft_draw_wall(all, ray, i);
		i++;
		ray.start += FOV / all->mapinfo->xrendersize;
	}
}
