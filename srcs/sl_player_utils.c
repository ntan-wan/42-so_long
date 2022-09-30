/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_player_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 08:48:45 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/09/30 14:07:23 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	sl_player_load_imgs(void *mlx, t_img **imgs)
{
	/*sl_load_img(mlx, imgs, "k_idle0", "sprite/knight/idle0.xpm");
	sl_load_img(mlx, imgs, "k_idle1", "sprite/knight/idle1.xpm");
	sl_load_img(mlx, imgs, "k_idle2", "sprite/knight/idle2.xpm");
	sl_load_img(mlx, imgs, "k_idle3", "sprite/knight/idle3.xpm");
	sl_load_img(mlx, imgs, "k_idle4", "sprite/knight/idle4.xpm");
	sl_load_img(mlx, imgs, "k_idle5", "sprite/knight/idle5.xpm");
	sl_load_img(mlx, imgs, "k_right0", "sprite/knight/run0.xpm");
	sl_load_img(mlx, imgs, "k_right1", "sprite/knight/run1.xpm");
	sl_load_img(mlx, imgs, "k_right2", "sprite/knight/run2.xpm");
	sl_load_img(mlx, imgs, "k_right3", "sprite/knight/run3.xpm");
	sl_load_img(mlx, imgs, "k_right4", "sprite/knight/run4.xpm");
	sl_load_img(mlx, imgs, "k_right5", "sprite/knight/run5.xpm");*/
	sl_load_img(mlx, imgs, "h_idle0", "sprite/hero/idle0.xpm");
	sl_load_img(mlx, imgs, "h_idle1", "sprite/hero/idle1.xpm");
	sl_load_img(mlx, imgs, "h_idle2", "sprite/hero/idle2.xpm");
	sl_load_img(mlx, imgs, "h_idle3", "sprite/hero/idle3.xpm");
	sl_load_img(mlx, imgs, "h_run0", "sprite/hero/run0.xpm");
	sl_load_img(mlx, imgs, "h_run1", "sprite/hero/run1.xpm");
	sl_load_img(mlx, imgs, "h_run2", "sprite/hero/run2.xpm");
	sl_load_img(mlx, imgs, "h_run3", "sprite/hero/run3.xpm");
	sl_load_img(mlx, imgs, "h_run4", "sprite/hero/run4.xpm");
	sl_load_img(mlx, imgs, "h_run5", "sprite/hero/run5.xpm");
	sl_load_img(mlx, imgs, "h_attack0", "sprite/hero/attack0.xpm");
	sl_load_img(mlx, imgs, "h_attack1", "sprite/hero/attack1.xpm");
	// sl_load_img(mlx, imgs, "h_attack2", "sprite/hero/attack2.xpm");
	sl_load_img(mlx, imgs, "h_attack3", "sprite/hero/attack3.xpm");
}

static void	sl_player_load_anim(t_player *player, t_img *imgs)
{
	/*sl_anim_add_frame(player->idle, sl_img_search("k_idle0", imgs));
	sl_anim_add_frame(player->idle, sl_img_search("k_idle1", imgs));
	sl_anim_add_frame(player->idle, sl_img_search("k_idle2", imgs));
	sl_anim_add_frame(player->idle, sl_img_search("k_idle3", imgs));
	sl_anim_add_frame(player->idle, sl_img_search("k_idle4", imgs));
	sl_anim_add_frame(player->idle, sl_img_search("k_idle5", imgs));
	sl_anim_add_frame(player->move_right, sl_img_search("k_right0", imgs));
	sl_anim_add_frame(player->move_right, sl_img_search("k_right1", imgs));
	sl_anim_add_frame(player->move_right, sl_img_search("k_right2", imgs));
	sl_anim_add_frame(player->move_right, sl_img_search("k_right3", imgs));
	sl_anim_add_frame(player->move_right, sl_img_search("k_right4", imgs));
	sl_anim_add_frame(player->move_right, sl_img_search("k_right5", imgs));*/
	sl_anim_add_frame(player->idle, sl_img_search("h_idle0", imgs));
	sl_anim_add_frame(player->idle, sl_img_search("h_idle1", imgs));
	sl_anim_add_frame(player->idle, sl_img_search("h_idle2", imgs));
	sl_anim_add_frame(player->idle, sl_img_search("h_idle3", imgs));
	sl_anim_add_frame(player->move_right, sl_img_search("h_run0", imgs));
	sl_anim_add_frame(player->move_right, sl_img_search("h_run1", imgs));
	sl_anim_add_frame(player->move_right, sl_img_search("h_run2", imgs));
	sl_anim_add_frame(player->move_right, sl_img_search("h_run3", imgs));
	sl_anim_add_frame(player->move_right, sl_img_search("h_run4", imgs));
	sl_anim_add_frame(player->move_right, sl_img_search("h_run5", imgs));
	sl_anim_add_frame(player->attack_right, sl_img_search("h_attack0", imgs));
	sl_anim_add_frame(player->attack_right, sl_img_search("h_attack1", imgs));
	// sl_anim_add_frame(player->attack_right, sl_img_search("h_attack2", imgs));
	sl_anim_add_frame(player->attack_right, sl_img_search("h_attack3", imgs));
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
		new_player->attack_right = sl_anim_init();
		sl_player_load_imgs(mlx, imgs);
		sl_player_load_anim(new_player, *imgs);
	}
	else
		ft_putstr_fd("player_init: init failed\n", 1);
	*player = new_player;
}

t_img	*sl_player_get_anim(t_player *player)
{
	static unsigned int timer;
	static unsigned int frame;

	frame = timer++ / INTERVAL;
	if (player->movement == IDLE)
		return (sl_anim_get_frame(player->idle,
				frame % player->idle->frame_count));
	else if (player->movement = RIGHT)
		return (sl_anim_get_frame(player->move_right,
				frame % player->move_right->frame_count));
}
