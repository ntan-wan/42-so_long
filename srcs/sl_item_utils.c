/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_item_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 21:31:20 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/10/18 20:00:14 by ntan-wan         ###   ########.fr       */
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
		new_chest->collected = 0;
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

/* 
	anim_dur = animation duration per cycle.
 */
t_img	*sl_item_chest_get_anim(t_chest *chest)
{
	t_anim				*anim;
	static unsigned int	timer;
	static unsigned int	frame;
	int					delay;
	int					anim_dur;

	frame = timer++ / ITEM_ANIM_SPEED;
	anim_dur = sl_anim_get_duration(ITEM_ANIM_SPEED, chest->shine->frame_count);
	delay = anim_dur * CHEST_ANIM_DELAY;
	if (!chest->interacted && timer % delay >= 0 && timer % delay <= anim_dur)
		anim = chest->shine;
	else if (chest->interacted)
		anim = chest->open;
	else
		anim = chest->close;
	return (sl_anim_get_frame(anim, frame % anim->frame_count));
}


void	sl_item_copy_img(t_img *buffer, t_game *g)
{
	t_chest	*chest;
	t_list	*chests;

	chests = g->chests;
	while (chests)
	{
		chest = (t_chest *)chests->content;
		if (!chest->collected)
		{
			sl_copy_img(buffer, sl_item_chest_get_anim(chest),
				chest->x + ((WINDOW_W - SPRITE_SIZE) / 2 - g->player->x),
				chest->y + ((WINDOW_H - SPRITE_SIZE) / 2 - g->player->y));
		}
		chests = chests->next;
	}
}

int	sl_item_chest_get_total(t_list *chests)
{
	/*int		total;
	t_chest	*chest;
	t_list	chests;

	total = 0;
	chests = c;
	while (chests)
	{
		total++;
		chests = chest->next;
	}
	return (total);*/
	return (ft_lstsize(chests));
}

/* 
	reduced_range = reduce the area to activate
	chest->collected = 1.
 */
void	sl_item_check_collected(t_game *g)
{
	t_chest	*chest;
	t_list	*chests;
	int		p_mid_x;
	int		p_mid_y;
	int		reduced_range;

	chests = g->chests;
	reduced_range = 16;
	p_mid_y = g->player->y + SPRITE_SIZE / 2;
	p_mid_x = g->player->x + SPRITE_SIZE / 2;
	while (chests)
	{
		chest = (t_chest *)chests->content;
		if (sl_coord_is_overlapped(p_mid_x, chest->x, reduced_range)
			&& sl_coord_is_overlapped(p_mid_y, chest->y, reduced_range))
			chest->collected = 1;
		chests = chests->next;
	}
}

void	sl_chest_add(t_list **chests, t_list *new)
{
	ft_lstadd_back(chests, new);
}

t_chest	*sl_chest_init(int x, int y)
{
	t_chest	*new_chest;

	new_chest = (t_chest *)malloc(sizeof(t_chest));
	if (new_chest)
	{
		new_chest->x = x;
		new_chest->y = y;
		new_chest->next = NULL;
		new_chest->interacted = 0;
		new_chest->collected = 0;
		new_chest->shine = sl_anim_init();
		new_chest->open = sl_anim_init();
		new_chest->close = sl_anim_init();
	}
	return (new_chest);
}