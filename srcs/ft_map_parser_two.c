/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_parser_two.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 19:41:50 by gmarva            #+#    #+#             */
/*   Updated: 2020/11/07 19:41:52 by gmarva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/cub3d.h"

unsigned int	ft_create_trgb(char **str)
{
	int	t;
	int	r;
	int	g;
	int	b;

	t = 0;
	r = ft_atoi(str[0]);
	g = ft_atoi(str[1]);
	b = ft_atoi(str[2]);
	if (r < 0 || g < 0 || b < 0 || r > 255 || g > 255 || b > 255)
		ft_exit("color entered incorrectly");
	return (t << 24 | r << 16 | g << 8 | b);
}

unsigned int	ft_get_color(char **map, char *identifier)
{
	int		i;
	int		j;
	char	**color;

	j = 0;
	color = NULL;
	if ((i = ft_get_line_mumber(map, identifier)) == -1)
		ft_exit_identifier("color identifier not found - ", identifier);
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
		i++;
	if (i > 3)
		ft_exit("many color arguments");
	if (i < 3)
		ft_exit("missing color arguments");
	return (ft_create_trgb(color));
}

char			**ft_get_map(char **map)
{
	char	**newmap;
	int		i;
	int		start;

	i = -1;
	start = 0;
	while (map[++i] != 0)
	{
		if (ft_strchr(map[i], '.') || ft_strchr(map[i], ',')
		|| ft_strchr(map[i], 'R'))
			continue ;
		else
		{
			if (start == 0 && ft_strchr(map[i], '1'))
				start = i;
		}
	}
	newmap = (char **)malloc(sizeof(char *) * (i - start + 1));
	i = 0;
	while (map[start] != 0)
		newmap[i++] = ft_strdup(map[start++]);
	return (newmap);
}
