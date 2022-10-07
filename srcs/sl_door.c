/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_door.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 08:28:15 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/10/07 09:21:44 by ntan-wan         ###   ########.fr       */
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
		new_door->interacted = 0;
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

t_img	*sl_door_get_anim(t_door *door)
{
	char				*key;
	static t_anim		*anim;
	static unsigned int	timer;
	static unsigned int	frame;

	frame = timer / DOOR_ANIM_SPEED;
	key = sl_img_get_key(frame % door->open->frame_count, door->open);
	if (door->interacted
		&& sl_is_last_frame(key, door->open) || anim == door->opened)
		anim = door->opened;
	else if (door->interacted)
	{
		timer++;
		anim = door->open;
	}
	else
		anim = door->closed;
	return (sl_anim_get_frame(anim, frame % anim->frame_count));
}

void	sl_door_copy_img(t_img *buffer, t_door *door, int p_x, int p_y)
{
	sl_copy_img(buffer, sl_door_get_anim(door),
		door->x + (WINDOW_W / 2 - SPRITE_SIZE - p_x),
		door->y + (WINDOW_H / 2 - SPRITE_SIZE - p_y));
}
