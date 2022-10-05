/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_player_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 08:48:45 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/10/05 18:34:03 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	sl_player_init(t_player **player)
{
	t_player	*new_player;

	new_player = (t_player *)malloc(sizeof(t_player));
	if (new_player)
	{
		new_player->x = 0;
		new_player->y = 0;
		new_player->dir = 0;
		new_player->action = 0;
		new_player->idle_left = sl_anim_init();
		new_player->idle_right = sl_anim_init();
		new_player->move_left = sl_anim_init();
		new_player->move_right = sl_anim_init();
	}
	else
		ft_printf("player_init: init failed\n");
	*player = new_player;
}

t_img	*sl_player_get_anim(t_player *player)
{
	t_anim				*anim;
	static unsigned int	timer;
	static unsigned int	frame;

	frame = timer++ / PLAYER_ANIM_SPEED;
	if (player->action == IDLE_RIGHT)
		anim = player->idle_right;
	else if (player->action == IDLE_LEFT)
		anim = player->idle_left;
	else if (player->action == MOVE_RIGHT)
		anim = player->move_right;
	else if (player->action == MOVE_LEFT)
		anim = player->move_left;
	else if (player->action == MOVE_DOWN && player->dir == IDLE_RIGHT)
		anim = player->move_right;
	else if (player->action == MOVE_DOWN && player->dir == IDLE_LEFT)
		anim = player->move_left;
	else if (player->action == MOVE_UP && player->dir == IDLE_RIGHT)
		anim = player->move_right;
	else if (player->action == MOVE_UP && player->dir == IDLE_LEFT)
		anim = player->move_left;
	return (sl_anim_get_frame(anim, frame % anim->frame_count));
}

void	sl_player_set_coord(t_player *player, int x, int y)
{
	if (player)
	{
		player->x = x;
		player->y = y;
	}
	else
		ft_printf("player_set_coord: player not found\n");
}

/* 
	Set player's facing direction.
 */
void	sl_player_set_dir(t_player *player)
{
	if (player)
	{
		if (player->action == IDLE_LEFT)
			player->dir = IDLE_LEFT;
		else if (player->action == IDLE_RIGHT)
			player->dir = IDLE_RIGHT;
	}
	else
		ft_printf("set_move_direction: player not found\n");
}

void	sl_player_copy_img(t_img *buffer, t_player *player)
{
	sl_copy_img(buffer, sl_player_get_anim(player), WINDOW_W / 2 - SPRITE_SIZE, WINDOW_H / 2 - SPRITE_SIZE);
}
