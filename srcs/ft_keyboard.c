/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keyboard.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 13:39:28 by gmarva            #+#    #+#             */
/*   Updated: 2020/10/26 13:39:30 by gmarva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/cub3d.h"

int		key_press(int keycode, t_all *all)
{
	t_point m;


	m.y = all->plr->y;
	m.x = all->plr->x;

	if (keycode == KEY_W)
    {
		m.y += 32 * sin(all->plr->dir);
		m.x += 32 * cos(all->plr->dir);
    }
	if (keycode == KEY_S)
	{
        m.y -= 32 * sin(all->plr->dir);
		m.x -= 32 * cos(all->plr->dir);
	}
	if (keycode == KEY_A)
	{
        m.y -= 32 * cos(all->plr->dir);
		m.x += 32 * sin(all->plr->dir);
	}
	if (keycode == KEY_D)
	{
        m.y += 32 * cos(all->plr->dir);
		m.x -= 32 * sin(all->plr->dir);	
	}
	if (all->map[(int)(m.y/ SCALE)][(int)(m.x/ SCALE)] != '1' && all->map[(int)(m.y/ SCALE)][(int)(m.x / SCALE)] != '2' )
	{
        all->plr->y = m.y;
		all->plr->x = m.x;
	}	
	if (keycode == KEY_LEFT)
	    all->plr->dir -= 0.1;
	if (keycode == KEY_RIGHT)
		all->plr->dir += 0.1;
	if (keycode == KEY_ESCAPE)
	{
		mlx_destroy_window(all->win->mlx, all->win->win);
		exit(0);
		// Написать нормальную функцию закрывающуюся
	}	
	ft_render_next_frame(all);
	ft_cub_2d(all);
	return (0);
}