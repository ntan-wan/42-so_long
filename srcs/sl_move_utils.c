/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_move_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 13:27:21 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/10/03 14:07:55 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void    sl_move_player_step(t_player *p)
{
	if (p)
	{
		if (p->action == MOVE_LEFT && p->x > 0)
			p->x -= STEP_SIZE;
		else if (p->action == MOVE_RIGHT && p->x < WINDOW_W - SPRITE_SIZE)
			p->x += STEP_SIZE;
		else if (p->action == MOVE_UP && p->y > 0)
			p->y -= STEP_SIZE;
		else if (p->action == MOVE_DOWN && p->y < WINDOW_H - SPRITE_SIZE)
			p->y += STEP_SIZE;
	}
	else
		ft_printf("move_player_step: player not found\n");
}