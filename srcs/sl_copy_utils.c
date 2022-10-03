/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_copy_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 10:31:09 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/10/02 11:34:35 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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
	s = sources
	d = destination
	x and y = dst's coordinate
	src->x = src img width
	src->y = src img height
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
	i = -1;
	while (++i < src->height)
	{
		j = -1;
		while (++j < src->width)
		{
			s.pixel = s.addr + ((i * s.size_line) + (j * (s.bpp / 8)));
			d.pixel = d.addr + ((i + y) * d.size_line + (j + x) * (d.bpp / 8));
			sl_copy_pixel(d.pixel, s.pixel, 4);
		}
	}
}
