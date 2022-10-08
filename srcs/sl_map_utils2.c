/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_map_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 20:35:59 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/10/09 00:13:42 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	sl_map_copy_img(t_img *buffer, t_map *map, int p_x, int p_y)
{
	// sl_copy_img(buffer, map->img,
		// WINDOW_W / 2 - SPRITE_SIZE - p_x,
		// WINDOW_H / 2 - SPRITE_SIZE - p_y);
	sl_copy_img(buffer, map->img, (WINDOW_W - SPRITE_SIZE) / 2 - p_x, (WINDOW_H - SPRITE_SIZE) / 2 - p_y);
}