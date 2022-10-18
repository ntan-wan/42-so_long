/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_move_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 13:27:21 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/10/18 19:40:30 by ntan-wan         ###   ########.fr       */
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

void	sl_move_enemy_step(t_game *g)
{
	t_enemy	*e;
	t_list	*enemies;

	enemies = g->enemies;
	if (!enemies)
		sl_exit_free_msg(g, "enemy_step: enemy not found\n", EXIT_FAILURE);
	while (enemies)
	{
		e = (t_enemy *)enemies->content;
		if (e->dir == IDLE_LEFT
			&& !sl_is_wall(g->map, e->x - STEP_SIZE, e->y + SPRITE_SIZE / 2))
			e->x -= STEP_SIZE;
		else if (e->dir == IDLE_RIGHT
			&& !sl_is_wall(g->map, e->x + SPRITE_SIZE, e->y + SPRITE_SIZE / 2))
			e->x += STEP_SIZE;
		else
			e->dir = !e->dir;
		enemies = enemies->next;
	}
}

int	sl_move_is_blocked(t_game *g)
{
	t_list	*chest;

	chest = g->chests;
	if (sl_is_blocked_by_door(g->player, g->door, chest))
		return (1);
	while (chest)
	{
		if (sl_is_blocked_by_chest(g->player, (t_chest*)chest->content))
			return (1);
		chest = chest->next;
	}
	return (0);
}
