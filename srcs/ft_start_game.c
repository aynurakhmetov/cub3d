/* ************************************************************************** */
/*                                                                            */
/*                                             w           :::      ::::::::   */
/*   ft_start_game.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 13:07:41 by gmarva            #+#    #+#             */
/*   Updated: 2020/10/26 13:07:46 by gmarva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/cub3d.h"

void    ft_draw(t_all *all, float i, float j, int color)
{
    unsigned int   *dst;
    dst = all->win->addr + ((int)i * all->win->line_length + (int)j * (all->win->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

int     ft_render_next_frame(t_all *all)
{
    ft_cast_rays(all);
    ft_cub_2d(all);
    ft_draw_sprites(all);
    mlx_put_image_to_window(all->win->mlx, all->win->win, all->win->img, 0, 0);
    mlx_put_image_to_window(all->win->mlx, all->win->win, all->text[1].image, 0, 144);
    mlx_put_image_to_window(all->win->mlx, all->win->win, all->text[0].image, 0, 210);
    return (0);
}

int ft_finish_game(t_all *all)
{
    int i;

	i = 0;
	if (all->map[i])
	{
		while (all->map[i])
		{
			free(all->map[i]);
			i++;
		}
		free(all->map[i]);
	}
	exit(EXIT_SUCCESS);
}

void	ft_start_game(t_map mapInfo, int savebmp)
{
    t_win data;
    t_plr plr;
    t_all all;
    t_point point;
    t_sprite *sprite;
    point.x = 0;
    point.y = 0;
    plr = ft_get_plr_info(mapInfo);
    sprite = ft_get_sprite_info(mapInfo);
    data.mlx = mlx_init();
    data.win = mlx_new_window(data.mlx, mapInfo.xRenderSize, 
                mapInfo.yRenderSize, "CUB");
    all = ft_get_all_info(plr, mapInfo, data, point);
    all.win->img = mlx_new_image(all.win->mlx, all.mapInfo->xRenderSize, all.mapInfo->yRenderSize);
    all.win->addr = (unsigned int*)mlx_get_data_addr(all.win->img, &all.win->bits_per_pixel, &all.win->line_length, &all.win->endian);
    all.text[1].image = mlx_xpm_file_to_image(all.win->mlx, all.mapInfo->northTexture, &all.text[1].img_width, &all.text[1].img_height);
    all.text[1].addr = (unsigned int*)mlx_get_data_addr(all.text[1].image, &all.text[1].bits_per_pixel, &all.text[1].line_length, &all.text[1].endian);
    all.text[2].image = mlx_xpm_file_to_image(all.win->mlx, all.mapInfo->southTexture, &all.text[2].img_width, &all.text[2].img_height);
    all.text[2].addr = (unsigned int*)mlx_get_data_addr(all.text[2].image, &all.text[2].bits_per_pixel, &all.text[2].line_length, &all.text[2].endian);
    all.text[3].image = mlx_xpm_file_to_image(all.win->mlx, all.mapInfo->westTexture, &all.text[3].img_width, &all.text[3].img_height);
    all.text[3].addr = (unsigned int*)mlx_get_data_addr(all.text[3].image, &all.text[3].bits_per_pixel, &all.text[3].line_length, &all.text[3].endian);
    all.text[4].image = mlx_xpm_file_to_image(all.win->mlx, all.mapInfo->eastTexture, &all.text[4].img_width, &all.text[4].img_height);
    all.text[4].addr = (unsigned int*)mlx_get_data_addr(all.text[4].image, &all.text[4].bits_per_pixel, &all.text[4].line_length, &all.text[4].endian);
    all.text[0].image = mlx_xpm_file_to_image(all.win->mlx, all.mapInfo->spriteTexture, &all.text[0].img_width, &all.text[0].img_height);
    all.text[0].addr = (unsigned int*)mlx_get_data_addr(all.text[0].image, &all.text[0].bits_per_pixel, &all.text[0].line_length, &all.text[0].endian);
    all.sprites = sprite;
    all.dist_wall = malloc(sizeof(float) * (all.mapInfo->xRenderSize + 1));
    ft_render_next_frame(&all);
    if (savebmp == 1)
    {
        screenshot(&all);
        exit(0);
    }
    mlx_hook(data.win, 2, 1L << 0, key_press, &all);
	mlx_hook(data.win, 17, 1, ft_finish_game, &all);
    mlx_loop(data.mlx); // Рендеринг 
}