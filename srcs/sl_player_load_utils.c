/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_player_load_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 16:30:18 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/09/30 16:58:47 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	sl_player_load_imgs_idle(void *mlx, t_img **imgs)
{
	sl_load_img(mlx, imgs, "k_idle0_r", "sprite/knight/idle_right0.xpm");
	sl_load_img(mlx, imgs, "k_idle1_r", "sprite/knight/idle_right1.xpm");
	sl_load_img(mlx, imgs, "k_idle2_r", "sprite/knight/idle_right2.xpm");
	sl_load_img(mlx, imgs, "k_idle3_r", "sprite/knight/idle_right3.xpm");
	sl_load_img(mlx, imgs, "k_idle4_r", "sprite/knight/idle_right4.xpm");
	sl_load_img(mlx, imgs, "k_idle5_r", "sprite/knight/idle_right5.xpm");
	sl_load_img(mlx, imgs, "k_idle0_l", "sprite/knight/idle_left0.xpm");
	sl_load_img(mlx, imgs, "k_idle1_l", "sprite/knight/idle_left1.xpm");
	sl_load_img(mlx, imgs, "k_idle2_l", "sprite/knight/idle_left2.xpm");
	sl_load_img(mlx, imgs, "k_idle3_l", "sprite/knight/idle_left3.xpm");
	sl_load_img(mlx, imgs, "k_idle4_l", "sprite/knight/idle_left4.xpm");
	sl_load_img(mlx, imgs, "k_idle5_l", "sprite/knight/idle_left5.xpm");
}

void	sl_player_load_imgs_move(void *mlx, t_img **imgs)
{
	sl_load_img(mlx, imgs, "k_run0_r", "sprite/knight/run_right0.xpm");
	sl_load_img(mlx, imgs, "k_run1_r", "sprite/knight/run_right1.xpm");
	sl_load_img(mlx, imgs, "k_run2_r", "sprite/knight/run_right2.xpm");
	sl_load_img(mlx, imgs, "k_run3_r", "sprite/knight/run_right3.xpm");
	sl_load_img(mlx, imgs, "k_run4_r", "sprite/knight/run_right4.xpm");
	sl_load_img(mlx, imgs, "k_run5_r", "sprite/knight/run_right5.xpm");
	sl_load_img(mlx, imgs, "k_run0_l", "sprite/knight/run_left0.xpm");
	sl_load_img(mlx, imgs, "k_run1_l", "sprite/knight/run_left1.xpm");
	sl_load_img(mlx, imgs, "k_run2_l", "sprite/knight/run_left2.xpm");
	sl_load_img(mlx, imgs, "k_run3_l", "sprite/knight/run_left3.xpm");
	sl_load_img(mlx, imgs, "k_run4_l", "sprite/knight/run_left4.xpm");
	sl_load_img(mlx, imgs, "k_run5_l", "sprite/knight/run_left5.xpm");

    /*sl_load_img(mlx, imgs, "h_idle0", "sprite/hero/idle0.xpm");
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
	sl_load_img(mlx, imgs, "h_attack2", "sprite/hero/attack2.xpm");
	sl_load_img(mlx, imgs, "h_attack3", "sprite/hero/attack3.xpm");*/
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

    /*sl_anim_add_frame(player->idle_right, sl_img_search("h_idle0", imgs));
	sl_anim_add_frame(player->idle_right, sl_img_search("h_idle1", imgs));
	sl_anim_add_frame(player->idle_right, sl_img_search("h_idle2", imgs));
	sl_anim_add_frame(player->idle_right, sl_img_search("h_idle3", imgs));
	sl_anim_add_frame(player->move_right, sl_img_search("h_run0", imgs));
	sl_anim_add_frame(player->move_right, sl_img_search("h_run1", imgs));
	sl_anim_add_frame(player->move_right, sl_img_search("h_run2", imgs));
	sl_anim_add_frame(player->move_right, sl_img_search("h_run3", imgs));
	sl_anim_add_frame(player->move_right, sl_img_search("h_run4", imgs));
	sl_anim_add_frame(player->move_right, sl_img_search("h_run5", imgs));
	sl_anim_add_frame(player->attack_right, sl_img_search("h_attack0", imgs));
	sl_anim_add_frame(player->attack_right, sl_img_search("h_attack1", imgs));
	sl_anim_add_frame(player->attack_right, sl_img_search("h_attack2", imgs));
	sl_anim_add_frame(player->attack_right, sl_img_search("h_attack3", imgs));*/
}