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

void	ft_neighbors_cheсk(char **map, int i, int j)
{
	if (!map[i][j + 1] || map[i][j + 1] == ' ')
		ft_exit("the wall is not closed sp");
	if (!map[i][j - 1] || map[i][j - 1] == ' ')
		ft_exit("the wall is not closed sl");
	if (!map[i + 1])
		ft_exit("the wall is not closed n1");
	if (map[i + 1][j] == ' ')
		ft_exit("the wall is not closed n2");
	if (i == 0)
		ft_exit("the wall is not closed v1");
	else if (map[i - 1][j] == ' ')
		ft_exit("the wall is not closed v1");
	if (!map[i - 1])
		ft_exit("the wall is not closed v1");
}

void	ft_diagonals_check(char **map, int i, int j)
{
	if (!map[i + 1][j + 1] || map[i + 1][j + 1] == ' ')
		ft_exit("the wall is not closed unp");
	if (!map[i - 1][j - 1] || map[i - 1][j - 1] == ' ')
		ft_exit("the wall is not closed uvl");
	if (!map[i + 1][j - 1] || map[i + 1][j - 1] == ' ')
		ft_exit("the wall is not closed unl");
	if (!map[i - 1][j + 1] || map[i - 1][j + 1] == ' ')
		ft_exit("the wall is not closed uvp");
}

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
		return (NULL);
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
		printf("%s\n", map[i]);
		ft_line_of_spaces_chek(map[i]);
		ft_spaces_in_line_chek(map[i], j);
		printf("ya tut1\n");
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
		printf("ya tut2\n");
	}
	printf("ya tut3\n");
}
