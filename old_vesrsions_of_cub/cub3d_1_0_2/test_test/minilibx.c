/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minilibx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 16:18:38 by gmarva            #+#    #+#             */
/*   Updated: 2020/10/19 16:19:11 by gmarva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mylib/libft/libft.h"
#include "minilibx_mms/mlx.h"

typedef struct  s_data {
    void        *img;
    char        *addr;
    int         bits_per_pixel;
    int         line_length;
    int         endian;
}               t_data;

//Вывести окно
/*
int main(void)
{
    void *mlx = NULL;
    void *win = NULL;
    int x = 100;
    int y = 100;
    mlx = mlx_init();
    win = mlx_new_window(mlx, 650, 480, "test");
    while (y++ < 200)
    {
        x = 100;
        while (x++ < 200)
            mlx_pixel_put(mlx, win, x, y, 0xFFFFFF);
    }
    mlx_loop(mlx);
    return (0);
}
*/

void            my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char    *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

/*
int     main(void)
{
    t_data    img;
    void    *mlx;

    mlx = mlx_init();
    img.img = mlx_new_image(mlx, 1920, 1080);
    ** After creating an image, we can call `mlx_get_data_addr`, we pass
    ** `bits_per_pixel`, `line_length`, and `endian` by reference. These will
    ** then be set accordingly for the *current* data address.
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
    


      Теперь у нас есть адрес изображения, но все еще нет пикселей.
      Прежде чем мы начнем с этого, мы должны понять, что байты не выровнены, это означает,
      что line_lengthширина окна отличается от фактической.
      Поэтому мы должны ВСЕГДА рассчитывать смещение памяти, используя длину строки,
      установленную mlx_get_data_addr.
      Мы можем очень легко рассчитать это, используя следующую формулу:
    //int     offset = (y * line_length + x * (bits_per_pixel / 8));

    return (0);
}   
*/

int             main(void)
{
    void    *mlx;
    void    *mlx_win;
    t_data  img;

    mlx = mlx_init();
    mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
    img.img = mlx_new_image(mlx, 1920, 1080);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
                                 &img.endian);
    my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
    mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
    mlx_loop(mlx);
}