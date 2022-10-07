/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_item_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 21:31:20 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/10/07 09:17:00 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_chest	*sl_item_chest_new(int x, int y)
{
	t_chest	*new_chest;

	new_chest = (t_chest *)malloc(sizeof(t_chest));
	if (new_chest)
	{
		new_chest->x = x;
		new_chest->y = y;
		new_chest->next = NULL;
		new_chest->interacted = 0;
		new_chest->shine = sl_anim_init();
		new_chest->open = sl_anim_init();
		new_chest->close = sl_anim_init();
	}
	return (new_chest);
}

t_chest	*sl_item_chest_get_last(t_chest *head)
{
	t_chest	*tail;

	tail = head;
	if (!tail)
		return (NULL);
	while (tail->next)
		tail = tail->next;
	return (tail);
}

void	sl_item_chest_add(t_chest **head, t_chest *new)
{
	t_chest	*tail;

	tail = sl_item_chest_get_last(*head);
	if (tail)
		tail->next = new;
	else
		*head = new;
}

int	sl_anim_get_duration(int anim_speed, int frame_count)
{
	return (anim_speed * frame_count);
}

t_img	*sl_item_chest_get_anim(t_chest *chest)
{
	t_anim				*anim;
	static unsigned int	timer;
	static unsigned int	frame;
	int					delay;
	int					duration;

	frame = timer++ / ITEM_ANIM_SPEED;
	duration = sl_anim_get_duration(ITEM_ANIM_SPEED, chest->shine->frame_count);
	delay = duration * 6;
	if (!chest->interacted && timer % delay >= 0 && timer % delay <= duration)
		anim = chest->shine;
	else if (chest->interacted)
		anim = chest->open;
	else
		anim = chest->close;
	return (sl_anim_get_frame(anim, frame % anim->frame_count));
}

/* 
	p_x = player's x coordinate.
	p_y = player's y coordinate.
	Copy the chest's image according to the player's coordinate.
 */
void	sl_item_copy_img(t_img *buffer, t_chest *head, int p_x, int p_y)
{
	t_chest	*chest;

	chest = head;
	while (chest)
	{
		sl_copy_img(buffer, sl_item_chest_get_anim(chest),
			chest->x + (WINDOW_W / 2 - SPRITE_SIZE - p_x),
			chest->y + (WINDOW_H / 2 - SPRITE_SIZE - p_y));
		chest = chest->next;
	}
}
