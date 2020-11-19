/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarva <gmarva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 18:13:53 by gmarva            #+#    #+#             */
/*   Updated: 2020/11/09 18:53:28 by gmarva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/cub3d.h"

void	ft_line_of_spaces_chek(char *lineofmap)
{
	int j;
	int k;

	j = 0;
	k = 0;
	while (lineofmap[j])
	{
		if (lineofmap[j] == ' ')
			k++;
		j++;
	}
	if (k == (int)ft_strlen(lineofmap))
		ft_exit("empty line in map");
}

void	ft_spaces_in_line_chek(char *lineofmap, int j)
{
	int linestart;
	int lineend;

	linestart = j;
	while (lineofmap[linestart])
	{
		if (lineofmap[linestart] == '1')
			break ;
		linestart++;
	}
	lineend = linestart;
	while (lineofmap[lineend++])
	{
		if (lineofmap[lineend] == '1' && (!lineofmap[lineend + 1]
		|| lineofmap[lineend + 1] == ' '))
			break ;
	}
	while (linestart < lineend)
	{
		if (lineofmap[linestart++] == ' ')
			ft_exit("space in line of map");
	}
	if (lineofmap[lineend + 1])
		ft_spaces_in_line_chek(lineofmap, lineend + 1);
}

void	*ft_bspaces(size_t num, size_t size)
{
	char			*des;
	size_t			i;

	if (!(des = (void *)malloc(num * size)))
		ft_exit("malloc error bsapces");
	ft_bzero(des, num * size);
	i = 0;
	while (i < size)
	{
		des[i] = ' ';
		i++;
	}
	return (des);
}

void	ft_add_spaces(char **map)
{
	int		i;
	int		len;
	int		k;
	char	*tmp;

	i = -1;
	len = 0;
	k = 0;
	while (map[++i] != 0)
	{
		k = (int)ft_strlen(map[i]);
		if (k > len)
			len = k;
	}
	i = -1;
	while (map[++i] != 0)
	{
		if ((k = (int)ft_strlen(map[i])) < len)
		{
			tmp = ft_bspaces(len - k, sizeof(char));
			map[i] = ft_strjoin(map[i], tmp);
			free(tmp);
		}
	}
}

void	ft_map_test(char **map)
{
	int i;
	int j;

	i = 0;
	ft_add_spaces(map);
	while (map[i] != 0)
	{
		j = 0;
		ft_line_of_spaces_chek(map[i]);
		ft_spaces_in_line_chek(map[i], j);
		while (map[i][j] != 0)
		{
			if (map[i][j] == '0' || map[i][j] == '2'
			|| map[i][j] == 'N' || map[i][j] == 'W'
			|| map[i][j] == 'E' || map[i][j] == 'S')
			{
				ft_neighbors_cheсk(map, i, j);
				ft_diagonals_check(map, i, j);
			}
			j++;
		}
		i++;
	}
}
