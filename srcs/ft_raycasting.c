/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 17:16:15 by gmarva            #+#    #+#             */
/*   Updated: 2020/10/26 17:16:17 by gmarva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/cub3d.h"

/*
void	ft_cast_ray(t_all *all)
{
	t_plr	ray = *all->plr; // задаем координаты луча равные координатам игрока

    ft_draw(all, ray.y, ray.x, 0x0000FF00);
	while (all->map[(int)(ray.y / SCALE)][(int)(ray.x / SCALE)] != '1')
	{
		ray.x += cos(ray.dir);
		ray.y += sin(ray.dir);
		ft_draw(all, ray.y, ray.x, 0x00990099);
	}
}x
*/

char	ft_get_new_dir(t_plr ray, t_all *all)
{
	char new_dir;
	t_plr test_plr;
	//LV
	float k = 1;

	new_dir = 'O';
	if (sin(ray.start) <= 0 && cos(ray.start) <= 0)
	{
		test_plr.x = ray.x + k;
		test_plr.y = ray.y + k;
		//printf ("tut 1, \n");
		if (all->map[(int)(ray.y / SCALE)][(int)(test_plr.x / SCALE)] == '1')
			return ('N');
		if (all->map[(int)(test_plr.y / SCALE)][(int)(ray.x / SCALE)] == '1')
			return ('W');
		if (all->map[(int)(ray.y / SCALE)][(int)(ray.x / SCALE)] == '1')
			return ('W');
		//printf ("tut 2\n");
	}

	//PV
	if (sin(ray.start) <= 0 && cos(ray.start) >= 0)
	{
		test_plr.x = ray.x - k;
		test_plr.y = ray.y + k;
		if (all->map[(int)(ray.y / SCALE)][(int)(test_plr.x/ SCALE)] == '1')
			return ('N');
		if (all->map[(int)(test_plr.y/ SCALE)][(int)(ray.x/ SCALE)] == '1')
			return ('E');
		if (all->map[(int)(ray.y / SCALE)][(int)(ray.x / SCALE)] == '1')
			return ('N');
	}

	//NP
	if (sin(ray.start) >= 0 && cos(ray.start) >= 0)
	{
		test_plr.x = ray.x - k;
		test_plr.y = ray.y - k;
		if (all->map[(int)(ray.y / SCALE)][(int)(test_plr.x/ SCALE)] == '1')
			return ('S');
		if (all->map[(int)(test_plr.y/ SCALE)][(int)(ray.x/ SCALE)] == '1')
			return ('E');
		if (all->map[(int)(ray.y / SCALE)][(int)(ray.x / SCALE)] == '1')
			return ('E');
	}

	//NL
	if (sin(ray.start) >= 0 && cos(ray.start) <= 0)
	{
		test_plr.x = ray.x + k;
		test_plr.y = ray.y - k;
		if (all->map[(int)(ray.y / SCALE)][(int)(test_plr.x/ SCALE)] == '1')
			return ('S');
		if (all->map[(int)(test_plr.y/ SCALE)][(int)(ray.x/ SCALE)] == '1')
			return ('W');
		if (all->map[(int)(ray.y / SCALE)][(int)(ray.x / SCALE)] == '1')
			return ('S');
	}

	return (new_dir);
}

void	ft_cast_rays(t_all *all)
{
    t_plr	ray = *all->plr; // задаем координаты и направление луча равные координатам игрока
	ray.start = ray.dir - ((FOV)/2); // начало веера лучей
    ray.end = ray.dir + ((FOV)/2); // край веера лучей
	int i;
	t_plr s;

	i = 0;
	//printf("ya tut 4\n");
	// Собрать информацию для отрисовки
    while (ray.start <= ray.end && i < all->mapInfo->xRenderSize)
    {
		ray.x = all->plr->x; // каждый раз возвращаемся в точку начала
		ray.y = all->plr->y;
		//printf("ya tut 9\n");
		while (all->map[(int)(ray.y / SCALE)][(int)(ray.x / SCALE)] != '1' && all->map[(int)(ray.y / SCALE)][(int)(ray.x / SCALE)] != '2')
		{
			ray.x += cos(ray.start);
			ray.y += sin(ray.start);
			ft_draw(all, ray.y/6.4, ray.x/6.4, 0x00990099);
		}
		all->new_dir = ft_get_new_dir(ray, all);
		//printf("dir %c\n", all->new_dir);
		if (all->map[(int)(ray.y/ SCALE)][(int)(ray.x / SCALE)] == '2')
		{
			s = ray;
			while (all->map[(int)(ray.y / SCALE)][(int)(ray.x / SCALE)] != '1')
			{
				ray.x += cos(ray.start);
				ray.y += sin(ray.start);
			}
			all->new_dir = ft_get_new_dir(ray, all);
			ft_draw_wall(all, ray.y, ray.x, i, ray.start);
		 	//ft_draw_sprite(all, s.y, s.x, i, s.start, s);	
		}
		else
		{
			ft_draw_wall(all, ray.y, ray.x, i, ray.start);
		}
		
		//printf("ya tut 69n");
		i++;
		ray.start += FOV / all->mapInfo->xRenderSize;
	}
	//printf("ya tut 3\n");
}
