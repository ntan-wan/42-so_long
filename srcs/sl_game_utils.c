/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_game_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 10:08:26 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/10/11 11:23:46 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	sl_game_init(t_game *g)
{
	if (g)
	{
		g->mlx = mlx_init();
		g->win = mlx_new_window(g->mlx, WINDOW_W, WINDOW_H, "so_long");
		g->imgs = NULL;
		g->chest = NULL;
		g->player = NULL;
		g->map = NULL;
	}
	else
		sl_exit_msg(g, "game_init\n", EXIT_FAILURE);
}

void	sl_game_load_imgs(t_game *g)
{
	sl_img_load(g->mlx, &g->imgs, "wall", "sprite/tiles/wall1.xpm");
	sl_img_load(g->mlx, &g->imgs, "floor", "sprite/tiles/floor2.xpm");
	sl_player_load_imgs_idle(g->mlx, &g->imgs);
	sl_player_load_imgs_move(g->mlx, &g->imgs);
	sl_item_load_imgs_chest(g->mlx, &g->imgs);
	sl_door_load_imgs(g->mlx, &g->imgs);
}

void	sl_game_load_anims(t_game *g)
{
	sl_player_load_anim_idle(g->player, g->imgs);
	sl_player_load_anim_move(g->player, g->imgs);
	sl_item_load_anim_chests(g->chest, g->imgs);
	sl_door_load_anims(g->door, g->imgs);
}

void	sl_game_init_all(t_game *g)
{
	sl_game_init(g);
	sl_map_init(&g->map);
	sl_door_init(&g->door);
	sl_player_init(&g->player);
}
