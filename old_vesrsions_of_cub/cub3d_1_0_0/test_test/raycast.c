#include "cub.h"
#include "minilibx_mms/mlx.h"

void	ft_cast_ray(t_all *all)
{
	t_plr	ray = *all->plr; // задаем координаты луча равные координатам игрока

	while (all->map[(int)(ray.y / SCALE)][(int)(ray.x / SCALE)] != '1')
	{
		ray.x += cos(ray.dir);
		ray.y += sin(ray.dir);
		mlx_pixel_put(all->mlx, all->win, ray.x, ray.y, 0x990099);
	}
}

void	ft_cast_rays(t_all *all)
{
	t_plr	ray = *all->plr; // задаем координаты и направление луча равные координатам игрока
	float start = ray.dir - [половина угла обзора]; // начало веера лучей
  float end = ray.dir + [половина угла обзора]; // край веера лучей

  while (ray.start <= ray.end)
	{
		ray.x = all->plr->x; // каждый раз возвращаемся в точку начала
		ray.y = all->plr->y;
		while (all->map[(int)(ray.y / SCALE)][(int)(ray.x / SCALE)] != '1')
		{
			ray.x += cos(ray.start);
			ray.y += sin(ray.start);
			mlx_pixel_put(all->mlx, all->win, ray.x, ray.y, 0x990099);
		}
		ray.start += [угол обзора] / [количество лучей];
	}
}