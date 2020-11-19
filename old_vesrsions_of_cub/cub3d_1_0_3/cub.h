#define SCALE 64 // условный размер каждого квадратика в карте

#define FOV 3.14/3

#define KEY_W 13
#define KEY_A 0
#define KEY_S 1
#define KEY_D 2
#define KEY_RIGHT 124  
#define KEY_LEFT 123
#define KEY_ESCAPE 53

#include "minilibx_mms/mlx.h"
#include "mylib/libft/libft.h"
#include "mylib/gnl/get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>


// Struct for map and parameters for map

typedef struct	s_map 
{
	int xRenderSize;
	int yRenderSize;
	char *northTexture;
	char *southTexture;
	char *westTexture;
	char *eastTexture;
	char *spriteTexture;
	unsigned int floorColor;
	unsigned int ceilingColor;
	char **map;

}				t_map;

typedef struct	s_win //структура для окна
{
	void		*mlx;
	void		*win;
	void		*img;
	//unsigned int		*addr;
	void *addr;
	int			bits_per_pixel;
	int			line_length; 
	int			endian;
}				t_win;

typedef struct	s_point // структура для точки
{
	float			x;
	float			y;
}				t_point;

typedef struct	s_sprite // структура для точки
{
	float			x;
	float			y;
	float 			ray;
	float			dist;
	int				len;
}				t_sprite;


typedef struct	s_plr //структура для игрока и луча
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
	//unsigned int		*addr;
	void *addr;
	int			bits_per_pixel;
	int			line_length; 
	int			endian;
}				t_texture;

typedef struct	s_all // структура для всего вместе
{
	t_win		*win;
	t_plr		*plr;
	t_point		*point;
	t_map		*mapInfo;
	t_texture	text[5];
	t_sprite	*sprites;
	float 		*dist_wall;
	char		**map;
	char		new_dir;
	int			texlen;
}				t_all;


int		ft_get_render_size(char **map, int numOfRes);
char	*ft_get_texture(char **map, char *identifier);
int 	ft_get_color(char **map, char *identifier);
char	**ft_get_map(char **map);
void	ft_start_game(t_map mapInfo, int savebmp);
int		key_press(int keycode, t_all * all);
int		key_release(int keycode, t_all * all);
t_plr	ft_get_plr_info(t_map mapInfo);
t_all	ft_get_all_info(t_plr plr, t_map mapInfo, t_win data, t_point point);
void	ft_cast_rays(t_all *all);
void    ft_draw(t_all *all, float i, float j, int color);
int     ft_render_next_frame(t_all *all);
void	ft_cub_2d(t_all *all);
void    ft_draw_wall(t_all *all, float y_draw, float x_draw, int i, float ugol);
void 	my_mlx_pixel_put(t_all *all, int x, int y, int color);
void	ft_draw_sprite(t_all *all, float y_draw, float x_draw, int i, float ugol, t_plr ray);
t_sprite  *ft_get_sprite_info(t_map mapInfo);
void ft_draw_sprite_2(t_all *all);
int				screenshot(t_all *all);
void ft_draw_sprites(t_all *all);
void ft_map_test(char **map);