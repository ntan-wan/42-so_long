/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 18:45:59 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/09/27 11:08:36 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	sl_close(t_game *game)
{
	sl_free_content(game);
	exit(EXIT_SUCCESS);
}

int	sl_key_hook(int keycode, t_game *game)
{
	if (keycode == ESC)
		sl_close(game);
	return (0);
}

int	sl_render(t_game *game)
{
	t_img	*buffer;
	
	//sl_copy_img(buffer->img, game->player->idle->frame);
	//mlx_put_image_to_window(game->mlx, game->win, buffer->img, 0, 0);
	mlx_put_image_to_window(game->mlx, game->win, game->player->idle->img, 0, 0);
}

int	main(int ac, char **av)
{
	t_game	game;

	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, SCREEN_W, SCREEN_H, "so_long");
	sl_player_init(game.mlx, game.player);
	mlx_hook(game.win, ON_DESTROY, 0, sl_close, &game);
	mlx_key_hook(game.win, sl_key_hook, &game);
	mlx_loop_hook(game.mlx, sl_render, &game);
	mlx_loop(game.mlx);
	return (0);
}
