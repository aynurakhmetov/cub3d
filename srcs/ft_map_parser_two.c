/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_parser_two.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarva <gmarva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 19:41:50 by gmarva            #+#    #+#             */
/*   Updated: 2020/11/08 18:48:14 by gmarva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/cub3d.h"

unsigned int	ft_create_trgb(char **str)
{
	int	t;
	int	r;
	int	g;
	int	b;
	int i;

	t = 0;
	r = ft_atoi(str[0]);
	g = ft_atoi(str[1]);
	b = ft_atoi(str[2]);
	if (r < 0 || g < 0 || b < 0 || r > 255 || g > 255 || b > 255)
		ft_exit("color entered incorrectly");
	i = -1;
	while (str[++i])
		free(str[i]);
	free(str);
	return (t << 24 | r << 16 | g << 8 | b);
}

void		ft_color_garbage_check(char *cstr, char c)
{
	int i;
	int k;

	i = -1;
	k = 0;
	while (cstr[++i] != 0)
	{
		if ((cstr[i] < '0' || cstr[i] > '9') && cstr[i] != ' '
		&& cstr[i] != '-' && cstr[i] != '+' && cstr[i] != c
		&& cstr[i] != ',')
			ft_exit("garbage in c");
		if ((cstr[i] == '+' || cstr[i] == '-')
		&& (cstr[i + 1] < '0' || cstr[i + 1] > '9'))
			ft_exit("garbage in C");
		if (cstr[i] == c)
			k++;
		if (k > 1)
			ft_exit("garbage in C");
	}
	ft_color_garbage_check_next(cstr);
}

void		ft_color_check(int j, char *cstr, char c)
{
	if (j > 3)
		ft_exit("many color arguments");
	if (j < 3)
		ft_exit("few color arguments");
	ft_color_garbage_check(cstr, c);
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
	j = 0;
	while (color[j] != 0)
		j++;
	ft_color_check(j, map[i], identifier[0]);
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
	if (start != 0)
	{
		while (map[start] != 0)
			newmap[i++] = ft_strdup(map[start++]);
	}
	else
		ft_exit("map not found");
	return (newmap);
}
