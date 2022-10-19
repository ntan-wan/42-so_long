/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_door.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 08:28:15 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/10/19 12:51:04 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	sl_door_init(t_door **door)
{
	t_door	*new_door;

	new_door = (t_door *)malloc(sizeof(t_door));
	if (new_door)
	{
		new_door->x = 0;
		new_door->y = 0;
		new_door->open = sl_anim_init();
		new_door->opened = sl_anim_init();
		new_door->closed = sl_anim_init();
	}
	else
		ft_printf("door_init: init failed\n");
	*door = new_door;
}

void	sl_door_set_coord(t_door *door, int x, int y)
{
	if (door)
	{
		door->x = x;
		door->y = y;
	}
	else
		ft_printf("door_set_coord: door not found\n");
}

t_img	*sl_door_get_anim(t_game *g)
{
	char				*key;
	t_anim				*anim;
	static unsigned int	timer;
	static unsigned int	frame;
	int					opened;

	opened = 0;
	frame = timer / DOOR_ANIM_SPEED;
	key = sl_img_get_key(frame % g->door->open->frame_count, g->door->open);
	if (sl_anim_is_last_frame(key, g->door->open) || opened)
	{
		anim = g->door->opened;
		opened = 1;
	}
	else if (g->player->collected == ft_lstsize(g->chests))
	{
		timer++;
		anim = g->door->open;
	}
	else
		anim = g->door->closed;
	return (sl_anim_get_frame(anim, frame % anim->frame_count));
}

void	sl_door_copy_img(t_img *buffer, t_game *g)
{
	sl_copy_img(buffer, sl_door_get_anim(g),
		g->door->x + ((WINDOW_W - SPRITE_SIZE) / 2 - g->player->x),
		g->door->y + ((WINDOW_H - SPRITE_SIZE) / 2 - g->player->y));
}

void	sl_door_exit(t_game *g)
{
	int		exit;
	int		reduced_contact;
	int		reduced_range;

	exit = 0;
	reduced_contact = 28;
	reduced_range = 16;
	if (sl_is_blocked_right(g->player->x - reduced_contact, g->door->x)
		&& sl_is_blocked_range(g->player->y, g->door->y, reduced_range))
		exit = 1;
	else if (sl_is_blocked_left(g->player->x + reduced_contact, g->door->x)
		&& sl_is_blocked_range(g->player->y, g->door->y, reduced_range))
		exit = 1;
	else if (sl_is_blocked_up(g->player->y + reduced_contact, g->door->y)
		&& sl_is_blocked_range(g->player->x, g->door->x, reduced_range))
		exit = 1;
	else if (sl_is_blocked_down(g->player->y - reduced_contact, g->door->y)
		&& sl_is_blocked_range(g->player->x, g->door->x, reduced_range))
		exit = 1;
	if (exit)
		sl_exit_free_msg(g, "YOU'VE SUCCESSFULLY ESCAPED!\n", EXIT_SUCCESS);
}
