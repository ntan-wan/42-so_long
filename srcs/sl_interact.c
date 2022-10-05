/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_interact.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 22:40:06 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/10/04 21:04:39 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	*sl_get_center_coord(int x, int y)
{
	int	*arr;

	arr = (int *)malloc(2 * sizeof(int));
	if (arr)
	{
		arr[0] = x + (SPRITE_SIZE / 2);
		arr[1] = y + (SPRITE_SIZE / 2);
	}
	return (arr);
}

static void	sl_interact_chest(t_player *p, t_chest *chest)
{
	t_chest	*ptr_chest;

	ptr_chest = chest;
	while (ptr_chest)
	{
		if (p->x + SPRITE_SIZE == ptr_chest->x)
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
