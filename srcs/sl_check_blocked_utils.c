/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_check_blocked_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 09:26:03 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/10/05 16:45:32 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	sl_is_blocked_by_chest(t_player *p, t_chest *c)
{
	int		act;

	act = p->action;
	while (c)
	{
		if (sl_is_blocked_right(act, p->x, c->x)
			&& sl_is_blocked_range(p->y, c->y))
			return (1);
		else if (sl_is_blocked_left(act, p->x, c->x)
			&& sl_is_blocked_range(p->y, c->y))
			return (1);
		else if (sl_is_blocked_up(act, p->y, c->y)
			&& sl_is_blocked_range(p->x, c->x))
			return (1);
		else if (sl_is_blocked_down(act, p->y, c->y)
			&& sl_is_blocked_range(p->x, c->x))
			return (1);
		c = c->next;
	}
	return (0);
}
