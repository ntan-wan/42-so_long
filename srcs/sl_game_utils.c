/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_game_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 10:08:26 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/10/07 09:08:34 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	sl_game_init(t_game *game)
{
	if (game)
	{
		game->mlx = mlx_init();
		game->win = mlx_new_window(game->mlx, WINDOW_W, WINDOW_H, "so_long");
		game->imgs = NULL;
		game->chest = NULL;
		game->player = NULL;
	}
	else
		sl_exit(game, "game_init\n", EXIT_FAILURE);
}

void	sl_game_buffer_init(void *mlx, t_img *buffer)
{
	buffer->key = "buffer";
	buffer->img = mlx_new_image(mlx, WINDOW_W, WINDOW_H);
	buffer->width = WINDOW_W;
	buffer->height = WINDOW_H;
	buffer->next = NULL;
}

void	sl_game_load_imgs(t_game *game)
{
	sl_player_load_imgs_idle(game->mlx, &game->imgs);
	sl_player_load_imgs_move(game->mlx, &game->imgs);
	sl_item_load_imgs_chest_idle(game->mlx, &game->imgs);
	sl_item_load_imgs_chest_shine(game->mlx, &game->imgs);
	sl_door_load_imgs_opening(game->mlx, &game->imgs);
	sl_door_load_imgs_opened(game->mlx, &game->imgs);
	sl_door_load_imgs_closed(game->mlx, &game->imgs);
}

void	sl_game_load_anims(t_game *game)
{
	sl_player_load_anim_idle(game->player, game->imgs);
	sl_player_load_anim_move(game->player, game->imgs);
	sl_item_load_anim_chests(game->chest, game->imgs);
	sl_door_load_anim_opening(game->door, game->imgs);
	sl_door_load_anim_opened(game->door, game->imgs);
	sl_door_load_anim_closed(game->door, game->imgs);
}
