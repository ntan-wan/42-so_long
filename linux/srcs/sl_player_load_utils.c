/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_player_load_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 16:30:18 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/10/17 13:44:31 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	sl_player_load_imgs_idle(void *mlx, t_img **imgs)
{
	sl_img_load(mlx, imgs, "k_idle0_r", "sprite/knight/idle_right0.xpm");
	sl_img_load(mlx, imgs, "k_idle1_r", "sprite/knight/idle_right1.xpm");
	sl_img_load(mlx, imgs, "k_idle2_r", "sprite/knight/idle_right2.xpm");
	sl_img_load(mlx, imgs, "k_idle3_r", "sprite/knight/idle_right3.xpm");
	sl_img_load(mlx, imgs, "k_idle4_r", "sprite/knight/idle_right4.xpm");
	sl_img_load(mlx, imgs, "k_idle5_r", "sprite/knight/idle_right5.xpm");
	sl_img_load(mlx, imgs, "k_idle0_l", "sprite/knight/idle_left0.xpm");
	sl_img_load(mlx, imgs, "k_idle1_l", "sprite/knight/idle_left1.xpm");
	sl_img_load(mlx, imgs, "k_idle2_l", "sprite/knight/idle_left2.xpm");
	sl_img_load(mlx, imgs, "k_idle3_l", "sprite/knight/idle_left3.xpm");
	sl_img_load(mlx, imgs, "k_idle4_l", "sprite/knight/idle_left4.xpm");
	sl_img_load(mlx, imgs, "k_idle5_l", "sprite/knight/idle_left5.xpm");
}

void	sl_player_load_imgs_move(void *mlx, t_img **imgs)
{
	sl_img_load(mlx, imgs, "k_run0_r", "sprite/knight/run_right0.xpm");
	sl_img_load(mlx, imgs, "k_run1_r", "sprite/knight/run_right1.xpm");
	sl_img_load(mlx, imgs, "k_run2_r", "sprite/knight/run_right2.xpm");
	sl_img_load(mlx, imgs, "k_run3_r", "sprite/knight/run_right3.xpm");
	sl_img_load(mlx, imgs, "k_run4_r", "sprite/knight/run_right4.xpm");
	sl_img_load(mlx, imgs, "k_run5_r", "sprite/knight/run_right5.xpm");
	sl_img_load(mlx, imgs, "k_run0_l", "sprite/knight/run_left0.xpm");
	sl_img_load(mlx, imgs, "k_run1_l", "sprite/knight/run_left1.xpm");
	sl_img_load(mlx, imgs, "k_run2_l", "sprite/knight/run_left2.xpm");
	sl_img_load(mlx, imgs, "k_run3_l", "sprite/knight/run_left3.xpm");
	sl_img_load(mlx, imgs, "k_run4_l", "sprite/knight/run_left4.xpm");
	sl_img_load(mlx, imgs, "k_run5_l", "sprite/knight/run_left5.xpm");
}

void	sl_player_load_anim_idle(t_player *player, t_img *imgs)
{
	sl_anim_add_frame(player->idle_right, sl_img_search("k_idle0_r", imgs));
	sl_anim_add_frame(player->idle_right, sl_img_search("k_idle1_r", imgs));
	sl_anim_add_frame(player->idle_right, sl_img_search("k_idle2_r", imgs));
	sl_anim_add_frame(player->idle_right, sl_img_search("k_idle3_r", imgs));
	sl_anim_add_frame(player->idle_right, sl_img_search("k_idle4_r", imgs));
	sl_anim_add_frame(player->idle_right, sl_img_search("k_idle5_r", imgs));
	sl_anim_add_frame(player->idle_left, sl_img_search("k_idle0_l", imgs));
	sl_anim_add_frame(player->idle_left, sl_img_search("k_idle1_l", imgs));
	sl_anim_add_frame(player->idle_left, sl_img_search("k_idle2_l", imgs));
	sl_anim_add_frame(player->idle_left, sl_img_search("k_idle3_l", imgs));
	sl_anim_add_frame(player->idle_left, sl_img_search("k_idle4_l", imgs));
	sl_anim_add_frame(player->idle_left, sl_img_search("k_idle5_l", imgs));
}

void	sl_player_load_anim_move(t_player *player, t_img *imgs)
{
	sl_anim_add_frame(player->move_right, sl_img_search("k_run0_r", imgs));
	sl_anim_add_frame(player->move_right, sl_img_search("k_run1_r", imgs));
	sl_anim_add_frame(player->move_right, sl_img_search("k_run2_r", imgs));
	sl_anim_add_frame(player->move_right, sl_img_search("k_run3_r", imgs));
	sl_anim_add_frame(player->move_right, sl_img_search("k_run4_r", imgs));
	sl_anim_add_frame(player->move_right, sl_img_search("k_run5_r", imgs));
	sl_anim_add_frame(player->move_left, sl_img_search("k_run0_l", imgs));
	sl_anim_add_frame(player->move_left, sl_img_search("k_run1_l", imgs));
	sl_anim_add_frame(player->move_left, sl_img_search("k_run2_l", imgs));
	sl_anim_add_frame(player->move_left, sl_img_search("k_run3_l", imgs));
	sl_anim_add_frame(player->move_left, sl_img_search("k_run4_l", imgs));
	sl_anim_add_frame(player->move_left, sl_img_search("k_run5_l", imgs));
}
