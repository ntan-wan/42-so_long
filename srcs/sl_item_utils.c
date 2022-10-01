/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_item_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 21:31:20 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/10/01 21:23:18 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	sl_item_chest_init(t_chest **chest)
{
	t_chest	*new_chest;

	new_chest = (t_chest *)malloc(sizeof(t_chest));
	if (new_chest)
	{
		new_chest->close = sl_anim_init();
		new_chest->open = sl_anim_init();
		new_chest->coords = NULL;
	}
	*chest = new_chest;
}

t_img	*sl_item_chest_get_anim(t_chest *chest)
{
	t_anim				*anim;
	static unsigned int	timer;
	static unsigned int	frame;

	frame = timer++ / INTERVAL;
	anim = chest->close;
	return (sl_anim_get_frame(anim, frame % anim->frame_count));
}

void	sl_item_chest_copy_img(t_img *buffer, t_chest *chest)
{
	sl_copy_img(buffer, sl_item_chest_get_anim(chest), 0, 0);
}
