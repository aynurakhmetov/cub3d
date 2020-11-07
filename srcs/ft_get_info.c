#include "./../includes/cub3d.h"

t_plr   ft_get_plr_info(t_map mapInfo)
{
    t_plr plr;
    printf("GET PLR %d\n", mapInfo.xRenderSize);
    float i;
    float j;

    i = 0;
    while (mapInfo.map[(int)(i / SCALE)])
    {
        j = 0;
        while (mapInfo.map[(int)(i / SCALE)][(int)(j / SCALE)])
        {
            if (mapInfo.map[(int)(i / SCALE)][(int)(j / SCALE)] == 'N' || 
                    mapInfo.map[(int)(i / SCALE)][(int)(j / SCALE)] == 'E' 
                    || mapInfo.map[(int)(i / SCALE)][(int)(j / SCALE)] == 'W' 
                    || mapInfo.map[(int)(i / SCALE)][(int)(j / SCALE)] == 'S')
            {
                plr.x = j + 31.5;
                plr.y = i - 31.5;
                if (mapInfo.map[(int)(i / SCALE)][(int)(j / SCALE)] == 'N')
                    plr.dir = 3.14 * 1.5;
                if (mapInfo.map[(int)(i / SCALE)][(int)(j / SCALE)] == 'E') 
                    plr.dir = 3.14 * 2;
                if (mapInfo.map[(int)(i / SCALE)][(int)(j / SCALE)] == 'W') 
                    plr.dir = 3.14;
                if (mapInfo.map[(int)(i / SCALE)][(int)(j / SCALE)] == 'S')
                    plr.dir = 3.14 / 2;
                break ;
            }
            j++;
        }
        i++;
    }
    return (plr);
}

t_sprite  *ft_get_sprite_info(t_map mapInfo)
{
    t_sprite sprite;
    float i;
    float j;

    i = 0;
    int k = 0;
    int l = 0;
    int m = 0;
    int sc = 1;
    while (mapInfo.map[(int)(i / sc)])
    {
        j = 0;
        while (mapInfo.map[(int)(i / sc)][(int)(j / sc)])
        {
            m++;
            if (mapInfo.map[(int)(i / sc)][(int)(j / sc)] == '2' && mapInfo.map[(int)(i / sc)][(int)(j / sc)] != '1')
            {
                sprite.x = j + 31.5;
                sprite.y = i - 31.5;
                k++;
                if (k == sc * sc)
                {
                    l++;
                    k = 0;
                }               
            }
            j++;
        }
        i++;
    }

    t_sprite *sprites = malloc(sizeof(t_sprite) * (l + 1)); 
    int len = l;

    i = 0;
    k = 0;
    l = 0;
    m = 0;
   
    while (mapInfo.map[(int)(i / sc)])
    {
        j = 0;
        while (mapInfo.map[(int)(i / sc)][(int)(j / sc)])
        {
            if (mapInfo.map[(int)(i / sc)][(int)(j / sc)] == '2' && mapInfo.map[(int)(i / sc)][(int)(j / sc)] != '1')
            {
                k++;
                if (k == sc * sc)
                {
                    sprites[l].len = len;
                    sprites[l].x = j*64 + 32;
                    sprites[l].y = i*64 + 32;
                    l++;
                    k = 0;
                }
            }
            j++;
        }
        i++;
    }
    return (sprites);
}

t_all   ft_get_all_info(t_plr plr, t_map mapInfo, t_win data, t_point point)
{
    t_all all;
    printf("GET ALL\n");
    all.map = mapInfo.map;
    all.plr = &plr;
    all.win = &data;
    all.point = &point;
    all.mapInfo = &mapInfo;
    return (all);
}