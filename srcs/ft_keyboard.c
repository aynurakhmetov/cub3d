/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keyboard.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarva <gmarva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 13:39:28 by gmarva            #+#    #+#             */
/*   Updated: 2020/11/08 17:57:58 by gmarva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/cub3d.h"

t_point	ft_get_new_plr(int keycode, t_all *all)
{
	t_point new;

	new.y = all->plr->y;
	new.x = all->plr->x;
	if (keycode == KEY_W)
	{
		new.y += (SCALE * 0.66) * sin(all->plr->dir);
		new.x += (SCALE * 0.66) * cos(all->plr->dir);
	}
	if (keycode == KEY_S)
	{
		new.y -= (SCALE * 0.66) * sin(all->plr->dir);
		new.x -= (SCALE * 0.66) * cos(all->plr->dir);
	}
	if (keycode == KEY_A)
	{
		new.y -= (SCALE * 0.66) * cos(all->plr->dir);
		new.x += (SCALE * 0.66) * sin(all->plr->dir);
	}
	if (keycode == KEY_D)
	{
		new.y += (SCALE * 0.66) * cos(all->plr->dir);
		new.x -= (SCALE * 0.66) * sin(all->plr->dir);
	}
	return (new);
}

int		ft_slit_check_plr(t_point ray, t_all *all)
{
	t_point test;
	t_point test2;

	if (all->map[(int)(ray.y / (SCALE))][(int)(ray.x / (SCALE))] == '0')
	{
		test.x = ray.x - cos(all->plr->dir) * (SCALE / 2);
		test.y = ray.y + sin(all->plr->dir) * (SCALE / 2);
		test2.x = ray.x + cos(all->plr->dir) * (SCALE / 2);
		test2.y = ray.y - sin(all->plr->dir) * (SCALE / 2);
		if (all->map[(int)(test.y / (SCALE))][(int)(test.x / (SCALE))] == '1'
	&& all->map[(int)(test2.y / (SCALE))][(int)(test2.x / (SCALE))] == '1')
			return (0);
		if (all->map[(int)(test.y / (SCALE))][(int)(test.x / (SCALE))] == '2'
	&& all->map[(int)(test2.y / (SCALE))][(int)(test2.x / (SCALE))] == '2')
			return (0);
	}
	return (1);
}

int		ft_key_press(int keycode, t_all *all)
{
	t_point new;

	new = ft_get_new_plr(keycode, all);
	if (all->map[(int)(new.y / SCALE)][(int)(new.x / SCALE)] != '1'
		&& all->map[(int)(new.y / SCALE)][(int)(new.x / SCALE)] != '2'
		&& ft_slit_check_plr(new, all) != 0)
	{
		all->plr->y = new.y;
		all->plr->x = new.x;
	}
	if (keycode == KEY_LEFT)
		all->plr->dir -= 0.1;
	if (keycode == KEY_RIGHT)
		all->plr->dir += 0.1;
	if (keycode == KEY_ESCAPE)
	{
		mlx_destroy_window(all->win->mlx, all->win->win);
		ft_finish_game(all);
	}
	ft_render_next_frame(all);
	return (0);
}
