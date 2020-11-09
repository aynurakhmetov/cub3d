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
		new.y += (SCALE) * sin(all->plr->dir);
		new.x += (SCALE) * cos(all->plr->dir);
	}
	if (keycode == KEY_S)
	{
		new.y -= (SCALE) * sin(all->plr->dir);
		new.x -= (SCALE) * cos(all->plr->dir);
	}
	if (keycode == KEY_A)
	{
		new.y -= (SCALE) * cos(all->plr->dir);
		new.x += (SCALE) * sin(all->plr->dir);
	}
	if (keycode == KEY_D)
	{
		new.y += (SCALE) * cos(all->plr->dir);
		new.x -= (SCALE) * sin(all->plr->dir);
	}
	return (new);
}

int		ft_key_press(int keycode, t_all *all)
{
	t_point new;

	new = ft_get_new_plr(keycode, all);
	if (all->map[(int)(new.y / SCALE)][(int)(new.x / SCALE)] != '1'
		&& all->map[(int)(new.y / SCALE)][(int)(new.x / SCALE)] != '2')
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
