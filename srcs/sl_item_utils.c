/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_item_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 21:31:20 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/10/03 21:23:01 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	sl_item_chest_init(t_chest **chest)
{
	t_chest	*new_chest;

	new_chest = (t_chest *)malloc(sizeof(t_chest));
	if (new_chest)
	{
		new_chest->coords = NULL;
		new_chest->close = sl_anim_init();
		new_chest->open = sl_anim_init();
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

void	sl_item_chest_set_coord(t_chest *chest, int x, int y)
{
	int	*arr;

	if (chest)
	{
		arr = (int *)malloc(2 * sizeof(int));
		arr[0] = x;
		arr[1] = y;
		ft_lstadd_back(&chest->coords, ft_lstnew(arr));
	}
	else
		ft_printf("item_chest: chest not found\n");
}

void	sl_item_chest_copy_img(t_img *buffer, t_chest *chest, int x, int y)
{
	sl_copy_img(buffer, sl_item_chest_get_anim(chest), x, y);
}

/* 
	p_x = player's x coordinate.
	p_y = player's y coordinate.
	Copy the chest's image according to the player's coordinate.
 */
void	sl_item_chest_copy_all(t_img *buffer, t_chest *chest, int p_x, int p_y)
{
	t_list	*coords;

	coords = chest->coords;
	while (coords)
	{
		sl_item_chest_copy_img(buffer, chest,
			((int *)coords->content)[0] + (WINDOW_W / 2 - SPRITE_SIZE - p_x),
			((int *)coords->content)[1] + (WINDOW_W / 2 - SPRITE_SIZE - p_y));
		//
		//printf("x -> %d\n", ((int *)coords->content)[0] + (WINDOW_W / 2 - SPRITE_SIZE - p_x));
		//printf("y -> %d\n", ((int *)coords->content)[1] + (WINDOW_W / 2 - SPRITE_SIZE - p_y));
		coords = coords->next;
	}
}
