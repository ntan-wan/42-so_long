/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_check_path_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 13:32:18 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/10/25 16:52:02 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	sl_flood_fill(t_map *map, int p_x, int p_y, int o_x, int o_y)
{
	if (p_x ==  o_x && p_y == o_y)
	{
		ft_printf("is valid path\n");
		return ;
	}
	if (sl_is_wall(map, p_x, p_y))
		return ;
	sl_flood_fill(map, p_x + SPRITE_SIZE, p_y, o_x, o_y);
	// sl_flood_fill(map, p_x - SPRITE_SIZE, p_y, o_x, o_y);
	// sl_flood_fill(map, p_x, p_y + SPRITE_SIZE, o_x, o_y);
	// sl_flood_fill(map, p_x, p_y - SPRITE_SIZE, o_x, o_y);
	return ;
}

void	sl_check_exit_path(t_map *map, t_player *p, t_door *d)
{
	sl_flood_fill(map, p->x, p->y, d->x, d->y);
}