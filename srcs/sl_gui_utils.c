/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_gui_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 10:40:09 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/10/21 14:07:29 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#define WHITE 0xFFFFFF

static void	sl_update_movecount(int curr_count, int prev_count, int *move_count)
{
	if (curr_count == 0 && curr_count != prev_count)
	{
		(*move_count)++;
		ft_printf("move_count: %d\n", *move_count);
	}
}

void	sl_gui_display_movecount(t_game *g)
{
	char		*count;
	int			curr_count_x;	
	int			curr_count_y;
	static int	prev_count_x;
	static int	prev_count_y;

	curr_count_x = (g->player->x + (SPRITE_SIZE / 2)) % SPRITE_SIZE;
	curr_count_y = (g->player->y + (SPRITE_SIZE / 2)) % SPRITE_SIZE;
	sl_update_movecount(curr_count_x, prev_count_x, &g->player->move_count);
	sl_update_movecount(curr_count_y, prev_count_y, &g->player->move_count);
	prev_count_x = curr_count_x;
	prev_count_y = curr_count_y;
	count = ft_itoa(g->player->move_count);
	mlx_string_put(g->mlx, g->win, SPRITE_SIZE, SPRITE_SIZE, WHITE, "moves :");
	mlx_string_put(g->mlx, g->win, 2 * SPRITE_SIZE, SPRITE_SIZE, WHITE, count);
	free(count);
}
