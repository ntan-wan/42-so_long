/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_player_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 08:48:45 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/09/30 16:54:43 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	sl_player_init(void *mlx, t_player **player, t_img **imgs)
{
	t_player	*new_player;

	new_player = (t_player *)malloc(sizeof(t_player));
	if (new_player)
	{
		new_player->action = 0;
		new_player->idle_left = sl_anim_init();
		new_player->idle_right = sl_anim_init();
		new_player->move_left = sl_anim_init();
		new_player->move_right = sl_anim_init();
		sl_player_load_imgs_idle(mlx, imgs);
		sl_player_load_imgs_move(mlx, imgs);
		sl_player_load_anim_idle(new_player, *imgs);
		sl_player_load_anim_move(new_player, *imgs);
	}
	else
		ft_putstr_fd("player_init: init failed\n", 1);
	*player = new_player;
}

t_img	*sl_player_get_anim(t_player *player)
{
	static unsigned int timer;
	static unsigned int frame;

	frame = timer++ / INTERVAL;
	if (player->action == IDLE_RIGHT)
		return (sl_anim_get_frame(player->idle_right,
				frame % player->idle_right->frame_count));
	else if (player->action == MOVE_RIGHT)
		return (sl_anim_get_frame(player->move_right,
				frame % player->move_right->frame_count));
	else if (player->action == MOVE_LEFT)
		return (sl_anim_get_frame(player->move_left,
				frame % player->move_left->frame_count));
	else if (player->action == IDLE_LEFT)
		return (sl_anim_get_frame(player->idle_left,
				frame % player->idle_left->frame_count));
}
