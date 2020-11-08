/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 18:14:29 by gmarva            #+#    #+#             */
/*   Updated: 2020/11/07 18:14:36 by gmarva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

#define SCALE 64
#define KEY_W 13
#define KEY_A 0
#define KEY_S 1
#define KEY_D 2
#define KEY_RIGHT 124  
#define KEY_LEFT 123
#define KEY_ESCAPE 53

#include "./../minilibx_mms/mlx.h"
#include "./../mylib/libft/libft.h"
#include "./../mylib/gnl/get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

#define FOV M_PI/3

typedef struct	s_map 
{
	int xrendersize;
	int yrendersize;
	char *northtexture;
	char *southtexture;
	char *westtexture;
	char *easttexture;
	char *spritetexture;
	unsigned int floorcolor;
	unsigned int ceilingcolor;
	char **map;

}				t_map;

typedef struct	s_win 
{
	void		*mlx;
	void		*win;
	void		*img;
	void *addr;
	int			bits_per_pixel;
	int			line_length; 
	int			endian;
}				t_win;

typedef struct	s_point 
{
	float			x;
	float			y;
}				t_point;

typedef struct s_wall
{
	float distance;
    float perpendicular;
    float height;
    float start;
    float end;
    float y_draw;
    float x_draw;
    float angle;
	unsigned int wall_color;
}	t_wall;

typedef struct	s_sprite 
{
	float			x;
	float			y;
	float 			ray;
	float			dist;
	int				len;
}				t_sprite;

typedef struct s_spriteinfo
{
	float i;
	float j;
	float distance;
	float dir;
	float screen_size;
	float step; 
	float	pos;
	char *color;
	int h_offset;
	int v_offset;
	int		y;
	int		x;
}	t_spriteinfo;

typedef struct	s_plr 
{
	float		x;
	float		y;
	float		dir;
	float		start;
	float		end;
}				t_plr;

typedef struct	s_texture
{
	float			x;
	float			y;
	void		*image;
	int			img_width;
	int			img_height;
	void *addr;
	int			bits_per_pixel;
	int			line_length; 
	int			endian;
}				t_texture;

typedef struct	s_all 
{
	t_win		*win;
	t_plr		*plr;
	t_point		*point;
	t_map		*mapinfo;
	t_texture	text[5];
	t_sprite	*sprites;
	float 		*dist_wall;
	char		**map;
	char		new_dir;
	int			spritelen;
}				t_all;


int		ft_get_render_size(char **map, int numOfRes);
char	*ft_get_texture(char **map, char *identifier);
unsigned int 	ft_get_color(char **map, char *identifier);
char	**ft_get_map(char **map);
int ft_get_line_mumber(char **map, char *identifier);
void	ft_start_game(t_map mapInfo, int savebmp);
int		key_press(int keycode, t_all * all);
t_plr	ft_get_plr_info(t_map mapInfo);
t_all   ft_get_all_info(t_map mapinfo, t_win data);
int ft_finish_game(t_all *all);
void	ft_cast_rays(t_all *all);
void    ft_draw(t_all *all, float i, float j, int color);
int     ft_render_next_frame(t_all *all);
void	ft_cub_2d(t_all *all);
void    ft_draw_wall(t_all *all, t_plr ray, int i);
void 	my_mlx_pixel_put(t_all *all, int x, int y, int color);
t_sprite  *ft_get_sprite_info(t_map mapInfo);
void ft_draw_sprite_2(t_all *all);
int				ft_screenshot(t_all *all);
void ft_draw_sprites(t_all *all);
void ft_map_test(char **map);
void ft_exit(char *errormassage);
void ft_exit_identifier(char *errormassage, char *identifier);
char	ft_get_new_dir(t_plr ray, t_all *all);
char *ft_get_texture_color(t_all *all, int h, int w, int textmum);

#endif