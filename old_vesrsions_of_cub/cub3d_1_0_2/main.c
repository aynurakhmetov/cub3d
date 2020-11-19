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

#include "./cub.h"

/*
** If any misconfiguration of any kind is encountered in the file, the program
** must exit properly and return "Error\n" followed by an explicit error message
** of your choice.
*/
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

/*
** Your program must take as a first argument a scene description file with the .cub
** extension.
*/
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
    // почистить head
    mapInfo.xRenderSize = ft_get_render_size(newMap, 1);
    mapInfo.yRenderSize = ft_get_render_size(newMap, 2);
    mapInfo.northTexture = ft_get_texture(newMap, "NO");
    mapInfo.southTexture = ft_get_texture(newMap, "SO");
    mapInfo.westTexture = ft_get_texture(newMap, "WE");
    mapInfo.eastTexture = ft_get_texture(newMap, "EA");
    mapInfo.spriteTexture = ft_get_texture(newMap, "S ");
    mapInfo.floorColor = ft_get_color(newMap, "F ");
    mapInfo.ceilingColor = ft_get_color(newMap, "C ");
    mapInfo.map = ft_get_map(newMap);
    printf("%s %d\n", mapInput, screenNeed); // DELETE!!!
    free (newMap);
    return (mapInfo);
    // check for leaks + закрыть чтение
}

int ft_map_error_test(t_map mapInfo)
{
    printf("TEST ERROR %d\n", mapInfo.xRenderSize);
    // Написать функцию
    // Проверить валидность всех полученных данных
    // 
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
            return (0);
        ft_start_game(mapInfo, 1);
        //printf("%s\n", argv[2]); // DELETE!!!!
    }
    else if (argc == 2) 
    {
        mapInfo = ft_map_parser(argv[1], 0);
        if (ft_map_error_test(mapInfo) == 0)
            return (0);
        ft_start_game(mapInfo, 0);
    }
    else
    {
        ft_putendl_fd("ERROR MESSAGE: problems with arguments in the input", 1);
        return (0);
    }
    
    
    // Про Скриншот помнить
    
    return (0);
}

