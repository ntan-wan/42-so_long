/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 09:42:31 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/09/23 09:42:32 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	open_player_imgs(t_game *game)
{
	game->player.idle_img_0 = mlx_xpm_file_to_image(game->mlx_ptr, "sprite/knight/idle_anim/idle_0.xpm", &game->player.width, &game->player.height);
	game->player.idle_img_1 = mlx_xpm_file_to_image(game->mlx_ptr, "sprite/knight/idle_anim/idle_1.xpm", &game->player.width, &game->player.height);
	game->player.idle_img_2 = mlx_xpm_file_to_image(game->mlx_ptr, "sprite/knight/idle_anim/idle_2.xpm", &game->player.width, &game->player.height);
	game->player.idle_img_3 = mlx_xpm_file_to_image(game->mlx_ptr, "sprite/knight/idle_anim/idle_3.xpm", &game->player.width, &game->player.height);
	game->player.idle_img_4 = mlx_xpm_file_to_image(game->mlx_ptr, "sprite/knight/idle_anim/idle_4.xpm", &game->player.width, &game->player.height);
	game->player.idle_img_5 = mlx_xpm_file_to_image(game->mlx_ptr, "sprite/knight/idle_anim/idle_5.xpm", &game->player.width, &game->player.height);
	game->player.idle_img_6 = mlx_xpm_file_to_image(game->mlx_ptr, "sprite/knight/idle_anim/idle_6.xpm", &game->player.width, &game->player.height);
	game->player.idle_img_7 = mlx_xpm_file_to_image(game->mlx_ptr, "sprite/knight/idle_anim/idle_7.xpm", &game->player.width, &game->player.height);
	game->player.idle_img_8 = mlx_xpm_file_to_image(game->mlx_ptr, "sprite/knight/idle_anim/idle_8.xpm", &game->player.width, &game->player.height);
	game->player.idle_img_9 = mlx_xpm_file_to_image(game->mlx_ptr, "sprite/knight/idle_anim/idle_9.xpm", &game->player.width, &game->player.height);
}

void	open_imgs(t_game *game)
{
   open_player_imgs(game);
}