/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 08:59:39 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/09/30 15:15:04 by ntan-wan         ###   ########.fr       */
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
	if (keycode == KEY_D)
		game->player->movement = RIGHT;
	else if (keycode == KEY_A)
		game->player->movement = LEFT;
	return (0);
}

int	sl_key_release(int keycode, t_game *game)
{
	if (keycode == KEY_D)
		game->player->movement = IDLE_RIGHT;
	else if (keycode == KEY_A)
		game->player->movement = IDLE_LEFT;
	return (0);
}

int	sl_render(t_game *game)
{
	t_img	buffer;

	buffer.img = mlx_new_image(game->mlx, WINDOW_W, WINDOW_H);
	sl_copy_player_img(&buffer, game->player);
	mlx_put_image_to_window(game->mlx, game->win, buffer.img, 0, 0);
	mlx_destroy_image(game->mlx, buffer.img);
	return (0);
}

int	main(int ac, char **av)
{
	t_game	game;

	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, WINDOW_W, WINDOW_H, "so_long");
	sl_player_init(game.mlx, &game.player, &game.imgs);
	mlx_hook(game.win, ON_DESTROY, 0, sl_close, &game);
	mlx_hook(game.win, ON_KEY_PRESS, KEY_PRESS_MASK, sl_key_press, &game);
	mlx_hook(game.win, ON_KEY_RELEASE, KEY_RELEASE_MASK, sl_key_release, &game);
	mlx_loop_hook(game.mlx, sl_render, &game);
	mlx_loop(game.mlx);
	return (0);
}
