/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_screenshote.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarva <gmarva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 18:13:26 by gmarva            #+#    #+#             */
/*   Updated: 2020/11/09 18:58:35 by gmarva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/cub3d.h"

int		ft_make_head(unsigned char *bmp_head,
	unsigned char *bmp_fhead, t_all *all)
{
	int		size;

	size = 14 + 40 + all->mapinfo->xrendersize * all->mapinfo->yrendersize
			* all->win->bits_per_pixel / 8;
	bmp_head[0] = 'B';
	bmp_head[1] = 'M';
	bmp_head[2] = (unsigned char)(size);
	bmp_head[3] = (unsigned char)(size >> 8);
	bmp_head[4] = (unsigned char)(size >> 16);
	bmp_head[5] = (unsigned char)(size >> 24);
	bmp_head[10] = (unsigned char)(54);
	bmp_fhead[0] = (unsigned char)(40);
	bmp_fhead[4] = (unsigned char)(all->mapinfo->xrendersize);
	bmp_fhead[5] = (unsigned char)(all->mapinfo->xrendersize >> 8);
	bmp_fhead[6] = (unsigned char)(all->mapinfo->xrendersize >> 16);
	bmp_fhead[7] = (unsigned char)(all->mapinfo->xrendersize >> 24);
	bmp_fhead[8] = (unsigned char)(-all->mapinfo->yrendersize);
	bmp_fhead[9] = (unsigned char)(-all->mapinfo->yrendersize >> 8);
	bmp_fhead[10] = (unsigned char)(-all->mapinfo->yrendersize >> 16);
	bmp_fhead[11] = (unsigned char)(-all->mapinfo->yrendersize >> 24);
	bmp_fhead[12] = (unsigned char)(1);
	bmp_fhead[14] = (unsigned char)(all->win->bits_per_pixel);
	return (1);
}

int		ft_make_file_screen(unsigned char *bmp_head,
	unsigned char *bmp_fhead, t_all *all)
{
	int		fd;
	char	*filename;
	int		i;
	int		size;

	i = 0;
	filename = "screenshot.bmp";
	if ((fd = open(filename, O_RDWR | O_CREAT, 0777)) < 0)
		return (0);
	write(fd, bmp_head, 14);
	write(fd, bmp_fhead, 40);
	size = all->win->bits_per_pixel / 8 * all->mapinfo->xrendersize;
	while (i < all->mapinfo->yrendersize)
	{
		write(fd, all->win->addr + i * all->win->line_length, size);
		i++;
	}
	return (1);
}

int		ft_screenshot(t_all *all)
{
	unsigned char	bmp_head[14];
	unsigned char	bmp_fhead[40];

	ft_putendl_fd("screenshot saved", 1);
	ft_bzero(bmp_head, 14);
	ft_bzero(bmp_fhead, 40);
	ft_make_head(bmp_head, bmp_fhead, all);
	if (!(ft_make_file_screen(bmp_head, bmp_fhead, all)))
		ft_putendl_fd("Problem with screenshot saving", 1);
	mlx_destroy_window(all->win->mlx, all->win->win);
	exit(0);
	return (0);
}
