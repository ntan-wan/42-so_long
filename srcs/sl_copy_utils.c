/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_copy_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 10:31:09 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/09/27 18:39:34 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	sl_copy_pixel(char *dst, char *src, int bytes_per_pixel)
{
	int	i;

	i = -1;
	while (++i < bytes_per_pixel)
		*dst++ = *src++;
}

/* 
	s = sources
	d = destination
	src -> x = src img width
	src -> y = src img height
 */
void	sl_copy_img(t_img *dst, t_img *src)
{
	int			x;
	int			y;
	t_img_addr	s;
	t_img_addr	d;

	s.addr = mlx_get_data_addr(src->img, &s.bpp, &s.size_line, &s.endian);
	d.addr = mlx_get_data_addr(dst->img, &d.bpp, &d.size_line, &d.endian);
	y = -1;
	while (++y < src->y)
	{
		x = -1;
		while (++x < src->x)
		{
			s.pixel = s.addr + ((y * s.size_line) + (x * (s.bpp / 8)));
			d.pixel = d.addr + ((y * d.size_line) + (x * (d.bpp / 8)));
			sl_copy_pixel(d.pixel, s.pixel, 4);
		}
	}	
}
