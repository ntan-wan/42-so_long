/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_game_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 10:08:26 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/10/04 11:17:42 by ntan-wan         ###   ########.fr       */
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
	sl_item_load_imgs_chest_open(game->mlx, &game->imgs);
	sl_item_load_imgs_chest_close(game->mlx, &game->imgs);
}

void	sl_game_load_anims(t_game *game)
{
	sl_player_load_anim_idle(game->player, game->imgs);
	sl_player_load_anim_move(game->player, game->imgs);
	sl_load_anim_chest(game->imgs, game->chest);
}
