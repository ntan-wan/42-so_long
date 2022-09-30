/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 08:59:39 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/09/29 21:55:37 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	sl_close(t_game *game)
{
	sl_free_content(game);
	sl_exit("exit success\n", EXIT_SUCCESS);
}

int	sl_key_hook(int keycode, t_game *game)
{
	if (keycode == ESC)
		sl_close(game);
	if (keycode == KEY_D)
		game->player->movement = RIGHT;
	return (0);
}

int	sl_render(t_game *game)
{
	t_img	buffer;

	buffer.img = mlx_new_image(game->mlx, SCREEN_W, SCREEN_H);
	sl_player_get_anim(&buffer, game->player);
	mlx_put_image_to_window(game->mlx, game->win, buffer.img, 0, 0);
	mlx_destroy_image(game->mlx, buffer.img);
	return (0);
}

int	main(int ac, char **av)
{
	t_game	game;

	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, SCREEN_W, SCREEN_H, "so_long");
	sl_player_init(game.mlx, &game.player, &game.imgs);
	mlx_hook(game.win, ON_DESTROY, 0, sl_close, &game);
	mlx_key_hook(game.win, sl_key_hook, &game);
	mlx_loop_hook(game.mlx, sl_render, &game);
	mlx_loop(game.mlx);
	return (0);
}
