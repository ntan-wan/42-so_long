/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_interact.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 22:40:06 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/10/04 08:12:36 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void sl_interact_chest(t_player* p, t_chest *chest)
{
	t_list	*coords;
	int		chest_x;
	int		chest_y;

	coords = chest->coords;
	while (coords)
	{
		chest_x = ((int *)coords ->content)[0];
		chest_y = ((int *)coords ->content)[1];
		if (p->x + SPRITE_SIZE == chest_x && p->y == chest_y)
		{
			chest->interacted = 1;
			return ;
		}
		coords = coords->next;
	}
}

void    sl_interact(t_game *game)
{
	sl_interact_chest(game->player, game->chest);
}