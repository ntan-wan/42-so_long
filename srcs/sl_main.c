/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 08:59:39 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/10/04 11:03:07 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	sl_close(t_game *game)
{
	sl_free_content(game);
	sl_exit("exit success\n", EXIT_SUCCESS);
}

int	sl_key_press(int keycode, t_game *game)
{
	if (keycode == ESC)
		sl_close(game);
	else if (keycode == KEY_E)
		sl_interact(game);
	else if (keycode == KEY_D)
		game->player->action = MOVE_RIGHT;
	else if (keycode == KEY_A)
		game->player->action = MOVE_LEFT;
	else if (keycode == KEY_W)
		game->player->action = MOVE_UP;
	else if (keycode == KEY_S)
		game->player->action = MOVE_DOWN;
	return (0);
}

int	sl_key_release(int keycode, t_game *game)
{
	if (keycode == KEY_D)
		game->player->action = IDLE_RIGHT;
	else if (keycode == KEY_A)
		game->player->action = IDLE_LEFT;
	else if (keycode == KEY_S && game->player->dir == IDLE_RIGHT)
		game->player->action = IDLE_RIGHT;
	else if (keycode == KEY_S && game->player->dir == IDLE_LEFT)
		game->player->action = IDLE_LEFT;
	else if (keycode == KEY_W && game->player->dir == IDLE_RIGHT)
		game->player->action = IDLE_RIGHT;
	else if (keycode == KEY_W && game->player->dir == IDLE_LEFT)
		game->player->action = IDLE_LEFT;
	return (0);
}

int	sl_render(t_game *game)
{
	t_img	buffer;

	sl_game_buffer_init(game->mlx, &buffer);
	sl_player_set_dir(game->player);
	sl_move_player_step(game->player);
	sl_player_copy_img(&buffer, game->player,
		WINDOW_W / 2 - SPRITE_SIZE, WINDOW_H / 2 - SPRITE_SIZE);
	sl_item_chest_copy_all(&buffer, game->chest,
		game->player->x, game->player->y);
	mlx_put_image_to_window(game->mlx, game->win, buffer.img, 0, 0);
	mlx_destroy_image(game->mlx, buffer.img);
	return (0);
}

int	main(int ac, char **av)
{
	t_game	game;

	sl_game_init(&game);
	sl_player_init(&game.player);
	//
	sl_player_set_coord(game.player, WINDOW_W / 2 - SPRITE_SIZE, WINDOW_H / 2 - SPRITE_SIZE);
	sl_item_chest_add(&game.chest, sl_item_chest_new(64, 336));
	sl_item_chest_add(&game.chest, sl_item_chest_new(5 * 64, 336));
	//
	sl_game_load_imgs(&game);
	sl_game_load_anims(&game);
	mlx_hook(game.win, ON_DESTROY, 0, sl_close, &game);
	mlx_hook(game.win, ON_KEY_PRESS, 1L << 0, sl_key_press, &game);
	mlx_hook(game.win, ON_KEY_RELEASE, 1L << 1, sl_key_release, &game);
	mlx_loop_hook(game.mlx, sl_render, &game);
	mlx_loop(game.mlx);
	return (0);
}
