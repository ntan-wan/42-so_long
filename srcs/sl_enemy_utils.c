/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_enemy_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 15:21:57 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/10/18 17:17:37 by ntan-wan         ###   ########.fr       */
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

void	sl_enemy_add(t_list **enemies, t_list *new)
{
	ft_lstadd_back(enemies, new);
}

void	sl_enemy_copy_img(t_img *buffer, t_game *g)
{
	t_enemy	*enemy;
	t_list	*enemies;

	enemies = g->enemies;
	while (enemies)
	{
		enemy = ((t_enemy *)enemies->content);
		sl_copy_img(buffer, sl_enemy_get_anim(enemy),
			enemy->x + ((WINDOW_W - SPRITE_SIZE) / 2 - g->player->x),
			enemy->y + ((WINDOW_H - SPRITE_SIZE) / 2 - g->player->y));
		enemies = enemies->next;
	}
}

void	sl_enemies_check_player(t_game *g)
{
	t_enemy	*enemy;
	t_list	*enemies;
	int		reduced_range;
	int		non_blocked_range;

	enemies = g->enemies;
	reduced_range = 28;
	non_blocked_range = 16;
	while (enemies)
	{
		enemy = ((t_enemy *)enemies->content);
		if (sl_is_blocked_right(g->player->x - reduced_range, enemy->x)
			&& sl_is_blocked_range(g->player->y, enemy->y, non_blocked_range))
			sl_exit_free_msg(g, "YOU'VE BEEN CAPTURED!\n", EXIT_SUCCESS);
		else if (sl_is_blocked_left(g->player->x + reduced_range, enemy->x)
			&& sl_is_blocked_range(g->player->y, enemy->y, non_blocked_range))
			sl_exit_free_msg(g, "YOU'VE BEEN CAPTURED!\n", EXIT_SUCCESS);
		enemies = enemies->next;
	}
}
