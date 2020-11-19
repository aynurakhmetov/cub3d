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