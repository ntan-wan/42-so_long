/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 08:59:39 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/10/04 09:40:48 by ntan-wan         ###   ########.fr       */
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
	if (keycode == KEY_E)
		sl_interact(game);
	if (keycode == ESC)
		sl_close(game);
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
	if (keycode == KEY_A)
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

	buffer.img = mlx_new_image(game->mlx, WINDOW_W, WINDOW_H);
	buffer.width = WINDOW_W;
	buffer.height = WINDOW_H;
	//
	//printf("p.x -> %d\n", game->player->x);
	//printf("p.y -> %d\n", game->player->y);
	//printf("item.x -> %d\n", ((int *)coords->content)[0]);
	//printf("item.y -> %d\n", ((int *)coords->content)[1]);
	sl_player_set_direction(game->player);
	sl_move_player_step(game->player);
	sl_player_copy_img(&buffer, game->player, WINDOW_W / 2 - SPRITE_SIZE, WINDOW_H / 2 - SPRITE_SIZE);
	sl_item_chest_copy_all(&buffer, game->chest, game->player->x, game->player->y);
	mlx_put_image_to_window(game->mlx, game->win, buffer.img, 0, 0);
	mlx_destroy_image(game->mlx, buffer.img);
	return (0);
}

int	main(int ac, char **av)
{
	t_game	game;

	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, WINDOW_W, WINDOW_H, "so_long");
	game.chest = NULL;
	sl_player_init(&game.player);
	//sl_item_chest_init(&game.chest);
	//
	sl_player_set_coord(game.player, WINDOW_W / 2 - SPRITE_SIZE, WINDOW_H / 2 - SPRITE_SIZE);
	sl_item_chest_add(&game.chest, sl_item_chest_new(64, 336));
	sl_item_chest_add(&game.chest, sl_item_chest_new(5 * 64, 336));
	//printf("%d\n", game.chest->x);
	//sl_item_chest_set_coord(game.chest, WINDOW_W - SPRITE_SIZE, WINDOW_H / 2 - SPRITE_SIZE);
	//sl_item_chest_set_coord(game.chest, WINDOW_W / 2 - SPRITE_SIZE, 0);
	//
	sl_load_imgs(&game);
	sl_load_anims(&game);
	mlx_hook(game.win, ON_DESTROY, 0, sl_close, &game);
	mlx_hook(game.win, ON_KEY_PRESS, KEY_PRESS_MASK, sl_key_press, &game);
	mlx_hook(game.win, ON_KEY_RELEASE, KEY_RELEASE_MASK, sl_key_release, &game);
	mlx_loop_hook(game.mlx, sl_render, &game);
	mlx_loop(game.mlx);
	return (0);
}
