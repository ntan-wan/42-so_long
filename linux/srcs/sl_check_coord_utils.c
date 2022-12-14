/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_check_coord_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 19:01:45 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/10/12 02:58:22 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	sl_coord_get_upper_limit(int o_coord, int reduced_range)
{
	return (o_coord + SPRITE_SIZE - reduced_range);
}

static int	sl_coord_get_lower_limit(int o_coord, int reduced_range)
{
	return (o_coord + reduced_range);
}

int	sl_coord_is_overlapped(int p_coord, int o_coord, int reduced_range)
{
	return (p_coord >= sl_coord_get_lower_limit(o_coord, reduced_range)
		&& p_coord <= sl_coord_get_upper_limit(o_coord, reduced_range));
}
