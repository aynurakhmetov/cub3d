/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 21:45:13 by gmarva            #+#    #+#             */
/*   Updated: 2020/11/07 18:14:13 by gmarva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/cub3d.h"

void ft_map_error_test(t_map mapinfo)
{
    int i;
    int j;
    int k;

    i = 0;
    k = 0;
    ft_map_test(mapinfo.map);
    while (mapinfo.map[i])
    {
        j = 0;
        while (mapinfo.map[i][j])
        {
            if (mapinfo.map[i][j] != 'N' && mapinfo.map[i][j] != 'E' 
                &&  mapinfo.map[i][j] != 'W' && mapinfo.map[i][j] != 'S'
                &&  mapinfo.map[i][j] != '1' &&  mapinfo.map[i][j] != '2'
                &&  mapinfo.map[i][j] != '0' &&  mapinfo.map[i][j] != ' ')
                ft_exit("garbage in the map");
            if (mapinfo.map[i][j] == 'N' || mapinfo.map[i][j] == 'E' 
                || mapinfo.map[i][j] == 'W' || mapinfo.map[i][j] == 'S')
                k++;
            j++;
        }
        i++;
    }
    if (k > 1)
        ft_exit("many players");
}

t_map ft_get_map_info(char **newmap)
{
    t_map mapinfo;

    if ((mapinfo.xrendersize = ft_get_render_size(newmap, 1)) == -1)
        ft_exit("problem with render size R");
    if ((mapinfo.yrendersize = ft_get_render_size(newmap, 2)) == -1)
        ft_exit("problem with render size R");
    mapinfo.northtexture = ft_get_texture(newmap, "NO");
    mapinfo.southtexture = ft_get_texture(newmap, "SO");
    mapinfo.westtexture = ft_get_texture(newmap, "WE");
    mapinfo.easttexture = ft_get_texture(newmap, "EA");
    mapinfo.spritetexture = ft_get_texture(newmap, "S ");
    mapinfo.floorcolor = ft_get_color(newmap, "F ");
    mapinfo.ceilingcolor = ft_get_color(newmap, "C ");
    mapinfo.map = ft_get_map(newmap);
    return (mapinfo);
}

char **ft_make_map(t_list **head, int size)
{
    char **map;
    int i;
    t_list *tmp;

    map = ft_calloc(size + 1, sizeof(char *));
    i = 0;
    tmp = *head;
    while (tmp)
    {
        map[i] = tmp->content;
        tmp = tmp->next;
        i++;
    }
    return (map);
}

t_map ft_map_parser(char *mapinput)
{
    int fd;
    char *line;
    char **newmap;
    t_list *head;
    t_map mapinfo;

    fd = open(mapinput, O_RDONLY);
    if (fd == -1)
        ft_exit(".cub file read error");
    line = NULL;
    head = NULL;    
    while (get_next_line(fd, &line))
        ft_lstadd_back(&head, ft_lstnew(line));
    ft_lstadd_back(&head, ft_lstnew(line));
    newmap = ft_make_map(&head, ft_lstsize(head));
    mapinfo = ft_get_map_info(newmap);
    free (newmap);
    return (mapinfo);
}

int main(int argc, char *argv[])
{
    t_map mapinfo;

    if (argc < 2 || argc > 3)
        ft_exit("problems with arguments in the input: more or less arguments");
    if (argc == 3 && ft_strncmp(argv[2], "--save", ft_strlen(argv[2])) == 0)
    {
        mapinfo = ft_map_parser(argv[1]);
        ft_map_error_test(mapinfo);
        ft_start_game(mapinfo, 1);
    }
    else if (argc == 2) 
    {
        mapinfo = ft_map_parser(argv[1]);
        ft_map_error_test(mapinfo);
        ft_start_game(mapinfo, 0);
    }
    else
        ft_exit("problems with arguments in the input");
    return (0);
}