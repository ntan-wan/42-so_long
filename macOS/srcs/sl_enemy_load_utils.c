/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_enemy_load_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 18:58:11 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/10/18 19:04:55 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	sl_enemy_load_img_idle(void *mlx, t_img **imgs)
{
	sl_img_load(mlx, imgs, "e_idle0_r", "sprite/enemy/idle_right0.xpm");
	sl_img_load(mlx, imgs, "e_idle1_r", "sprite/enemy/idle_right1.xpm");
	sl_img_load(mlx, imgs, "e_idle2_r", "sprite/enemy/idle_right2.xpm");
	sl_img_load(mlx, imgs, "e_idle3_r", "sprite/enemy/idle_right3.xpm");
	sl_img_load(mlx, imgs, "e_idle4_r", "sprite/enemy/idle_right4.xpm");
	sl_img_load(mlx, imgs, "e_idle5_r", "sprite/enemy/idle_right5.xpm");
	sl_img_load(mlx, imgs, "e_idle0_l", "sprite/enemy/idle_left0.xpm");
	sl_img_load(mlx, imgs, "e_idle1_l", "sprite/enemy/idle_left1.xpm");
	sl_img_load(mlx, imgs, "e_idle2_l", "sprite/enemy/idle_left2.xpm");
	sl_img_load(mlx, imgs, "e_idle3_l", "sprite/enemy/idle_left3.xpm");
	sl_img_load(mlx, imgs, "e_idle4_l", "sprite/enemy/idle_left4.xpm");
	sl_img_load(mlx, imgs, "e_idle5_l", "sprite/enemy/idle_left5.xpm");
}

void	sl_enemy_load_imgs_move(void *mlx, t_img **imgs)
{
	sl_img_load(mlx, imgs, "e_run0_r", "sprite/enemy/run_right0.xpm");
	sl_img_load(mlx, imgs, "e_run1_r", "sprite/enemy/run_right1.xpm");
	sl_img_load(mlx, imgs, "e_run2_r", "sprite/enemy/run_right2.xpm");
	sl_img_load(mlx, imgs, "e_run3_r", "sprite/enemy/run_right3.xpm");
	sl_img_load(mlx, imgs, "e_run4_r", "sprite/enemy/run_right4.xpm");
	sl_img_load(mlx, imgs, "e_run5_r", "sprite/enemy/run_right5.xpm");
	sl_img_load(mlx, imgs, "e_run0_l", "sprite/enemy/run_left0.xpm");
	sl_img_load(mlx, imgs, "e_run1_l", "sprite/enemy/run_left1.xpm");
	sl_img_load(mlx, imgs, "e_run2_l", "sprite/enemy/run_left2.xpm");
	sl_img_load(mlx, imgs, "e_run3_l", "sprite/enemy/run_left3.xpm");
	sl_img_load(mlx, imgs, "e_run4_l", "sprite/enemy/run_left4.xpm");
	sl_img_load(mlx, imgs, "e_run5_l", "sprite/enemy/run_left5.xpm");
}

static void	sl_enemy_load_anim_idle(t_enemy *e, t_img *imgs)
{
	sl_anim_add_frame(e->idle_right, sl_img_search("e_idle0_r", imgs));
	sl_anim_add_frame(e->idle_right, sl_img_search("e_idle1_r", imgs));
	sl_anim_add_frame(e->idle_right, sl_img_search("e_idle2_r", imgs));
	sl_anim_add_frame(e->idle_right, sl_img_search("e_idle3_r", imgs));
	sl_anim_add_frame(e->idle_right, sl_img_search("e_idle4_r", imgs));
	sl_anim_add_frame(e->idle_right, sl_img_search("e_idle5_r", imgs));
	sl_anim_add_frame(e->idle_left, sl_img_search("e_idle0_l", imgs));
	sl_anim_add_frame(e->idle_left, sl_img_search("e_idle1_l", imgs));
	sl_anim_add_frame(e->idle_left, sl_img_search("e_idle2_l", imgs));
	sl_anim_add_frame(e->idle_left, sl_img_search("e_idle3_l", imgs));
	sl_anim_add_frame(e->idle_left, sl_img_search("e_idle4_l", imgs));
	sl_anim_add_frame(e->idle_left, sl_img_search("e_idle5_l", imgs));
}

static void	sl_enemy_load_anim_move(t_enemy *e, t_img *imgs)
{
	sl_anim_add_frame(e->move_right, sl_img_search("e_run0_r", imgs));
	sl_anim_add_frame(e->move_right, sl_img_search("e_run1_r", imgs));
	sl_anim_add_frame(e->move_right, sl_img_search("e_run2_r", imgs));
	sl_anim_add_frame(e->move_right, sl_img_search("e_run3_r", imgs));
	sl_anim_add_frame(e->move_right, sl_img_search("e_run4_r", imgs));
	sl_anim_add_frame(e->move_right, sl_img_search("e_run5_r", imgs));
	sl_anim_add_frame(e->move_left, sl_img_search("e_run0_l", imgs));
	sl_anim_add_frame(e->move_left, sl_img_search("e_run1_l", imgs));
	sl_anim_add_frame(e->move_left, sl_img_search("e_run2_l", imgs));
	sl_anim_add_frame(e->move_left, sl_img_search("e_run3_l", imgs));
	sl_anim_add_frame(e->move_left, sl_img_search("e_run4_l", imgs));
	sl_anim_add_frame(e->move_left, sl_img_search("e_run5_l", imgs));
}

void	sl_enemies_load_anim(t_list *enemies, t_img *imgs)
{
	t_list	*enemy;

	enemy = enemies;
	while (enemy)
	{
		sl_enemy_load_anim_idle((t_enemy *)enemy->content, imgs);
		sl_enemy_load_anim_move((t_enemy *)enemy->content, imgs);
		enemy = enemy->next;
	}
}
