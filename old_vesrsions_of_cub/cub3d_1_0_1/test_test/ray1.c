#include <math.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "mylib/libft/libft.h"
#include "minilibx_mms/mlx.h"
#define KEY_W 13
#define KEY_A 0
#define KEY_S 1
#define KEY_D 2
#define KEY_RIGHT 124  
#define KEY_LEFT 123
#define KEY_ESCAPE 53

typedef struct  s_vars {
        void    *mlx;
        void    *win;
}               t_vars;

typedef struct	s_plr //структура для игрока и луча
{
	float		x;
	float		y;
	float		dir;
	float		start;
	float		end;
}				 t_plr;

int             ft_close(int keycode, t_vars *vars)
{
    if (keycode == KEY_ESCAPE)
        printf("%d", 1);
        //mlx_destroy_window(vars->mlx, vars->win);
    if (keycode == KEY_W)
        printf("%d", 1);
    if (keycode == KEY_A)
        printf("%d", 1);
    if (keycode == KEY_D)
        printf("%d", 1);
    if (keycode == KEY_S)
        printf("%d", 1);
    if (keycode == KEY_LEFT)
        printf("%d", 1);
    if (keycode == KEY_RIGHT)
        printf("%d", 1);
    exit (0);
}

int main()
{
    char **map;
    int i;
    i = 0;
    map = (char **)malloc(sizeof(char*) * 5);
    while (i < 5)
    {
        map[i] = (char *)malloc(sizeof(char) * 5);
        i++;
    }
    map[0] = "1111";
    map[1] = "1001";
    map[2] = "1001";
    map[3] = "1111";

    int nScreenWidth = 1280; // Ширина консольного окна
    int nScreenHeight = 1080; // Высота консольного окна
    float fPlayerX = 1.0; // Координата игрока по оси X
    float fPlayerY = 1.0; // Координата игрока по оси Y
    float fPlayerA = 0.0; // Направление игрока
    int nMapHeight = 16; // Высота игрового поля
    int nMapWidth = 16;	 // Ширина игрового поля
    float fFOV = 3.14159 / 3; // Угол обзора (поле видимости)
    float fDepth = 30.0f;	  // Максимальная дистанция обзора

    t_vars    vars;

    vars.mlx = mlx_init();
    vars.win = mlx_new_window(vars.mlx, nScreenWidth, nScreenHeight, "Hello world!");
    mlx_key_hook(vars.win, ft_close, &vars);
    mlx_loop(vars.mlx);

    return (0);

}