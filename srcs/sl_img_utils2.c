/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_img_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 11:22:21 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/10/11 11:25:25 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/* init + add imgs */
void	sl_img_load(void *mlx, t_img **head, char *key, char *path)
{
	sl_img_add(head, sl_img_init(mlx, key, path));
}

t_img	*sl_img_new(void *mlx, int width, int height)
{
	t_img	*new_img;

	new_img = (t_img *)malloc(sizeof(t_img));
	new_img->width = width;
	new_img->height = height;
	new_img->img = mlx_new_image(mlx, width, height);
	return (new_img);
}
