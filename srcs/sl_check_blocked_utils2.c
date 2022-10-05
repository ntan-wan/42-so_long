/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_check_blocked_utils2.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 16:34:45 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/10/05 18:29:05 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/* 
	+ 10 = control entry blocked range.
	- 10 = control leaving blocked range.
	the larger the number above, the smaller the blocked range.
 */
int	sl_is_blocked_range(int p_coord, int o_coord)
{
	return (p_coord + SPRITE_SIZE >= o_coord + 8
		&& p_coord <= o_coord + SPRITE_SIZE - 8);
}

int	sl_is_blocked_right(int action, int p_x, int o_x)
{
	return (action == MOVE_RIGHT && p_x + SPRITE_SIZE == o_x);
	//return (dir == IDLE_RIGHT && p_x + SPRITE_SIZE == o_x);
}

int	sl_is_blocked_left(int action, int p_x, int o_x)
{
	return (action == MOVE_LEFT && p_x - SPRITE_SIZE == o_x);
}

int	sl_is_blocked_up(int action, int p_y, int o_y)
{
	return (action == MOVE_UP && p_y - SPRITE_SIZE == o_y);
}

int	sl_is_blocked_down(int action, int p_y, int o_y)
{
	return (action == MOVE_DOWN && p_y + SPRITE_SIZE == o_y);
}
