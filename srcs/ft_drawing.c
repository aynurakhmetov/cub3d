#include "./../includes/cub3d.h"

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
            if (all->map[(int)(i / sc)][(int)(j / sc)] == '2')
                ft_draw(all, i, j, 0x0000FFFF);
            if (all->map[(int)(i / sc)][(int)(j / sc)] >= 'E' && all->map[(int)(i / sc)][(int)(j / sc)] <= 'W')
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
    return (*(int *)color);
}

int ft_get_wall_color(t_all *all, float y_draw, float x_draw, int start, int end, int i, float height)
{
    int h=0;
    int w=0;
    float hit;
    int textnum;

    if (all->new_dir == 'N')
        textnum = 1;
    if (all->new_dir == 'S')
        textnum = 2;
    if (all->new_dir == 'W')
        textnum = 3;
    if (all->new_dir == 'E')
        textnum = 4;

    char *color;

    if (all->new_dir == 'N' || all->new_dir == 'S')
    {
        hit = fmod(x_draw, SCALE) / SCALE;
    }
    if (all->new_dir == 'W' || all->new_dir == 'E')
    {
        hit = fmod(y_draw, SCALE) / SCALE;
    }
    w = all->text[textnum].img_width * hit;

    start = all->mapInfo->yRenderSize / 2.0 - height / 2.0;
 
    while (start < end)
    {
		if (start >= 0)
		{
    		color = (all->text[textnum].addr + ((((int)((h * all->text[textnum].img_height) / height)*all->text[textnum].line_length + ((int)w * (all->text[textnum].bits_per_pixel/ 8))))));
        	ft_draw(all, start, i, *(int *)color);
		}
        h++;
        start++;
    }
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
   
    distance = sqrt(pow(x_draw - all->plr->x, 2) + pow(y_draw - all->plr->y, 2)) * cos(ugol - all->plr->dir);
     all->dist_wall[i] = distance;
    perpendicular = (all->mapInfo->xRenderSize / 2) / tan(FOV/2);
    height = (SCALE / distance) * (all->mapInfo->xRenderSize / 2) / tan(FOV/2);
    start = all->mapInfo->yRenderSize/2 - height/2;
    end = height + start;
	if (end > all->mapInfo->yRenderSize)
        end = all->mapInfo->yRenderSize;
    int j = 0;
    while (j < start)
    {
        ft_draw(all, j, i, all->mapInfo->ceilingColor);
        j++;
    }

    wall_color = ft_get_wall_color(all, y_draw, x_draw, start, end, i, height);
    while (end < all->mapInfo->yRenderSize)
    {
        ft_draw(all, end, i, all->mapInfo->floorColor);
        end++;
    }
}