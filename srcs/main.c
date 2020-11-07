/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 21:45:13 by gmarva            #+#    #+#             */
/*   Updated: 2020/10/25 21:45:21 by gmarva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/cub3d.h"

char **make_map(t_list **head, int size)
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
    i = 0;
    while (map[i])
    {
        ft_putendl_fd(map[i], 1);
        i++;
    }
    return (map);
}

t_map ft_map_parser(char *mapInput, int screenNeed)
{
    t_map mapInfo;
    int fd;
    char *line;
    char **newMap;
    t_list *head;

    fd = open(mapInput, O_RDONLY);
    if (fd == -1)
    {
        ft_putendl_fd("ERROR MESSAGE: file read error", 1);
        exit (0);
    }
    line = NULL;
    head = NULL;    
    while (get_next_line(fd, &line))
    {
        ft_lstadd_back(&head, ft_lstnew(line));
    }
    ft_lstadd_back(&head, ft_lstnew(line));
    newMap = make_map(&head, ft_lstsize(head));
    if ((mapInfo.xRenderSize = ft_get_render_size(newMap, 1)) == -1)
    {
       ft_putendl_fd("ERROR MESSAGE: R", 1); 
       exit(0);
    }
    if ((mapInfo.yRenderSize = ft_get_render_size(newMap, 2)) == -1)
     {
       ft_putendl_fd("ERROR MESSAGE: R", 1); 
       exit(0);
    }
    mapInfo.northTexture = ft_get_texture(newMap, "NO");
    mapInfo.southTexture = ft_get_texture(newMap, "SO");
    mapInfo.westTexture = ft_get_texture(newMap, "WE");
    mapInfo.eastTexture = ft_get_texture(newMap, "EA");
    mapInfo.spriteTexture = ft_get_texture(newMap, "S ");
    mapInfo.floorColor = ft_get_color(newMap, "F ");
    mapInfo.ceilingColor = ft_get_color(newMap, "C ");
    mapInfo.map = ft_get_map(newMap);
   
    printf("%s %d\n", mapInput, screenNeed);
    free (newMap);
    return (mapInfo);
}

int ft_map_error_test(t_map mapInfo)
{
    int i;
    int j;
    int k;

    i = 0;
    k = 0;
    ft_map_test(mapInfo.map);
    printf("TEST ERROR %d\n", mapInfo.xRenderSize);
     while (mapInfo.map[i])
    {
        j = 0;
        while (mapInfo.map[i][j])
        {
            if (mapInfo.map[i][j] != 'N' && 
                    mapInfo.map[i][j] != 'E' 
                    &&  mapInfo.map[i][j] != 'W' 
                    && mapInfo.map[i][j] != 'S'
                    &&  mapInfo.map[i][j] != '1'
                    &&  mapInfo.map[i][j] != '2'
                    &&  mapInfo.map[i][j] != '0'
                    &&  mapInfo.map[i][j] != ' '
                    )
                {
                    ft_putendl_fd("ERROR MESSAGE: musor in map", 1);
                    exit(0);
                }
            if (mapInfo.map[i][j] == 'N' || 
                    mapInfo.map[i][j] == 'E' 
                    || mapInfo.map[i][j] == 'W' 
                    || mapInfo.map[i][j] == 'S')
            {
                k++;
            }
            j++;
        }
        i++;
    }
    if (k > 1)
    {
        ft_putendl_fd("ERROR MESSAGE: many players", 1);
        exit(0);
    }
    return (1);
}

int main(int argc, char *argv[])
{
    t_map mapInfo;

    if (argc < 2 || argc > 3)
    {
        ft_putendl_fd("ERROR MESSAGE: problems with arguments in the input", 1);
        return (0);
    }
    if (argc == 3 && ft_strncmp(argv[2], "--save", ft_strlen(argv[2])) == 0)
    {
        mapInfo = ft_map_parser(argv[1], 1);
        if (ft_map_error_test(mapInfo) == 0)
        {
            return (0);
        }
        ft_start_game(mapInfo, 1);
    }
    else if (argc == 2) 
    {
        mapInfo = ft_map_parser(argv[1], 0);
        if (ft_map_error_test(mapInfo) == 0)
        {
            return (0);
        }
        ft_start_game(mapInfo, 0);
    }
    else
    {
        ft_putendl_fd("ERROR MESSAGE: problems with arguments in the input", 1);
        return (0);
    }
    return (0);
}

