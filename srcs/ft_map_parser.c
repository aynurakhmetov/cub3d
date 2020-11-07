/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 22:45:57 by gmarva            #+#    #+#             */
/*   Updated: 2020/11/07 18:12:40 by gmarva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/cub3d.h"

int ft_get_line_mumber(char **map, char *identifier)
{
    int i;
    int j;

    i = 0;
    while (map[i] != 0)
    {
        j = 0;
        while (map[i][j])
        {
            if (ft_strncmp(&map[i][j], identifier, ft_strlen(identifier)) == 0)
            {
                return (i);
                break ;
            }
            j++;
        }
        i++;
    }
    return (-1);
}

int ft_get_render_size(char **map, int numOfRes)
{
    int i;
    int j;
    int r_num_1;
    int r_num_2;

    j = 0;
    r_num_1 = -1;
    r_num_2 = -1;
    if ((i = ft_get_line_mumber(map, "R ")) == -1)
    {
        ft_putendl_fd("ERROR MESSAGE: identifier R not found", 1);
        return (-1);
    }
    while (map[i][j] != 0)
    {
        if (map[i][j] >= '0' && map[i][j] <= '9')
        {
            if (r_num_1 == -1)
                r_num_1 = ft_atoi(&map[i][j]);
            if (r_num_1 != -1 && map[i][j - 1] == ' ')
                r_num_2 = ft_atoi(&map[i][j]);
        }
        j++;
    }
    printf("RRR %d %d\n", r_num_1, r_num_2);
    if (r_num_1 <= 0 || r_num_2 <= 0)
    {
        ft_putendl_fd("ERROR MESSAGE: r < 0", 1);
        return (-1);
    }
    if (r_num_1 > 2560) 
        r_num_1 = 2560;
    if (r_num_2 > 1440) 
        r_num_2 = 1440;
    if (numOfRes == 1)
        return (r_num_1);
    if (numOfRes == 2)
        return (r_num_2);
    return (-1);
}


char *ft_get_texture(char **map, char *identifier)
{
    int i;
    int j;
    int k;
    int start;
    char *address;
    int fd;

    j = 0;
    k = 0;
    if ((i = ft_get_line_mumber(map, identifier)) == -1)
    {
        ft_putstr_fd("ERROR MESSAGE: texture identifier not found - ", 1);
        ft_putendl_fd(identifier, 1);
        exit (0);
    }
    while (map[i][j] != 0)
    {
        if (map[i][j] != ' ' && map[i][j] != identifier[0] && map[i][j] != identifier[1])
        {
            if (k == 0)
                start = j;
            k++;   
        }
        j++;
    }
    address = ft_substr(map[i], start, k);
    if ((fd = open(address, O_RDONLY)) == -1)
    {
        ft_putstr_fd("ERROR MESSAGE: texture identifier not found - ", 1);
        ft_putendl_fd(identifier, 1);
        exit (0);
    }
    printf("TEXTUREEEE %s\n", address);
    return (address);
}

unsigned int 		create_trgb(char **str)
{
    int t;
    int r;
    int g;
    int b;

    t = 0;
    r = ft_atoi(str[0]);
    g = ft_atoi(str[1]);
    b = ft_atoi(str[2]);
   

    if (r < 0 || g < 0 || b < 0 || r > 255 || g > 255 || b > 255)
    {
        ft_putstr_fd("ERROR MESSAGE: color problem", 1);
        exit (0);
    }
	return(t << 24 | r << 16 | g << 8 | b);
}

int ft_get_color(char **map, char *identifier)
{
    int i;
    int j;
    char **color;
    unsigned int  clr;

    j = 0;
    color = NULL;
    if ((i = ft_get_line_mumber(map, identifier)) == -1)
    {
        ft_putstr_fd("ERROR MESSAGE: color identifier not found - ", 1);
        ft_putendl_fd(identifier, 1);
        exit (0);
    }
    while (map[i][j] != 0)
    {
        if (ft_isdigit(map[i][j]) > 1)
        {
            color = ft_split(&map[i][j], ',');
            break ;
        }
        j++;
    }
    
    i = 0;
    while (color[i] != 0)
    {
        printf("COLOOOR %s\n", color[i]);
        i++;
    }
    if (i > 3)
    {
        ft_putstr_fd("ERROR MESSAGE: many colors ", 1);
        exit (0);
    }
    if (i < 3)
    {
        ft_putstr_fd("ERROR MESSAGE: malo colors ", 1);
        exit (0);
    }
    clr = create_trgb(color);
    return (clr);
}

char **ft_get_map(char **map)
{
    char **newMap;
    int i;
    int start;

    i = 0;
    start = 0;
    while (map[i] != 0)
    {
        if (ft_strchr(map[i], '.') || ft_strchr(map[i], ',')
            || ft_strchr(map[i], 'R'))
        {
            i++;
            continue ;
        }
        else 
        {
            if (start == 0 && ft_strchr(map[i], '1'))
                start = i;      
        }
        i++;
    }
    newMap = (char **)malloc(sizeof(char *) * (i - start + 1));
    i = 0;
    while (map[start] != 0)
        newMap[i++] = ft_strdup(map[start++]); 
    i = 0;
    while (newMap[i] != 0)
    {
        printf("MAAAAP %s\n", newMap[i]);
        i++;
    }
    return (newMap);
}   
