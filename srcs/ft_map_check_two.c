/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_check_two.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarva <gmarva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 18:51:54 by gmarva            #+#    #+#             */
/*   Updated: 2020/11/09 19:06:48 by gmarva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/cub3d.h"

void	ft_neighbors_cheсk(char **map, int i, int j)
{
	if (!map[i][j + 1] || map[i][j + 1] == ' ')
		ft_exit("the wall is not closed");
	if (!map[i][j - 1] || map[i][j - 1] == ' ')
		ft_exit("the wall is not closed");
	if (!map[i + 1])
		ft_exit("the wall is not closed");
	if (map[i + 1][j] == ' ')
		ft_exit("the wall is not closed");
	if (i == 0)
		ft_exit("the wall is not closed");
	else if (map[i - 1][j] == ' ')
		ft_exit("the wall is not closed");
	if (!map[i - 1])
		ft_exit("the wall is not closed");
}

void	ft_diagonals_check(char **map, int i, int j)
{
	if (!map[i + 1][j + 1] || map[i + 1][j + 1] == ' ')
		ft_exit("the wall is not closed");
	if (!map[i - 1][j - 1] || map[i - 1][j - 1] == ' ')
		ft_exit("the wall is not closed");
	if (!map[i + 1][j - 1] || map[i + 1][j - 1] == ' ')
		ft_exit("the wall is not closed");
	if (!map[i - 1][j + 1] || map[i - 1][j + 1] == ' ')
		ft_exit("the wall is not closed");
}

void	ft_playmap_garbage_check(char c)
{
	if (c != 'N' && c != 'E'
			&& c != 'W' && c != 'S'
			&& c != '1' && c != '2'
			&& c != '0' && c != ' ')
		ft_exit("garbage in the map");
}
