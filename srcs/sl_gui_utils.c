/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_gui_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 10:40:09 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/10/21 13:44:01 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#define WHITE 0xFFFFFF
#define RESET 0
#define MOVING 2

void	sl_gui_display_move(t_game *g)
{
	char		*count;
	int			curr_count_x;	
	int			curr_count_y;
	static int	prev_count_x;
	static int	prev_count_y;
	
	curr_count_x = (g->player->x + (SPRITE_SIZE / 2)) % SPRITE_SIZE;
	curr_count_y = (g->player->y + (SPRITE_SIZE / 2)) % SPRITE_SIZE;
	if (curr_count_x == 0 && curr_count_x != prev_count_x)
		(g->player->move_count)++;
	if (curr_count_y == 0 && curr_count_y != prev_count_y)
		(g->player->move_count)++;
	prev_count_x = curr_count_x;
	prev_count_y = curr_count_y;
	count = ft_itoa(g->player->move_count);
	mlx_string_put(g->mlx, g->win, SPRITE_SIZE, SPRITE_SIZE, WHITE, "moves :");
	mlx_string_put(g->mlx, g->win, 2 * SPRITE_SIZE, SPRITE_SIZE, WHITE, count);
	free(count);
}
