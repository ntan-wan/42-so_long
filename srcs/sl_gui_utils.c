/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_gui_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 10:40:09 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/10/20 18:12:23 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#define WHITE 0xFFFFFF

void	sl_gui_display_move(t_game *g)
{
	char		*count;
	static int	prev_action;

	if (prev_action != g->player->action && g->player->action > IDLE_LEFT)
	{
		(g->player->move_count)++;
		ft_printf("move_count: %d\n", g->player->move_count);
	}
	prev_action = g->player->action;
	count = ft_itoa(g->player->move_count);
	mlx_string_put(g->mlx, g->win, SPRITE_SIZE, SPRITE_SIZE, WHITE, "move :");
	mlx_string_put(g->mlx, g->win, 2 * SPRITE_SIZE, SPRITE_SIZE, WHITE, count);
	free(count);
}
