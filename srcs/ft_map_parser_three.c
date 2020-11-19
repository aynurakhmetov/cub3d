/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_parser_three.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 13:19:00 by gmarva            #+#    #+#             */
/*   Updated: 2020/11/09 13:19:02 by gmarva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/cub3d.h"

void	ft_color_garbage_check_next(char *cstr)
{
	int i;
	int m;
	int l;

	i = -1;
	m = 0;
	l = 0;
	while (cstr[++i] != 0)
	{
		if (cstr[i] == ',')
			m++;
		if (m > 2)
			ft_exit("garbage in C");
		if ((cstr[i] == ' ' || cstr[i] == ',')
		&& (cstr[i + 1] >= '0' && cstr[i + 1] <= '9'))
			l++;
		if (l > 3)
			ft_exit("spaces in C");
	}
}

void	ft_texture_garbage_chek(char *tstr, char *identifier)
{
	int i;

	i = -1;
	while (tstr[++i] != 0)
	{
		if (ft_strncmp(identifier, "S ", ft_strlen(identifier)) != 0)
		{
			if (tstr[i] == identifier[0] && tstr[i + 1] == identifier[1]
				&& tstr[i + 2] != ' ')
				ft_exit("not spacet after texture identifier");
		}
	}
	i = -1;
	while (tstr[++i] != identifier[0])
	{
		if (tstr[i] != ' ')
			ft_exit("garbage before texture identifier");
	}
}

void	ft_make_newmap(char **map, char **newmap, int start, int i)
{
	if ((i - start) < 3)
		ft_exit("incorrect map - little line");
	i = 0;
	if (start != 0)
	{
		while (map[start] != 0)
			newmap[i++] = ft_strdup(map[start++]);
	}
	else
		ft_exit("map not found");
}

char	**ft_get_map(char **map)
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
			else if (start == 0)
				ft_newmap_garbage_check(map[i]);
		}
	}
	newmap = (char **)malloc(sizeof(char *) * (i - start + 1));
	ft_make_newmap(map, newmap, start, i);
	return (newmap);
}

void	ft_texture_open_check(char *address, char *identifier)
{
	if ((open(address, O_RDONLY)) == -1)
		ft_exit_identifier("texture does not open - ", identifier);
}
