/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 08:59:39 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/10/17 20:59:45 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	sl_key_press(int keycode, t_game *game)
{
	if (keycode == ESC)
		sl_exit_free_msg(game, "exit success\n", EXIT_SUCCESS);
	else if (keycode == SPACE_BAR)
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

int	sl_render(t_game *g)
{
	t_img	*buffer;

	buffer = sl_img_new(g->mlx, WINDOW_W, WINDOW_H);
	if (!sl_move_is_blocked(g))
		sl_move_player_step(g);
	sl_move_enemy_step(g);
	sl_player_set_dir(g->player);
	sl_item_check_collected(g);
	sl_player_check_collected(g);
	sl_map_copy_img(buffer, g);
	sl_item_copy_img(buffer, g);
	sl_door_copy_img(buffer, g);
	sl_enemy_copy_img(buffer, g);
	sl_player_copy_img(buffer, g->player);
	mlx_put_image_to_window(g->mlx, g->win, buffer->img, 0, 0);
	mlx_destroy_image(g->mlx, buffer->img);
	free(buffer);
	return (0);
}

int	main(int ac, char **av)
{
	t_game	game;

	sl_game_init_all(&game);
	sl_map_setup(&game, av[1]);
	sl_game_load_imgs(&game);
	sl_game_load_anims(&game);
	sl_map_parse_data(&game, sl_map_parse_image);
	mlx_hook(game.win, ON_DESTROY, 0, sl_exit_free, &game);
	mlx_hook(game.win, ON_KEY_PRESS, 1L << 0, sl_key_press, &game);
	mlx_hook(game.win, ON_KEY_RELEASE, 1L << 1, sl_key_release, &game);
	mlx_loop_hook(game.mlx, sl_render, &game);
	mlx_loop(game.mlx);
	return (0);
}
