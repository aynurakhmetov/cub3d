#include "./../includes/cub3d.h"

float		ft_get_dir_info(char **map, int i, int j)
{
	if (map[i][j] == 'N')
		return (3.14 * 1.5);
	if (map[i][j] == 'E')
		return (3.14 * 2);
	if (map[i][j] == 'W')
		return (3.14);
	if (map[i][j] == 'S')
		return (3.14 / 2);
	return (0);
}

t_plr		ft_get_plr_info(t_map mapinfo)
{
	t_plr	plr;
	int		i;
	int		j;

	i = 0;
	while (mapinfo.map[i])
	{
		j = 0;
		while (mapinfo.map[i][j])
		{
			if (mapinfo.map[i][j] == 'N' || mapinfo.map[i][j] == 'E'
			|| mapinfo.map[i][j] == 'W' || mapinfo.map[i][j] == 'S')
			{
				plr.x = j * SCALE + SCALE / 2;
				plr.y = i * SCALE + SCALE / 2;
				plr.dir = ft_get_dir_info(mapinfo.map, i, j);
				break ;
			}
			j++;
		}
		i++;
	}
	return (plr);
}

int			ft_get_number_of_sprites(t_map mapinfo)
{
	int i;
	int j;
	int l;

	i = 0;
	l = 0;
	while (mapinfo.map[i])
	{
		j = 0;
		while (mapinfo.map[i][j])
		{
			if (mapinfo.map[i][j] == '2' && mapinfo.map[i][j] != '1')
				l++;
			j++;
		}
		i++;
	}
	return (l);
}

t_sprite	*ft_get_sprite_info(t_map mapinfo)
{
	t_sprite	*sprites;
	int			len;
	int			i;
	int			j;
	int			l;

	len = ft_get_number_of_sprites(mapinfo);
	if (!(sprites = malloc(sizeof(t_sprite) * (len + 1))))
		ft_exit("malloc problem in ft_get_sprite_info");
	if (len == 0)
		sprites[0].len = 0;
	i = -1;
	l = 0;
	while (mapinfo.map[++i])
	{
		j = -1;
		while (mapinfo.map[i][++j])
			if (mapinfo.map[i][j] == '2' && mapinfo.map[i][j] != '1')
			{
				sprites[l].len = len;
				sprites[l].x = j * SCALE + SCALE / 2;
				sprites[l++].y = i * SCALE + SCALE / 2;
			}
	}
	return (sprites);
}

t_all		ft_get_all_info(t_map mapinfo, t_win data)
{
	t_all		all;
	t_plr		*plr;
	t_point		point;
	t_sprite	*sprite;

	point.x = 0;
	point.y = 0;
	sprite = ft_get_sprite_info(mapinfo);
	all.map = mapinfo.map;
	all.win = &data;
	all.point = &point;
	all.mapinfo = &mapinfo;
	all.sprites = sprite;
	all.spritelen = sprite[0].len;
	if (!(plr = malloc(sizeof(t_plr) * 1)))
		ft_finish_game(&all);
	*plr = ft_get_plr_info(mapinfo);
	all.plr = plr;
	if (!(all.dist_wall = malloc(sizeof(float)
		* (all.mapinfo->xrendersize + 1))))
		ft_finish_game(&all);
	return (all);
}
