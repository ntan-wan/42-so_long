/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_player_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 08:48:45 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/09/30 16:35:06 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/*static void	sl_player_load_imgs(void *mlx, t_img **imgs)
{
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
	sl_load_img(mlx, imgs, "h_attack2", "sprite/hero/attack2.xpm");
	sl_load_img(mlx, imgs, "h_attack3", "sprite/hero/attack3.xpm");
}

static void	sl_player_load_anim(t_player *player, t_img *imgs)
{
	
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
	sl_anim_add_frame(player->attack_right, sl_img_search("h_attack3", imgs));
}*/

void	sl_player_init(void *mlx, t_player **player, t_img **imgs)
{
	t_player	*new_player;

	new_player = (t_player *)malloc(sizeof(t_player));
	if (new_player)
	{
		new_player->action = 0;
		new_player->idle_left = sl_anim_init();
		new_player->idle_right = sl_anim_init();
		new_player->move_left = sl_anim_init();
		new_player->move_right = sl_anim_init();
		sl_player_load_imgs_idle(mlx, imgs);
		sl_player_load_imgs_move(mlx, imgs);
		sl_player_load_anim_idle(new_player, *imgs);
		sl_player_load_anim_move(new_player, *imgs);
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
	if (player->action == IDLE_RIGHT)
		return (sl_anim_get_frame(player->idle_right,
				frame % player->idle_right->frame_count));
	else if (player->action == MOVE_RIGHT)
		return (sl_anim_get_frame(player->move_right,
				frame % player->move_right->frame_count));
	else if (player->action == MOVE_LEFT)
		return (sl_anim_get_frame(player->move_left,
				frame % player->move_left->frame_count));
	else if (player->action == IDLE_LEFT)
		return (sl_anim_get_frame(player->idle_left,
				frame % player->idle_left->frame_count));
}
