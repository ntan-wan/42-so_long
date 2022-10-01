/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_load_imgs_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 08:50:04 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/10/01 21:20:29 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/* init + add imgs */
void	sl_load_img(void *mlx, t_img **head, char *key, char *path)
{
	sl_img_add(head, sl_img_init(mlx, key, path));
}

void	sl_load_imgs(t_game *game)
{
	sl_player_load_imgs_idle(game->mlx, &game->imgs);
	sl_player_load_imgs_move(game->mlx, &game->imgs);
	sl_player_load_anim_idle(game->player, game->imgs);
	sl_player_load_anim_move(game->player, game->imgs);
	sl_item_load_imgs_chest_open(game->mlx, &game->imgs);
	sl_item_load_imgs_chest_close(game->mlx, &game->imgs);
	sl_item_load_anim_chest_open(game->chest, game->imgs);
	sl_item_load_anim_chest_close(game->chest, game->imgs);
}
