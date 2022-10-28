/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_check_blocked_utils2.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 16:34:45 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/10/19 11:10:08 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/* 
	BLOCKED_RANGE = set blocked range.
 */
int	sl_is_blocked_range(int p_coord, int o_coord, int reduced_range)
{
	return (p_coord + SPRITE_SIZE >= o_coord + reduced_range
		&& p_coord <= o_coord + SPRITE_SIZE - reduced_range);
}

int	sl_is_blocked_right(int p_x, int o_x)
{
	return (p_x + SPRITE_SIZE == o_x);
}

int	sl_is_blocked_left(int p_x, int o_x)
{
	return (p_x - SPRITE_SIZE == o_x);
}

int	sl_is_blocked_up(int p_y, int o_y)
{
	return (p_y - SPRITE_SIZE == o_y);
}

int	sl_is_blocked_down(int p_y, int o_y)
{
	return (p_y + SPRITE_SIZE == o_y);
}
