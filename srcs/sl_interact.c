/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_interact.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 22:40:06 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/10/04 19:16:59 by ntan-wan         ###   ########.fr       */
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

/* 
	p_x = player's x coordinate.
	p_y = player's y coordinate.
	x = other object's x coordinate.
	y = other object's y coordinate.
 */
int	sl_check_in_range(int p_x, int p_y, int x, int y)
{
	int	center_x;
	int	center_y;
	int	*center_coord;
	int	is_in_range;

	//printf("%d\n", p_x);
	//printf("%d\n", p_y);
	center_coord = sl_get_center_coord(p_x, p_y);
	center_x = center_coord[0];
	center_y = center_coord[1];
	free(center_coord);
	//printf("x -> %d\n", center_x);
	//printf("y -> %d\n", center_y);
	//  printf("%d\n", center_y <= y + SPRITE_SIZE && center_y >= y);
	return (center_y >= y && center_y <= y + SPRITE_SIZE);
}

/*int	sl_check(int p_x, int p_y, int o_x, int o_y)
{
	int	*p_img_center_coord;
	int	*o_img_center_coord;

	p_img_center_coord = sl_get_center_coord(p_x, p_y);
	o_img_center_coord = sl_get_center_coord(o_x, o_y);
	if (p_img_center_coord[1] >= o_img_center_coord[1] - SPRITE_SIZE / 2 && )
}*/

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
