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

int ft_render_size_chek(r_num_1, r_num_2, numofres)
{
    if (r_num_1 <= 0 || r_num_2 <= 0)
        ft_exit("render size R <= 0");
    if (r_num_1 > 2560) 
        r_num_1 = 2560;
    if (r_num_2 > 1440) 
        r_num_2 = 1440;
    if (numofres == 1)
        return (r_num_1);
    if (numofres == 2)
        return (r_num_2);
    return (-1);
}

int ft_get_render_size(char **map, int numofres)
{
    int i;
    int j;
    int r_num_1;
    int r_num_2;

    j = 0;
    r_num_1 = -1;
    r_num_2 = -1;
    if ((i = ft_get_line_mumber(map, "R ")) == -1)
        ft_exit("identifier R not found");
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
    return (ft_render_size_chek(r_num_1, r_num_2, numofres));
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
        ft_exit_identifier("texture identifier not found - ", identifier);
    while (map[i][j] != 0)
    {
        if (map[i][j] != ' ' && map[i][j] 
        != identifier[0] && map[i][j] != identifier[1])
        {
            if (k == 0)
                start = j;
            k++;   
        }
        j++;
    }
    address = ft_substr(map[i], start, k);
    if ((fd = open(address, O_RDONLY)) == -1)
        ft_exit_identifier("texture does not open - ", identifier);
    return (address);
}