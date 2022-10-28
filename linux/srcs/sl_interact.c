/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_interact.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 22:40:06 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/10/18 19:56:33 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	sl_interact_chest(t_player *p, t_list *c)
{
	t_chest	*chest;
	t_list	*chests;

	chests = c;
	while (chests)
	{
		chest = (t_chest *)chests->content;
		if (sl_is_blocked_by_chest(p, chest))
		{
			chest->interacted = 1;
			return ;
		}
		chests = chests->next;
	}
}

void	sl_interact(t_game *g)
{
	sl_interact_chest(g->player, g->chests);
}
