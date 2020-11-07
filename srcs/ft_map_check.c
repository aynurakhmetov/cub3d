/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 18:13:53 by gmarva            #+#    #+#             */
/*   Updated: 2020/11/07 18:13:58 by gmarva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/cub3d.h"

void ft_neighbors_cheсk(char **map, int i, int j)
{
	if (!map[i][j + 1] || map[i][j + 1] == ' ')
		ft_exit("the wall is not closed");
	if (!map[i][j - 1] || map[i][j - 1] == ' ')
		ft_exit("the wall is not closed");
	if (!map[i + 1][j] || map[i + 1][j] == ' ')
		ft_exit("the wall is not closed");
	if (!map[i - 1][j] || map[i - 1][j] == ' ')
		ft_exit("the wall is not closed");
	if (!map[i + 1][j + 1] || map[i + 1][j + 1] == ' ')
		ft_exit("the wall is not closed");
	if (!map[i - 1][j - 1] || map[i - 1][j - 1] == ' ')
		ft_exit("the wall is not closed");
	if (!map[i + 1][j - 1] || map[i + 1][j - 1] == ' ')
		ft_exit("the wall is not closed");
	if (!map[i - 1][j + 1] || map[i - 1][j + 1] == ' ')
		ft_exit("the wall is not closed");
}

void ft_line_of_spaces_chek(char *lineofmap)
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

void ft_spaces_in_line_chek(char *lineofmap, int j)
{
	int linestart;
	int lineend;

	linestart = j;
	while (lineofmap[linestart])
	{
		if (lineofmap[linestart] == '1')
			break;
		linestart++;
	}
	lineend = linestart;
	while (lineofmap[lineend++])
	{
		if (lineofmap[lineend] == '1' && (!lineofmap[lineend + 1] 
		|| lineofmap[lineend + 1] == ' '))
			break;
	}
	while (linestart < lineend)
	{
		if (lineofmap[linestart++] == ' ')
			ft_exit("space in line of map");
	}
	if (lineofmap[lineend + 1])
		ft_spaces_in_line_chek(lineofmap, lineend + 1);
}

void ft_map_test(char **map)
{
	int i;
	int j;

	i = 0;
	while(map[i])
	{
		j = 0;
		ft_line_of_spaces_chek(map[i]);
		ft_spaces_in_line_chek(map[i], j);
		while(map[i][j])
		{
			if (map[i][j] == '0' || map[i][j] == '2'
			|| map[i][j] == 'N' || map[i][j] == 'W'
			|| map[i][j] == 'E' || map[i][j] == 'S')
				ft_neighbors_cheсk(map, i, j);
			j++;
		}
		i++;
	}
}
