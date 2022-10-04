/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_math_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 19:19:45 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/10/04 19:35:52 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/* 
    point = x axis or y axis' value.
    Get the center coordinate of a img.
 */
int sl_math_get_center(int point)
{
	return (point + (SPRITE_SIZE / 2));
}

/* 
    center_point = center value starting point from x or y.
    coord = compare with center point to check whether is in range.
 */
int sl_math_is_in_range(int center_point, int coord)
{
	return (center_point >= coord && center_point <= coord + SPRITE_SIZE);
}