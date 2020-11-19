#include <mlx.h>

// EVENTS
/*
typedef struct  s_vars {
        void    *mlx;
        void    *win;
}               t_vars;

int             close(int keycode, t_vars *vars)
{
    mlx_destroy_window(vars->mlx, vars->win);
    return (0);
}

int             main(void)
{
    t_vars    vars;

    vars.mlx = mlx_init();
    vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Hello world!");
    mlx_hook(vars.win, 2, 1L<<0, close, &vars);
    mlx_loop(vars.mlx);
} 
*/

//LOOPS
/*
int     render_next_frame(void *YourStruct);

int     main(void)
{
    void    *mlx;

    mlx = mlx_init();
    mlx_loop_hook(mlx, render_next_frame, YourStruct);
    mlx_loop(mlx);
}
*/

//IMAGES
/*
int     main(void)
{
    void    *mlx;
    void    *img;
    char    *relative_path = "./test.xpm";
    void    *mlx_win;
    int     img_width;
    int     img_height;

    mlx = mlx_init();
    mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
    img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
    mlx_put_image_to_window(mlx, mlx_win, img, 35, 35);
    mlx_loop(mlx);
}
*/

//SYNC
#define MLX_SYNC_IMAGE_WRITABLE    1 
#define MLX_SYNC_WIN_FLUSH_CMD     2
#define MLX_SYNC_WIN_CMD_COMPLETED 3

int	mlx_sync(int cmd, void *ptr);

