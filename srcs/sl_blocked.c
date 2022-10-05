/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_blocked.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 09:26:03 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/10/05 15:09:11 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	sl_is_blocked_range(int p_coord, int o_coord)
{
	return (p_coord + SPRITE_SIZE >= o_coord && p_coord <= o_coord + SPRITE_SIZE);
}

int	sl_is_blocked_right(int action, int p_x, int o_x)
{
	return (action == MOVE_RIGHT && p_x + SPRITE_SIZE == o_x);
}

int	sl_is_blocked_left(int action, int p_x, int o_x)
{
	return (action == MOVE_LEFT && p_x - SPRITE_SIZE == o_x);
}

int	sl_is_blocked_by_chest(t_player *p, t_chest *c)
{
	t_chest	*ptr_c;

	ptr_c = c;
	while (ptr_c)
	{
		if (sl_is_blocked_right(p->action, p->x, ptr_c->x) && sl_is_blocked_range(p->y, ptr_c->y))
			printf("right blocked\n");
			return (1);
		else if (sl_is_blocked_left(p->action, p->x, ptr_c->x) && sl_is_blocked_range(p->y, ptr_c->y))
			return (1);
		ptr_c = ptr_c->next;
	}
	return (0);
}

int	sl_is_blocked(t_game *g)
{
	//printf ("%d\n", sl_is_blocked_by_chest(g->player, g->chest));
	return (sl_is_blocked_by_chest(g->player, g->chest));
}