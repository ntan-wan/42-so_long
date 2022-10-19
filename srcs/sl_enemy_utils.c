/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_enemy_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 15:21:57 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/10/19 12:57:37 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_enemy	*sl_enemy_init(int x, int y)
{
	t_enemy	*new_enemy;

	new_enemy = (t_enemy *)malloc(sizeof(t_enemy));
	if (new_enemy)
	{
		new_enemy->x = x;
		new_enemy->y = y;
		new_enemy->dir = 0;
		new_enemy->action = 0;
		new_enemy->idle_left = sl_anim_init();
		new_enemy->idle_right = sl_anim_init();
		new_enemy->move_left = sl_anim_init();
		new_enemy->move_right = sl_anim_init();
	}
	else
		ft_printf("enemy_init: init failed\n");
	return (new_enemy);
}

static t_img	*sl_enemy_get_anim(t_enemy *e)
{
	t_anim				*anim;
	static unsigned int	timer;
	static unsigned int	frame;

	frame = timer++ / PLAYER_ANIM_SPEED;
	if (e->dir == IDLE_RIGHT)
		anim = e->move_right;
	else if (e->dir == IDLE_LEFT)
		anim = e->move_left;
	return (sl_anim_get_frame(anim, frame % anim->frame_count));
}

void	sl_enemy_copy_img(t_img *buffer, t_game *g)
{
	t_enemy	*enemy;
	t_list	*enemies;

	enemies = g->enemies;
	while (enemies)
	{
		enemy = (t_enemy *)enemies->content;
		sl_copy_img(buffer, sl_enemy_get_anim(enemy),
			enemy->x + ((WINDOW_W - SPRITE_SIZE) / 2 - g->player->x),
			enemy->y + ((WINDOW_H - SPRITE_SIZE) / 2 - g->player->y));
		enemies = enemies->next;
	}
}

/* 
	reduced_contact = The higher the number,
	the lesser the contact range between the enemies and
	the player.
	reduced_range = The higher the number, the lesser
	the range to be blocked by other object.
 */
void	sl_enemies_check_player(t_game *g)
{
	t_enemy	*enemy;
	t_list	*enemies;
	int		captured;

	captured = 0;
	enemies = g->enemies;
	while (enemies)
	{
		enemy = ((t_enemy *)enemies->content);
		if (sl_is_blocked_right(g->player->x - 28, enemy->x)
			&& sl_is_blocked_range(g->player->y, enemy->y, 16))
			captured = 1;
		else if (sl_is_blocked_left(g->player->x + 28, enemy->x)
			&& sl_is_blocked_range(g->player->y, enemy->y, 16))
			captured = 1;
		else if (sl_is_blocked_up(g->player->y + 28, enemy->y)
			&& sl_is_blocked_range(g->player->x, enemy->x, 16))
			captured = 1;
		else if (sl_is_blocked_down(g->player->y - 28, enemy->y)
			&& sl_is_blocked_range(g->player->x, enemy->x, 16))
			captured = 1;
		if (captured)
			sl_exit_free_msg(g, "YOU'VE BEEN CAPTURED!\n", EXIT_SUCCESS);
		enemies = enemies->next;
	}
}
