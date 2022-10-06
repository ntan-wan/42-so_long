/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_interact.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 22:40:06 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/10/06 21:52:52 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	sl_interact_chest(t_player *p, t_chest *c)
{
	t_chest	*chest;

	chest = c;
	while (chest)
	{
		if (sl_is_blocked_by_chest(p, chest))
		{
			chest->interacted = 1;
			return ;
		}
		chest = chest->next;
	}
}

static void sl_interact_door(t_player *p, t_door *d)
{
	if (sl_is_blocked_by_door(p, d))
		d->interacted = 1;
}

void	sl_interact(t_game *game)
{
	sl_interact_chest(game->player, game->chest);
	sl_interact_door(game->player, game->door);
}
