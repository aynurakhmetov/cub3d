#include "./cub.h"

void    ft_cub_2d(t_all *all)
{
    float i;
    float j;
    int sc;

    i = 0;
    sc = 10;
    while (all->map[(int)(i / sc)])
    {
        j = 0;
        while (all->map[(int)(i / sc)][(int)(j / sc)])
        {
            if (all->map[(int)(i / sc)][(int)(j / sc)] == '1')
                ft_draw(all, i, j, 0x000000FF);
            //if (all->map[(int)(i / sc)][(int)(j / sc)] == '0')
            //    ft_draw(all, i, j, 0x00FFFFFF);
            if (all->map[(int)(i / sc)][(int)(j / sc)] == '2')
                ft_draw(all, i, j, 0x0000FFFF);
            if (all->map[(int)(i / sc)][(int)(j / sc)] >= 'E' && all->map[(int)(i / SCALE)][(int)(j / SCALE)] <= 'W')
                ft_draw(all, i, j, 0x0000FF88);
            j++;
        }
        i++;
    }
    ft_draw(all, all->plr->y / (6.4), all->plr->x / (6.4), 0x00AA00FF);
    float x = all->plr->x / (6.4);
    float y = all->plr->y / (6.4);
    float x_end = x + 64;
    float y_end = y + 64;
    while (y < y_end)
    {
        x = all->plr->x;
        while (x < x_end)
        {
            ft_draw(all, y, x, 0x00AA00FF);
            x++;
        }
        y++;
    }
}

int get_color(t_all *all, int h, int w, float height)
{
    char *color;
    color = (all->text[1].addr + ((((int)(h * all->text[1].img_height / height)*all->text[1].line_length + ((int)w * (all->text[1].bits_per_pixel/ 8))))));
    // color = (*(int*)(all->text[1].addr + (SCALE * all->text[1].img_width * (int)h) + (SCALE * (int)w)));
    return (*(int *)color);
}

int ft_get_wall_color(t_all *all, float y_draw, float x_draw, int start, int end, int i, float height)
{
    // int color_n;
    // int color_w;
    // int color_e;
    // int color_s;
    int h=0;
    int w=0;
    float hit;
    //float ptr;

    //int     k;
    //int color;

    //void *addr;

    char *color;
    //int x;


    if (all->new_dir == 'N' || all->new_dir == 'S')
    {
        //hit = modff(x_draw, &ptr);
        hit = fmod(x_draw, SCALE) / SCALE;
        //printf("x hit = %f, x_draw = %f\n",hit, x_draw);
    }
    if (all->new_dir == 'W' || all->new_dir == 'E')
    {
        //hit = modff(y_draw, &ptr); 
        hit = fmod(y_draw, SCALE) / SCALE;
        //printf("y hit = %f, y_draw = %f\n", hit, y_draw);
    }
    w = all->text[1].img_width * hit;

    //printf("w=%d imwid = %d\n", w, all->text[1].img_width);
    

    start = all->mapInfo->yRenderSize / 2.0 - height / 2.0;
    // int step = 1.0 * all->text[1].img_height / (end - start);
    // int step = (end - start) / SCALE;
    //  ВОВА
    // float texPos = (start - all->mapInfo->yRenderSize / 2 + (end - start) / 2) * step;
    // //all->mapInfo->northTexture, &all->text[1].img_width, &all->text[1]->img_height);
    // printf("2 %d\n", (int)all->text[1].addr);

    while (start < end)
    {
        // ВОВА
        // int texY = 254;
        // texY = (int)texPos & (all->text[1].img_height - 1);
        // texPos += step;
        // color  = get_color(all, h, w, height);
		if (start >= 0)
		{
    		color = (all->text[1].addr + ((((int)((h * all->text[1].img_height) / height)*all->text[1].line_length + ((int)w * (all->text[1].bits_per_pixel/ 8))))));
        	ft_draw(all, start, i, *(int *)color);
		}

        // printf("y = %d \n x = %d\n", texY, w);
        // printf("w = %f, h = %f, t_h = %d\n", w, h, all->text[1].img_height);
        //printf("%d\n", start);

        // ШАМИЛЬ
        // if (start >= 0)
        // {
        //     k = (int)h / 1 * all->text[1].line_length;
        //     ft_draw(all, start, i, all->text[1].addr[k + (int)w]);
        // }

        //  ВОВА
        //my_mlx_pixel_put(all, i, start, color);
        // if (h < 10)
        h++;
        // h = h + step;
        start++;
    }
    //printf("color  %d\n", color);
    

    // color_n = 0x00FF69A4;
    // color_w = 0x00FF1493;
    // color_e = 0x00FF4500;
    // color_s = 0x00FF0000;

    // if (all->new_dir == 'N')
    //     return (color_n);
    // if (all->new_dir == 'E')
    //     return (color_e);
    // if (all->new_dir == 'S')
    //     return (color_s);
    // if (all->new_dir == 'W')
    //     return (color_w);
   
    return (0);
}

void    ft_draw_wall(t_all *all, float y_draw, float x_draw, int i, float ugol)
{
    float distance;
    float perpendicular;
    float height;
    float start;
    float end;
    int wall_color;
    //wall_color = ft_get_wall_color(all, y_draw, x_draw);
    // РАЗОБРАТЬСЯ С ПЕРЕДАЧЕЙ ЦВЕТА НЕБА И ПОЛА
   

    //printf("ya tut 2\n");
    distance = sqrt(pow(x_draw - all->plr->x, 2) + pow(y_draw - all->plr->y, 2)) * cos(ugol - all->plr->dir);
     all->dist_wall[i] = distance;
    perpendicular = (all->mapInfo->xRenderSize / 2) / tan(FOV/2);
    //height = all->mapInfo->yRenderSize / (distance * sin(all->plr->dir));
    height = (SCALE / distance) * (all->mapInfo->xRenderSize / 2) / tan(FOV/2);
    // if (height > all->mapInfo->yRenderSize)
    //     height = all->mapInfo->yRenderSize;
    // height = (int)(height);
    // if  ((int)height % 2 == 1)
    //     height = height - 1;
    // if (height < 0
    //     height = height * (-1);
    start = all->mapInfo->yRenderSize/2 - height/2;
    end = height + start;
	if (end > all->mapInfo->yRenderSize)
        end = all->mapInfo->yRenderSize;

    //printf("ya tut 7\n");
    //printf("HEY HEY %f %f %f %f\n", distance, perpendicular, height, start);
    int j = 0;
    while (j < start)
    {
        ft_draw(all, j, i, 0x00FFFFFF);
        j++;
    }
    // printf("ya tut 5 %f %d\n", start, i);

    wall_color = ft_get_wall_color(all, y_draw, x_draw, start, end, i, height);
    // if (all->map[(int)(y_draw / SCALE)][(int)(x_draw / SCALE)] == '2')
	// 	 	ft_draw_sprite(all, y_draw, x_draw, i, ugol);

    // while (start < end)
    // {
    //     ft_draw(all, start, i, wall_color);
    //     start++;
    // }
    //ft_draw_texture(all, start, end, i, height, distance);
    //printf("ya tut 6\n");
    while (end < all->mapInfo->yRenderSize)
    {
		//printf("ya=%d\n", i);
        ft_draw(all, end, i, 0x00FFFF00);
        end++;
    }
    //printf("ya tut 8\n");
    //printf("ya tut 4\n");
}