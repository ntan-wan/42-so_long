/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_copy_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 10:31:09 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/10/04 16:17:28 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	is_pixel_black(char *pixel)
{
	return (*pixel == 0);
}

static void	sl_copy_pixel(char *dst, char *src, int bytes_per_pixel)
{
	int	i;

	i = -1;
	if (dst && src)
	{
		while (++i < bytes_per_pixel)
			*dst++ = *src++;
	}
	else
		ft_printf("copy_pixel: src or dst not found\n");
}

/* 
	Eg: coordinate = (0, -1), img = 4 x 4 resolution.
	Should copy 4 columns and 3 rows only as the first 
	row is out of boundary.Hence, start to copy from 
	0th(index) column and 1st(index) row. 
	Else, copy the whole img.
 */
static int	sl_copy_starting_pixel(int num)
{
	if (num < 0)
		num = -num;
	else
		num = -1;
	return (num);
}

/*
	s = sources
	d = destination
	x and y = dst's coordinate
 */
void	sl_copy_img(t_img *dst, t_img *src, int x, int y)
{
	int			i;
	int			j;
	t_img_addr	s;
	t_img_addr	d;

	if (!src || !dst)
	{
		ft_printf("copy_img: src or dst not found\n");
		return ;
	}
	s.addr = mlx_get_data_addr(src->img, &s.bpp, &s.size_line, &s.endian);
	d.addr = mlx_get_data_addr(dst->img, &d.bpp, &d.size_line, &d.endian);
	i = sl_copy_starting_pixel(y);
	while (++i < src->height && y + i < dst->height)
	{
		j = sl_copy_starting_pixel(x);
		while (++j < src->width && x + j < dst->width)
		{
			s.pixel = s.addr + ((i * s.size_line) + (j * (s.bpp / 8)));
			d.pixel = d.addr + ((i + y) * d.size_line + (j + x) * (d.bpp / 8));
			if (!is_pixel_black(s.pixel))
				sl_copy_pixel(d.pixel, s.pixel, 4);
		}
	}
}
