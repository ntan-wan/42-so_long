/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_check_blocked_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 09:26:03 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/10/19 11:09:36 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/* 
	o_x = other object's x coordinate.
	o_y = other object's y coordinate.
 */
int	sl_is_blocked(t_player *p, int o_x, int o_y)
{
	int		act;
	int		reduced_range;

	act = p->action;
	reduced_range = 4;
	if (act == MOVE_RIGHT && sl_is_blocked_right(p->x, o_x)
		&& sl_is_blocked_range(p->y, o_y, reduced_range))
		return (1);
	else if (act == MOVE_LEFT && sl_is_blocked_left(p->x, o_x)
		&& sl_is_blocked_range(p->y, o_y, reduced_range))
		return (1);
	else if (act == MOVE_UP && sl_is_blocked_up(p->y, o_y)
		&& sl_is_blocked_range(p->x, o_x, reduced_range))
		return (1);
	else if (act == MOVE_DOWN && sl_is_blocked_down(p->y, o_y)
		&& sl_is_blocked_range(p->x, o_x, reduced_range))
		return (1);
	return (0);
}

int	sl_is_blocked_by_chest(t_player *p, t_chest *c)
{
	return (sl_is_blocked(p, c->x, c->y) && !c->interacted);
}

int	sl_is_blocked_by_door(t_player *p, t_door *d, t_list *c)
{
	int	chest_total;

	chest_total = ft_lstsize(c);
	return (sl_is_blocked(p, d->x, d->y) && p->collected != chest_total);
}

int	sl_is_wall(t_map *map, int x, int y)
{
	int		i;
	t_list	*data;

	i = -1;
	data = map->data;
	while (++i < y / SPRITE_SIZE)
		data = data->next;
	return (((char *)data->content)[x / SPRITE_SIZE] == '1');
}
