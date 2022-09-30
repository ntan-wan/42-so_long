/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_player_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 08:48:45 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/09/30 08:59:25 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	sl_player_load_imgs(void *mlx, t_img **imgs)
{
	sl_load_img(mlx, imgs, "k_right0", "sprite/knight/run0.xpm");
	sl_load_img(mlx, imgs, "k_right1", "sprite/knight/run1.xpm");
	sl_load_img(mlx, imgs, "k_right2", "sprite/knight/run2.xpm");
	sl_load_img(mlx, imgs, "k_right3", "sprite/knight/run3.xpm");
	sl_load_img(mlx, imgs, "k_right4", "sprite/knight/run4.xpm");
	sl_load_img(mlx, imgs, "k_right5", "sprite/knight/run5.xpm");
	sl_load_img(mlx, imgs, "d_right0", "sprite/debug/knight/idle_0.xpm");
	sl_load_img(mlx, imgs, "d_right1", "sprite/debug/knight/idle_1.xpm");
	sl_load_img(mlx, imgs, "d_right2", "sprite/debug/knight/idle_2.xpm");
	sl_load_img(mlx, imgs, "d_right3", "sprite/debug/knight/idle_3.xpm");
	sl_load_img(mlx, imgs, "d_right4", "sprite/debug/knight/idle_4.xpm");
	sl_load_img(mlx, imgs, "d_right5", "sprite/debug/knight/idle_5.xpm");
}

static void	sl_player_load_anim(t_player *player, t_img *imgs)
{
	sl_anim_add_frame(player->move_right, sl_img_search("k_right0", imgs));
	sl_anim_add_frame(player->move_right, sl_img_search("k_right1", imgs));
	sl_anim_add_frame(player->move_right, sl_img_search("k_right2", imgs));
	sl_anim_add_frame(player->move_right, sl_img_search("k_right3", imgs));
	sl_anim_add_frame(player->move_right, sl_img_search("k_right4", imgs));
	sl_anim_add_frame(player->move_right, sl_img_search("k_right5", imgs));
	sl_anim_add_frame(player->idle, sl_img_search("d_right0", imgs));
	sl_anim_add_frame(player->idle, sl_img_search("d_right1", imgs));
	sl_anim_add_frame(player->idle, sl_img_search("d_right2", imgs));
	sl_anim_add_frame(player->idle, sl_img_search("d_right3", imgs));
	sl_anim_add_frame(player->idle, sl_img_search("d_right4", imgs));
	sl_anim_add_frame(player->idle, sl_img_search("d_right5", imgs));
}

void	sl_player_init(void *mlx, t_player **player, t_img **imgs)
{
	t_player	*new_player;

	new_player = (t_player *)malloc(sizeof(t_player));
	if (new_player)
	{
		new_player->movement = 0;
		new_player->idle = sl_anim_init();
		new_player->move_right = sl_anim_init();
		sl_player_load_imgs(mlx, imgs);
		sl_player_load_anim(new_player, *imgs);
	}
	else
		ft_putstr_fd("player_init: init failed\n", 1);
	*player = new_player;
}

void	sl_player_get_anim(t_img *dst, t_player *player)
{
	t_anim				*anim;
	static unsigned int	timer;
	static unsigned int	frame;

	anim = player->move_right;
	frame = timer++ / INTERVAL;
	sl_copy_img(dst, sl_anim_get_frame(anim,
			frame % anim->frame_count), 0, 0);
}
