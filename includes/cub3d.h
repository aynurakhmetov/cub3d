#ifndef CUB3D_H
# define CUB3D_H
# define SCALE 64
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_RIGHT 124
# define KEY_LEFT 123
# define KEY_ESCAPE 53
# include "./../minilibx_mms/mlx.h"
# include "./../mylib/libft/libft.h"
# include "./../mylib/gnl/get_next_line.h"
# include <fcntl.h>
# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# define FOV M_PI/3

typedef struct	s_map
{
	int				xrendersize;
	int				yrendersize;
	char			*northtexture;
	char			*southtexture;
	char			*westtexture;
	char			*easttexture;
	char			*spritetexture;
	unsigned int	floorcolor;
	unsigned int	ceilingcolor;
	char			**map;
}				t_map;

typedef struct	s_win
{
	void		*mlx;
	void		*win;
	void		*img;
	void		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_win;

typedef struct	s_point
{
	float		x;
	float		y;
}				t_point;

typedef struct	s_wall
{
	float			distance;
	float			perpendicular;
	float			height;
	float			start;
	float			end;
	float			y_draw;
	float			x_draw;
	float			angle;
	unsigned int	wall_color;
}				t_wall;

typedef struct	s_sprite
{
	float		x;
	float		y;
	float		dist;
	int			len;
}				t_sprite;

typedef struct	s_spriteinfo
{
	float		i;
	float		j;
	float		distance;
	float		dir;
	float		screen_size;
	float		step;
	float		pos;
	char		*color;
	int			h_offset;
	int			v_offset;
	int			y;
	int			x;
}				t_spriteinfo;

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
	float		x;
	float		y;
	void		*image;
	void		*addr;
	int			img_width;
	int			img_height;
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
	float		*dist_wall;
	char		**map;
	char		new_dir;
	int			spritelen;
}				t_all;

int				ft_get_render_size(char **map, int numofres);
char			*ft_get_texture(char **map, char *identifier);
unsigned int	ft_get_color(char **map, char *identifier);
char			**ft_get_map(char **map);
int				ft_get_line_mumber(char **map, char *identifier);
void			ft_map_test(char **map);
void			ft_color_garbage_check_next(char *cstr);
void			ft_texture_garbage_chek(char *tstr, char *identifier);
int				ft_newmap_garbage_check(char *str);
void			ft_playmap_garbage_check(char c);
void			ft_texture_open_check(char *address, char *identifier);
void			ft_neighbors_check(char **map, int i, int j);
void			ft_diagonals_check(char **map, int i, int j);
void			ft_start_game(t_map mapinfo, int savebmp);
int				ft_key_press(int keycode, t_all *all);
t_plr			ft_get_plr_info(t_map mapinfo);
t_sprite		*ft_get_sprite_info(t_map mapinfo);
t_all			ft_get_all_info(t_map mapinfo, t_win data);
int				ft_render_next_frame(t_all *all);
void			ft_cast_rays(t_all *all);
void			ft_draw_wall_after_sprite(t_all *all, t_plr ray, int i);
void			ft_cub_2d(t_all *all);
void			ft_draw(t_all *all, float i, float j, int color);
void			ft_draw_wall(t_all *all, t_plr ray, int i);
void			ft_draw_sprites(t_all *all);
char			ft_get_new_dir(t_plr ray, t_all *all);
char			*ft_get_texture_color(t_all *all, int h, int w, int textmum);
int				ft_screenshot(t_all *all);
void			ft_exit(char *errormassage);
void			ft_exit_identifier(char *errormassage, char *identifier);
int				ft_finish_game(t_all *all);
void			ft_lstclear_here(t_list **lst);
void			ft_free_array(char **str);
void			ft_cub_2d(t_all *all);

#endif
