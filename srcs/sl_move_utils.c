/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_move_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 13:27:21 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/10/12 04:05:19 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	sl_move_player_step(t_game *g)
{
	t_player	*p;

	p = g->player;
	if (p)
	{
		if (p->action == MOVE_LEFT 
			&& !sl_is_wall(g->map, p->x - STEP_SIZE, p->y + SPRITE_SIZE / 2))
			p->x -= STEP_SIZE;
		else if (p->action == MOVE_RIGHT
			&& !sl_is_wall(g->map, p->x + SPRITE_SIZE, p->y + SPRITE_SIZE / 2))
			p->x += STEP_SIZE;
		else if (p->action == MOVE_UP
			&& !sl_is_wall(g->map, p->x + SPRITE_SIZE / 2, p->y - STEP_SIZE))
			p->y -= STEP_SIZE;
		else if (p->action == MOVE_DOWN
			&& !sl_is_wall(g->map, p->x + SPRITE_SIZE / 2, p->y + SPRITE_SIZE))
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
