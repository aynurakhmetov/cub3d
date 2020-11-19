#include "./cub.h"

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
    //printf("GET PLR %d\n", mapInfo.xRenderSize);
    float i;
    float j;
    // int i;
    // int j;
    //t_list *spritefind;

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
                //printf ("1 sprite X Y %f %f\n", i, j);
                k++;
                if (k == sc * sc)
                {
                    l++;
                    k = 0;
                }
                //break;
                //ft_lstadd_back(&spritefind, &sprite);
                
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
                
                //printf ("1 sprite X Y %f %f\n", i, j);
                k++;
                if (k == sc * sc)
                {
                    sprites[l].len = len;
                    sprites[l].x = j*64 + 32;
                    sprites[l].y = i*64 + 32;
                    l++;
                    k = 0;
                }
                //break;
                //ft_lstadd_back(&spritefind, &sprite);
            }
            j++;
        }
        i++;
    }

    

    printf("l = %d\n", l);

    //  while (mapInfo.map[(int)(i)])
    // {
    //     j = 0;
    //     while (mapInfo.map[(int)(i)][(int)(j)])
    //     {
    //         if (mapInfo.map[(int)(i)][(int)(j)] == '2')
    //         {
    //             sprite.x = j;
    //             sprite.y = i;
    //             printf ("1 sprite X Y %f %f\n", i, j);
    //             break;
    //             //ft_lstadd_back(&spritefind, &sprite);
    //             //printf ("1 sprite X Y %f %f\n", i, j);
    //         }
    //         j++;
    //     }
    //     i++;
    // }
    return (sprites);
}

t_all   ft_get_all_info(t_plr plr, t_map mapInfo, t_win data, t_point point)
{
    t_all all;
    printf("GET ALL\n");
    //sprite = ft_get_sprite_info(mapInfo);
    //all.sprite = &sprite;
    all.map = mapInfo.map;
    all.plr = &plr;
    all.win = &data;
    all.point = &point;
    all.mapInfo = &mapInfo;
	//printf ("0 sprite X Y %f %f\n", all.sprite->y, all.sprite->x);

    return (all);
}