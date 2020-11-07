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
    
    //mlx_pixel_put(all->win->mlx, all->win->win, j, i, color);
    unsigned int   *dst;
    // int x;
    // int y;
    //char    *dst;

    // x = (int)j;
    // y = (int)i;

    //printf("ya tut 2\n");

    //  МОЯ ВЕРСИЯ
    dst = all->win->addr + ((int)i * all->win->line_length + (int)j * (all->win->bits_per_pixel / 8));
    *(unsigned int*)dst = color;

    // ШАИТЛЬww
    // if ((int)i >= all->mapInfo->yRenderSize)
    //     i -= 1;
    // dst = all->win->addr + all->win->line_length * (int)i / 4;
    // dst[(int)j] = color;
    //printf("ya tut 333\n");
}

int     ft_render_next_frame(t_all *all)
{
    // int i, j;
    // i = 0;
    // j = 0;
    // while (i < 640)
    // {
    //     j = 0;
    //     while (j < 640)
    //     {
    //         ft_draw(all, i, j, 0x000000FF);
    //         j++;
    //     }
    //     i++;
    // }
    //printf("ya tut 11\n");
    //printf ("3 sprite X Y %f %f\n", all->sprite->y, all->sprite->x);
    ft_cast_rays(all);
   /// printf("ya tut 21\n");
   
    // ft_cub_2d(all);
    ft_draw_sprites(all);
    
    //printf("ya tut 21\n");
    //printf("ya tut 22\n");
    //ft_cub3d(all);
    mlx_put_image_to_window(all->win->mlx, all->win->win, all->win->img, 0, 0);
    mlx_put_image_to_window(all->win->mlx, all->win->win, all->text[1].image, 0, 144);
    mlx_put_image_to_window(all->win->mlx, all->win->win, all->text[0].image, 0, 210);
    //printf("RENDEER %d\n", (int)all->plr->x);
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

    // Найти позицию игрока
    plr = ft_get_plr_info(mapInfo);
    sprite = ft_get_sprite_info(mapInfo);

    // Получить данные для окна
    // Создать структуру для всего
    // Привязать клавиатуру
    // Запустить рейкастинг 
    // Натянуть текстуру
    // Заплилить спрайты
    data.mlx = mlx_init();
    data.win = mlx_new_window(data.mlx, mapInfo.xRenderSize, 
                mapInfo.yRenderSize, "CUB");
    all = ft_get_all_info(plr, mapInfo, data, point);
    //printf ("4 sprite X Y %f %f\n", all.sprite->y, all.sprite->x);
    
    all.win->img = mlx_new_image(all.win->mlx, all.mapInfo->xRenderSize, all.mapInfo->yRenderSize);
    all.win->addr = (unsigned int*)mlx_get_data_addr(all.win->img, &all.win->bits_per_pixel, &all.win->line_length, &all.win->endian);

    //printf("%s\n", all.mapInfo->northTexture);
    
    all.text[1].image = mlx_xpm_file_to_image(all.win->mlx, all.mapInfo->northTexture, &all.text[1].img_width, &all.text[1].img_height);
    all.text[1].addr = (unsigned int*)mlx_get_data_addr(all.text[1].image, &all.text[1].bits_per_pixel, &all.text[1].line_length, &all.text[1].endian);

    //printf("%s\n", all.mapInfo->northTexture);

    all.text[2].image = mlx_xpm_file_to_image(all.win->mlx, all.mapInfo->southTexture, &all.text[2].img_width, &all.text[2].img_height);
    all.text[2].addr = (unsigned int*)mlx_get_data_addr(all.text[2].image, &all.text[2].bits_per_pixel, &all.text[2].line_length, &all.text[2].endian);

    all.text[3].image = mlx_xpm_file_to_image(all.win->mlx, all.mapInfo->westTexture, &all.text[3].img_width, &all.text[3].img_height);
    all.text[3].addr = (unsigned int*)mlx_get_data_addr(all.text[3].image, &all.text[3].bits_per_pixel, &all.text[3].line_length, &all.text[3].endian);

    all.text[4].image = mlx_xpm_file_to_image(all.win->mlx, all.mapInfo->eastTexture, &all.text[4].img_width, &all.text[4].img_height);
    all.text[4].addr = (unsigned int*)mlx_get_data_addr(all.text[4].image, &all.text[4].bits_per_pixel, &all.text[4].line_length, &all.text[4].endian);

    all.text[0].image = mlx_xpm_file_to_image(all.win->mlx, all.mapInfo->spriteTexture, &all.text[0].img_width, &all.text[0].img_height);
    all.text[0].addr = (unsigned int*)mlx_get_data_addr(all.text[0].image, &all.text[0].bits_per_pixel, &all.text[0].line_length, &all.text[0].endian);
    // all.text[0].x = sprite.x;
    // all.text[0].y = sprite.y;
    all.sprites = sprite;
    all.dist_wall = malloc(sizeof(float) * (all.mapInfo->xRenderSize + 1));

    
    //printf("1 %d %d\n", all.text[1].line_length, all.text[1].bits_per_pixel);
    //mlx_loop_hook(data.mlx, ft_render_next_frame, &all);
    //printf("0 %d\n", (int)all.text[1].addr);
    //printf ("5 sprite X Y %f %f\n", all.sprite->y, all.sprite->x);
    ft_render_next_frame(&all);
    if (savebmp == 1)
    {
        screenshot(&all);
        exit(0);
    }

    //printf("1 %d\n", (int)all.text[1].addr);
    mlx_hook(data.win, 2, 1L << 0, key_press, &all);
    ////mlx_hook(data.win, 3, 1L << 1, key_release, &all);
	mlx_hook(data.win, 17, 1, ft_finish_game, &all);
    //ft_render_next_frame(&all);
    //ft_cast_ray(&all);
	
    mlx_loop(data.mlx); // Рендеринг 

    //printf("START GAME %d\n", mapInfo.xRenderSize);
}