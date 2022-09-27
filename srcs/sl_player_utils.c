/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_player_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 08:48:45 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/09/27 11:00:50 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	sl_player_load_imgs(void *mlx, t_player *player)
{
	sl_img_load(mlx, &player->idle, "idle0", "sprite/knight/idle_0.xpm");
	sl_img_load(mlx, &player->idle, "idle1", "sprite/knight/idle_1.xpm");
	sl_img_load(mlx, &player->idle, "idle2", "sprite/knight/idle_2.xpm");
	sl_img_load(mlx, &player->idle, "idle3", "sprite/knight/idle_3.xpm");
	sl_img_load(mlx, &player->idle, "idle4", "sprite/knight/idle_4.xpm");
	sl_img_load(mlx, &player->idle, "idle5", "sprite/knight/idle_5.xpm");
	sl_img_load(mlx, &player->idle, "idle6", "sprite/knight/idle_6.xpm");
	sl_img_load(mlx, &player->idle, "idle7", "sprite/knight/idle_7.xpm");
	sl_img_load(mlx, &player->idle, "idle8", "sprite/knight/idle_8.xpm");
	sl_img_load(mlx, &player->idle, "idle9", "sprite/knight/idle_9.xpm");
}

void	sl_player_init(void *mlx, t_player *player)
{
	player->idle = NULL;
	sl_player_load_imgs(mlx, player);
}
