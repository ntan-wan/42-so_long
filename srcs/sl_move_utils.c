/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_move_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 13:27:21 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/10/04 19:51:39 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	get_center(int coord)
{
	return (coord + (SPRITE_SIZE / 2));
}

int	sl_move_is_blocked(t_game *game)
{
	int		center_x;
	int		center_y;
	t_chest	*ptr_chest;

	ptr_chest = game->chest;
	//printf("%d\n", game->player->action);
	//printf("p.y -> %d\n", game->player->y);
	while (ptr_chest)
	{
		center_x = sl_math_get_center(game->player->x);
		center_y = sl_math_get_center(game->player->y);
		if (game->player->action == MOVE_RIGHT && game->player->x + SPRITE_SIZE == ptr_chest->x && sl_math_is_in_range(sl_math_get_center(game->player->y), ptr_chest->y))
			return (1);
		ptr_chest = ptr_chest->next;
	}
	return (0);
}

void	sl_move_player_step(t_player *p)
{
	if (p)
	{
		if (p->action == MOVE_LEFT)
			p->x -= STEP_SIZE;
		else if (p->action == MOVE_RIGHT)
			p->x += STEP_SIZE;
		else if (p->action == MOVE_UP)
			p->y -= STEP_SIZE;
		else if (p->action == MOVE_DOWN)
			p->y += STEP_SIZE;
	}
	else
		ft_printf("move_player_step: player not found\n");
}

void	sl_move(t_game *game)
{
	if (!sl_move_is_blocked(game))
		sl_move_player_step(game->player);
}