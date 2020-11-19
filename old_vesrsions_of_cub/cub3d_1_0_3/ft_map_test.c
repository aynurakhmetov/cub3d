#include "./cub.h"

void ft_neighbors_cheсk(char **map, int i, int j)
{
	if (!map[i][j + 1] || map[i][j + 1] == ' ')
	{
       ft_putendl_fd("ERROR MESSAGE: the wall is not closed", 1); 
       exit(0);
    }
	if (!map[i][j - 1] || map[i][j - 1] == ' ')
	{
       ft_putendl_fd("ERROR MESSAGE: the wall is not closed", 1); 
       exit(0);
    }
	if (!map[i + 1][j] || map[i + 1][j] == ' ')
	{
       ft_putendl_fd("ERROR MESSAGE: the wall is not closed", 1); 
       exit(0);
    }
	if (!map[i - 1][j] || map[i - 1][j] == ' ')
	{
       ft_putendl_fd("ERROR MESSAGE: the wall is not closed", 1); 
       exit(0);
    }
}

void ft_diagonals_cheсk(char **map, int i, int j)
{
	if (!map[i + 1][j + 1] || map[i + 1][j + 1] == ' ')
	{
       ft_putendl_fd("ERROR MESSAGE: the wall is not closed", 1); 
       exit(0);
    }
	if (!map[i - 1][j - 1] || map[i - 1][j - 1] == ' ')
	{
       ft_putendl_fd("ERROR MESSAGE: the wall is not closed", 1); 
       exit(0);
    }
	if (!map[i + 1][j - 1] || map[i + 1][j - 1] == ' ')
	{
       ft_putendl_fd("ERROR MESSAGE: the wall is not closed", 1); 
       exit(0);
    }
	if (!map[i - 1][j + 1] || map[i - 1][j + 1] == ' ')
	{
       ft_putendl_fd("ERROR MESSAGE: the wall is not closed", 1); 
       exit(0);
    }
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
	{
       ft_putendl_fd("ERROR MESSAGE: empty line in map", 1); 
       exit(0);
    }

}

void ft_spaces_in_line_chek(char *lineofmap, int j)
{
	int linestart;
	int lineend;

	linestart = j;
	lineend = linestart;
	while (lineofmap[linestart])
	{
		if (lineofmap[linestart] == '1')
			break;
		linestart++;
	}
	lineend = linestart;
	while (lineofmap[lineend])
	{
		if (lineofmap[lineend] == '1' && (!lineofmap[lineend + 1] || lineofmap[lineend + 1] == ' '))
			break;
		lineend++;
	}
	while (linestart < lineend)
	{
		if (lineofmap[linestart] == ' ')
		{
       		ft_putendl_fd("ERROR MESSAGE: space in line of map", 1); 
       		exit(0);
    	}
		linestart++;
	}
	if (lineofmap[lineend + 1])
		ft_spaces_in_line_chek(lineofmap, lineend + 1);
}

void ft_map_test(char **map)
{
	printf("MAP TEST %c\n", map[0][0]);
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
			if (map[i][j] == '0' || map[i][j] == '2' ||
			map[i][j] == 'N' || map[i][j] == 'W'||
			map[i][j] == 'E' || map[i][j] == 'S')
			{
				ft_neighbors_cheсk(map, i, j);
				ft_diagonals_cheсk(map, i, j);
			}
			j++;
		}
		i++;
	}
}