#include "./../includes/cub3d.h"

void	ft_draw(t_all *all, float i, float j, int color)
{
	unsigned int *dst;

	dst = all->win->addr + ((int)i * all->win->line_length
	+ (int)j * (all->win->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

char	*ft_get_texture_color(t_all *all, int h, int w, int textmum)
{
	char *color;

	color = all->text[textmum].addr + ((int)h * all->text[textmum].line_length
	+ (int)w * (all->text[textmum].bits_per_pixel / 8));
	return (color);
}

void	ft_draw_wall_after_sprite(t_all *all, t_plr ray, int i)
{
	while (all->map[(int)(ray.y / (SCALE))][(int)(ray.x / (SCALE))] != '1')
	{
		ray.x += cos(ray.start);
		ray.y += sin(ray.start);
	}
	ft_draw_wall(all, ray, i);
}
