/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_check_blocked_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 09:26:03 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/10/11 08:05:24 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/* 
	o_x = other object's x coordinate.
	o_y = other object's y coordinate.
 */
static int	sl_is_blocked(t_player *p, int o_x, int o_y)
{
	int		act;

	act = p->action;
	if (sl_is_blocked_right(act, p->x, o_x)
		&& sl_is_blocked_range(p->y, o_y))
		return (1);
	else if (sl_is_blocked_left(act, p->x, o_x)
		&& sl_is_blocked_range(p->y, o_y))
		return (1);
	else if (sl_is_blocked_up(act, p->y, o_y)
		&& sl_is_blocked_range(p->x, o_x))
		return (1);
	else if (sl_is_blocked_down(act, p->y, o_y)
		&& sl_is_blocked_range(p->x, o_x))
		return (1);
	return (0);
}

int	sl_is_blocked_by_chest(t_player *p, t_chest *c)
{
	return (sl_is_blocked(p, c->x, c->y));
}

int	sl_is_blocked_by_door(t_player *p, t_door *d)
{
	return (sl_is_blocked(p, d->x, d->y));
}

int	sl_is_blocked_by_wall(t_map *map, int x, int y)
{
	int		i;
	t_list	*data;

	i = -1;
	data = map->data;
	while (++i < y / SPRITE_SIZE)
		data = data->next;
	return (((char *)data->content)[x / SPRITE_SIZE] == '1');
}
