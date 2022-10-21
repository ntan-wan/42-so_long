/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_gui_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 10:40:09 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/10/21 13:10:53 by ntan-wan         ###   ########.fr       */
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
	
	curr_count_x = g->player->x % SPRITE_SIZE;
	curr_count_y = g->player->y % SPRITE_SIZE;
	if (curr_count_x == 0 && curr_count_x != prev_count_x)
		(g->player->move_count)++;
	if (curr_count_y == 0 && curr_count_y != prev_count_y)
		(g->player->move_count)++;
	prev_count_x = curr_count_x;
	prev_count_y = curr_count_y;
	// static int	step_size;
	// static int	prev_x;
	// static int	prev_y;
	// int			curr_count_y;
	// static int	prev_count;
	// static int prev_x;
	// static int	prev_count_y;

	// if (curr_count_x == 0 && g->player->move_count != prev_count)
	// if (curr_count_x == 0 && g->player->x != prev_x)
		// printf("count -> %d\n", g->player->move_count);
		// printf("prev_x -> %d\n", prev_x);
		// printf("x -> %d\n", g->player->x);
		// printf(".................\n");
	// prev_count = g->player->move_count;
	// prev_x = g->player->x;
	// if (g->player->action >= MOVING)
		// step_size += P_STEP_SIZE;
	// if (step_size >= SPRITE_SIZE)
	// {
		// step_size = RESET;
		// (g->player->move_count)++;
		// ft_printf("move_count: %d\n", g->player->move_count);
	// }

	// if (g->player->action != prev_action && g->player->action >= 2)
		// step_size = 0;
	// prev_action = g->player->action;
	// prev_x = g->player->x;
	count = ft_itoa(g->player->move_count);
	mlx_string_put(g->mlx, g->win, SPRITE_SIZE, SPRITE_SIZE, WHITE, "moves :");
	mlx_string_put(g->mlx, g->win, 2 * SPRITE_SIZE, SPRITE_SIZE, WHITE, count);
	free(count);
}
