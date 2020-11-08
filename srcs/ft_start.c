/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_game.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 13:07:41 by gmarva            #+#    #+#             */
/*   Updated: 2020/11/07 18:12:47 by gmarva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/cub3d.h"

int		ft_render_next_frame(t_all *all)
{
	ft_cast_rays(all);
	ft_draw_sprites(all);
	//ft_cub_2d(all);
	mlx_put_image_to_window(all->win->mlx, all->win->win, all->win->img, 0, 0);
	return (0);
}

void	ft_get_addr_img_text(t_all *all)
{
	all->text[0].image = mlx_xpm_file_to_image(all->win->mlx,
all->mapinfo->spritetexture, &all->text[0].img_width, &all->text[0].img_height);
	all->text[0].addr = (unsigned int*)mlx_get_data_addr(all->text[0].image,
&all->text[0].bits_per_pixel, &all->text[0].line_length, &all->text[0].endian);
	all->text[1].image = mlx_xpm_file_to_image(all->win->mlx,
all->mapinfo->northtexture, &all->text[1].img_width, &all->text[1].img_height);
	all->text[1].addr = (unsigned int*)mlx_get_data_addr(all->text[1].image,
&all->text[1].bits_per_pixel, &all->text[1].line_length, &all->text[1].endian);
	all->text[2].image = mlx_xpm_file_to_image(all->win->mlx,
all->mapinfo->southtexture, &all->text[2].img_width, &all->text[2].img_height);
	all->text[2].addr = (unsigned int*)mlx_get_data_addr(all->text[2].image,
&all->text[2].bits_per_pixel, &all->text[2].line_length, &all->text[2].endian);
	all->text[3].image = mlx_xpm_file_to_image(all->win->mlx,
all->mapinfo->westtexture, &all->text[3].img_width, &all->text[3].img_height);
	all->text[3].addr = (unsigned int*)mlx_get_data_addr(all->text[3].image,
&all->text[3].bits_per_pixel, &all->text[3].line_length, &all->text[3].endian);
	all->text[4].image = mlx_xpm_file_to_image(all->win->mlx,
all->mapinfo->easttexture, &all->text[4].img_width, &all->text[4].img_height);
	all->text[4].addr = (unsigned int*)mlx_get_data_addr(all->text[4].image,
&all->text[4].bits_per_pixel, &all->text[4].line_length, &all->text[4].endian);
}

void	ft_start_game(t_map mapinfo, int savebmp)
{
	t_win	data;
	t_all	all;

	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, mapinfo.xrendersize,
				mapinfo.yrendersize, "CUB3D");
	all = ft_get_all_info(mapinfo, data);
	all.win->img = mlx_new_image(all.win->mlx, all.mapinfo->xrendersize,
		all.mapinfo->yrendersize);
	all.win->addr = (unsigned int*)mlx_get_data_addr(all.win->img,
			&all.win->bits_per_pixel, &all.win->line_length, &all.win->endian);
	ft_get_addr_img_text(&all);
	ft_render_next_frame(&all);
	if (savebmp == 1)
	{
		ft_screenshot(&all);
		ft_finish_game(&all);
	}
	mlx_hook(data.win, 2, 1L << 0, ft_key_press, &all);
	mlx_hook(data.win, 17, 1, ft_finish_game, &all);
	mlx_loop(data.mlx);
}
