/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_block.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 09:26:03 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/10/05 10:11:50 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/* 
	center_point = player's center point starting from x or y.
	o_coord = obstruction's coordinate.
	check whether player is within obstruction's range.
 */
int	sl_is_blocked_range(int p_coord, int o_coord)
{
	return (p_coord + SPRITE_SIZE >= o_coord && p_coord <= o_coord + SPRITE_SIZE);
}

/* 
	p_x = player's x coordinate.
	o_x = obstruction's x coordinate.
	check whether obstruction is on the right.
 */
int	sl_is_blocked_right(int action, int p_x, int o_x)
{
	return (action == MOVE_RIGHT && p_x + SPRITE_SIZE == o_x);
}

int	sl_is_blocked_left(int action, int p_x, int o_x)
{
	return (action == MOVE_LEFT && p_x - SPRITE_SIZE == o_x);
}

/* 
    point = x axis or y axis' point.
    Get the center coordinate of a img.
 */

int	sl_is_blocked(int action, int p_x, int p_y, int o_x, int o_y)
{
	if (sl_is_blocked_right(action, p_x, o_x) && sl_is_blocked_range(p_y, o_y))
		return (1);
	else if (sl_is_blocked_left(action, p_x, o_x) && sl_is_blocked_range(p_y, o_y))
		return (1);
	return (0);
}
