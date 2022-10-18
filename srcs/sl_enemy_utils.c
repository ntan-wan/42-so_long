/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_enemy_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 15:21:57 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/10/17 19:32:09 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	sl_enemy_init(t_enemy **e)
{
	t_enemy *new_enemy;

	new_enemy = (t_enemy *)malloc(sizeof(t_enemy));
	if (new_enemy)
	{
		new_enemy->x = 0;
		new_enemy->y = 0;
		new_enemy->dir = 0;
		new_enemy->action = 0;
		new_enemy->idle_left = sl_anim_init();
		new_enemy->idle_right = sl_anim_init();
		new_enemy->move_left = sl_anim_init();
		new_enemy->move_right = sl_anim_init();
	}
	else
		ft_printf("enemy_init: init failed\n");
	*e = new_enemy;
}

void	sl_enemy_set_coord(t_enemy *e, int x, int y)
{
	if (e)	
	{
		e->x = x;	
		e->y = y;
	}
	else
		ft_printf("enemy:set_coord: enemy not found\n");
}

t_img	*sl_enemy_get_anim(t_enemy *e)
{
	t_anim				*anim;
	static unsigned int	timer;
	static unsigned int	frame;

	frame = timer++ / PLAYER_ANIM_SPEED;
	if (e->action == IDLE_RIGHT)
		anim = e->idle_right;
	else if (e->action == IDLE_LEFT)
		anim = e->idle_left;
	else if (e->action == MOVE_RIGHT)
		anim = e->move_right;
	else if (e->action == MOVE_LEFT)
		anim = e->move_left;
	else if (e->dir == IDLE_RIGHT)
		anim = e->move_right;
	else if (e->dir == IDLE_LEFT)
		anim = e->move_left;
	return (sl_anim_get_frame(anim, frame % anim->frame_count));
}


void	sl_enemy_set_dir(t_enemy *e)
{
	if (e)
	{
		if (e->action == IDLE_LEFT)
			e->dir = IDLE_LEFT;
		else if (e->action == IDLE_RIGHT)
			e->dir = IDLE_RIGHT;
	}
	else
		ft_printf("set_move_direction: enemy not found\n");
}

void	sl_enemy_copy_img(t_img *buffer, t_game *g)
{
	sl_copy_img(buffer, sl_enemy_get_anim(g->enemy),
		g->enemy->x + ((WINDOW_W - SPRITE_SIZE) / 2 - g->player->x),
		g->enemy->y + ((WINDOW_H - SPRITE_SIZE) / 2 - g->player->y));
}