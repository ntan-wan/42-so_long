/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_interact.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 22:40:06 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/10/04 10:31:37 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	sl_interact_chest(t_player *p, t_chest *chest)
{
	int		chest_x;
	int		chest_y;
	t_chest	*ptr_chest;

	ptr_chest = chest;
	while (ptr_chest)
	{
		chest_x = ptr_chest->x;
		chest_y = ptr_chest->y;
		if (p->x + SPRITE_SIZE == chest_x && p->y == chest_y)
		{
			ptr_chest->interacted = 1;
			return ;
		}
		ptr_chest = ptr_chest->next;
	}
}

void	sl_interact(t_game *game)
{
	sl_interact_chest(game->player, game->chest);
}
