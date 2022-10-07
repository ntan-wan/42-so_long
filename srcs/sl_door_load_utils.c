/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_door_load_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 08:28:09 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/10/07 09:25:44 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	sl_door_load_imgs_opening(void *mlx, t_img **imgs)
{
	sl_load_img(mlx, imgs, "opening0", "sprite/door/door_open0.xpm");
	sl_load_img(mlx, imgs, "opening1", "sprite/door/door_open1.xpm");
	sl_load_img(mlx, imgs, "opening2", "sprite/door/door_open2.xpm");
	sl_load_img(mlx, imgs, "opening3", "sprite/door/door_open3.xpm");
	sl_load_img(mlx, imgs, "opening4", "sprite/door/door_open4.xpm");
	sl_load_img(mlx, imgs, "opening5", "sprite/door/door_open5.xpm");
	sl_load_img(mlx, imgs, "opening6", "sprite/door/door_open6.xpm");
	sl_load_img(mlx, imgs, "opening7", "sprite/door/door_open7.xpm");
	sl_load_img(mlx, imgs, "opening8", "sprite/door/door_open8.xpm");
	sl_load_img(mlx, imgs, "opening9", "sprite/door/door_open9.xpm");
	sl_load_img(mlx, imgs, "opening10", "sprite/door/door_open10.xpm");
	sl_load_img(mlx, imgs, "opening11", "sprite/door/door_open11.xpm");
	sl_load_img(mlx, imgs, "opening12", "sprite/door/door_open12.xpm");
	sl_load_img(mlx, imgs, "opening13", "sprite/door/door_open13.xpm");
}

void	sl_door_load_imgs_idle(void *mlx, t_img **imgs)
{
	sl_load_img(mlx, imgs, "opened", "sprite/door/door_opened.xpm");
	sl_load_img(mlx, imgs, "closed", "sprite/door/door_closed.xpm");
}

void	sl_door_load_anim_opening(t_door *door, t_img *imgs)
{
	sl_anim_add_frame(door->open, sl_img_search("opening0", imgs));
	sl_anim_add_frame(door->open, sl_img_search("opening1", imgs));
	sl_anim_add_frame(door->open, sl_img_search("opening2", imgs));
	sl_anim_add_frame(door->open, sl_img_search("opening3", imgs));
	sl_anim_add_frame(door->open, sl_img_search("opening4", imgs));
	sl_anim_add_frame(door->open, sl_img_search("opening5", imgs));
	sl_anim_add_frame(door->open, sl_img_search("opening6", imgs));
	sl_anim_add_frame(door->open, sl_img_search("opening7", imgs));
	sl_anim_add_frame(door->open, sl_img_search("opening8", imgs));
	sl_anim_add_frame(door->open, sl_img_search("opening9", imgs));
	sl_anim_add_frame(door->open, sl_img_search("opening10", imgs));
	sl_anim_add_frame(door->open, sl_img_search("opening11", imgs));
	sl_anim_add_frame(door->open, sl_img_search("opening12", imgs));
	sl_anim_add_frame(door->open, sl_img_search("opening13", imgs));
}

void	sl_door_load_anim_idle(t_door *door, t_img *imgs)
{
	sl_anim_add_frame(door->opened, sl_img_search("opened", imgs));
	sl_anim_add_frame(door->closed, sl_img_search("closed", imgs));
}
