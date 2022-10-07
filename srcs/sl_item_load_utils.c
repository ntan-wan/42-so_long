/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_item_load_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 23:41:43 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/10/07 09:20:37 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	sl_item_load_imgs_chest_shine(void *mlx, t_img **imgs)
{
	sl_load_img(mlx, imgs, "chest_close1", "sprite/items/chest_closed1.xpm");
	sl_load_img(mlx, imgs, "chest_close2", "sprite/items/chest_closed2.xpm");
	sl_load_img(mlx, imgs, "chest_close3", "sprite/items/chest_closed3.xpm");
	sl_load_img(mlx, imgs, "chest_close4", "sprite/items/chest_closed4.xpm");
	sl_load_img(mlx, imgs, "chest_close5", "sprite/items/chest_closed5.xpm");
	sl_load_img(mlx, imgs, "chest_close6", "sprite/items/chest_closed6.xpm");
	sl_load_img(mlx, imgs, "chest_close7", "sprite/items/chest_closed7.xpm");
}

void	sl_item_load_imgs_chest_idle(void *mlx, t_img **imgs)
{
	sl_load_img(mlx, imgs, "chest_close0", "sprite/items/chest_closed0.xpm");
	sl_load_img(mlx, imgs, "chest_open", "sprite/items/chest_open.xpm");
}

void	sl_item_load_anim_chest_shine(t_chest *chest, t_img *imgs)
{
	sl_anim_add_frame(chest->shine, sl_img_search("chest_close1", imgs));
	sl_anim_add_frame(chest->shine, sl_img_search("chest_close2", imgs));
	sl_anim_add_frame(chest->shine, sl_img_search("chest_close3", imgs));
	sl_anim_add_frame(chest->shine, sl_img_search("chest_close4", imgs));
	sl_anim_add_frame(chest->shine, sl_img_search("chest_close5", imgs));
	sl_anim_add_frame(chest->shine, sl_img_search("chest_close6", imgs));
	sl_anim_add_frame(chest->shine, sl_img_search("chest_close7", imgs));
}

void	sl_item_load_anim_chest_idle(t_chest *chest, t_img *imgs)
{
	sl_anim_add_frame(chest->close, sl_img_search("chest_close0", imgs));
	sl_anim_add_frame(chest->open, sl_img_search("chest_open", imgs));
}

void	sl_item_load_anim_chests(t_chest *chest, t_img *imgs)
{
	t_chest	*ptr_chest;

	ptr_chest = chest;
	while (ptr_chest)
	{
		sl_item_load_anim_chest_idle(ptr_chest, imgs);
		sl_item_load_anim_chest_shine(ptr_chest, imgs);
		ptr_chest = ptr_chest->next;
	}
}
