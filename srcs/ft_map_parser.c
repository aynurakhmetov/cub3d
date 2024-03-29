#include "./../includes/cub3d.h"

int		ft_get_line_mumber(char **map, char *identifier)
{
	int i;
	int j;
	int k;
	int m;

	i = -1;
	m = -1;
	k = 0;
	while (map[++i] != 0)
	{
		j = -1;
		while (map[i][++j])
		{
			if (ft_strncmp(&map[i][j], identifier, ft_strlen(identifier)) == 0)
			{
				m = i;
				k++;
				if (k > 1)
					ft_exit("many identifier");
			}
		}
	}
	if (m == -1 && identifier[0] == 'R')
		ft_exit_identifier("identifier not found - ", identifier);
	return (m);
}

int		ft_render_cheсk(int r_num_1, int r_num_2, int numofres)
{
	if (r_num_1 <= 0 || r_num_2 <= 0)
		ft_exit("incorrect R");
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

void	ft_render_garbage_check(char *rstr)
{
	int j;
	int k;
	int m;

	j = -1;
	k = 0;
	m = 0;
	while (rstr[++j] != 0)
	{
		if ((rstr[j] < '0' || rstr[j] > '9') && rstr[j] != ' '
		&& rstr[j] != '-' && rstr[j] != '+' && rstr[j] != 'R'
		&& rstr[j] != '\t')
			ft_exit("garbage in R");
		if ((rstr[j] == '+' || rstr[j] == '-')
		&& (rstr[j + 1] < '0' || rstr[j + 1] > '9'))
			ft_exit("garbage in R");
		if (rstr[j] == 'R')
			k++;
		if (k > 1)
			ft_exit("garbage in R");
		if (rstr[j] == ' ' && (rstr[j + 1] >= '0' && rstr[j + 1] <= '9'))
			m++;
		if (m > 2)
			ft_exit("garbage in R");
	}
}

int		ft_get_render_size(char **map, int numofres)
{
	int	i;
	int	j;
	int	r_num_1;
	int	r_num_2;

	j = -1;
	r_num_1 = -1;
	r_num_2 = -1;
	i = ft_get_line_mumber(map, "R ");
	ft_render_garbage_check(map[i]);
	while (map[i][++j] != 0)
	{
		if ((map[i][j] >= '0' && map[i][j] <= '9')
		|| map[i][j] == '-' || map[i][j] == '+')
		{
			if (r_num_1 == -1)
			{
				r_num_1 = ft_atoi(&map[i][j]);
				j++;
			}
			if (r_num_1 != -1 && map[i][j - 1] == ' ')
				r_num_2 = ft_atoi(&map[i][j]);
		}
	}
	return (ft_render_cheсk(r_num_1, r_num_2, numofres));
}

char	*ft_get_texture(char **map, char *identifier)
{
	int		i;
	int		j;
	int		k;
	int		start;
	char	*address;

	j = -1;
	k = 0;
	if ((i = ft_get_line_mumber(map, identifier)) == -1)
		ft_exit_identifier("texture identifier not found - ", identifier);
	while (map[i][++j] != 0)
	{
		if (map[i][j] != ' ' && map[i][j]
		!= identifier[0] && map[i][j] != identifier[1])
		{
			if (k == 0)
				start = j;
			k++;
		}
	}
	address = ft_substr(map[i], start, k);
	ft_texture_open_check(address, identifier);
	ft_texture_garbage_chek(map[i], identifier);
	return (address);
}
