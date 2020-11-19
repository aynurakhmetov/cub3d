#include "mylib/libft/libft.h"
#include "minilibx_mms/mlx.h"
#include <stdlib.h>
#define KEY_W 13
#define KEY_A 0
#define KEY_S 1
#define KEY_D 2
#define KEY_RIGHT 124  
#define KEY_LEFT 123
#define KEY_ESCAPE 53
//#include <unistd.h>

typedef struct  s_vars {
    void        *mlx;
    void        *win;
}               t_vars;

int             fclose(int keycode, t_vars *vars)
{
    mlx_destroy_window(vars->mlx, vars->win);
    exit (0);
}

int             main(void)
{
    t_vars      vars;

    vars.mlx = mlx_init();
    vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Hello world!");
    mlx_key_hook(vars.win, fclose, &vars);
    mlx_loop(vars.mlx);
    return (0);
} 