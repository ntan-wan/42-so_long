/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_move_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 13:27:21 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/10/07 09:28:08 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	sl_move_player_step(t_player *p)
{
	if (p)
	{
		if (p->action == MOVE_LEFT)
			p->x -= STEP_SIZE;
		else if (p->action == MOVE_RIGHT)
			p->x += STEP_SIZE;
		else if (p->action == MOVE_UP)
			p->y -= STEP_SIZE;
		else if (p->action == MOVE_DOWN)
			p->y += STEP_SIZE;
	}
	else
		ft_printf("move_player_step: player not found\n");
}

int	sl_move_is_blocked(t_game *g)
{
	t_chest	*chest;

	if (sl_is_blocked_by_door(g->player, g->door))
		return (1);
	chest = g->chest;
	while (chest)
	{
		if (sl_is_blocked_by_chest(g->player, chest))
			return (1);
		chest = chest->next;
	}
	return (0);
}
