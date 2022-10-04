/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_move_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 13:27:21 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/10/04 16:04:18 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	get_center(int coord)
{
	return (coord + (SPRITE_SIZE / 2));
}

int	sl_move_is_blocked(t_game *game)
{
	int		chest_x;
	int		chest_y;
	int		center_x;
	int		center_y;
	t_chest	*ptr_chest;

	ptr_chest = game->chest;
	//printf("%d\n", game->player->action);
	//printf("p.y -> %d\n", game->player->y);
	while (ptr_chest)
	{
		chest_x = ptr_chest->x;
		chest_y = ptr_chest->y;
		center_x = get_center(game->player->x);
		center_y = get_center(game->player->y);
		//printf("c.y -> %d\n", center_y);
		if (game->player->action == MOVE_RIGHT && game->player->x + SPRITE_SIZE == chest_x && center_y <= chest_y + SPRITE_SIZE && center_y >= chest_y)
			return (1);
		ptr_chest = ptr_chest->next;
	}
	return (0);
}

void	sl_move_player_step(t_game *game, t_player *p)
{
	if (p)
	{
		if (p->action == MOVE_LEFT)
			p->x -= STEP_SIZE;
		else if (p->action == MOVE_RIGHT && !sl_move_is_blocked(game))
			p->x += STEP_SIZE;
		else if (p->action == MOVE_UP)
			p->y -= STEP_SIZE;
		else if (p->action == MOVE_DOWN)
			p->y += STEP_SIZE;
	}
	else
		ft_printf("move_player_step: player not found\n");
}

/*void	sl_move(t_game *game)
{
	if (!sl_move_is_blocked(game))
		sl_move_player_step(game->player);
}*/