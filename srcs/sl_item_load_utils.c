/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_item_load_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 23:41:43 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/10/18 17:02:15 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	sl_item_load_imgs_chest(void *mlx, t_img **imgs)
{
	sl_img_load(mlx, imgs, "chest_close0", "sprite/items/chest_closed0.xpm");
	sl_img_load(mlx, imgs, "chest_close1", "sprite/items/chest_closed1.xpm");
	sl_img_load(mlx, imgs, "chest_close2", "sprite/items/chest_closed2.xpm");
	sl_img_load(mlx, imgs, "chest_close3", "sprite/items/chest_closed3.xpm");
	sl_img_load(mlx, imgs, "chest_close4", "sprite/items/chest_closed4.xpm");
	sl_img_load(mlx, imgs, "chest_close5", "sprite/items/chest_closed5.xpm");
	sl_img_load(mlx, imgs, "chest_close6", "sprite/items/chest_closed6.xpm");
	sl_img_load(mlx, imgs, "chest_close7", "sprite/items/chest_closed7.xpm");
	sl_img_load(mlx, imgs, "coin0", "sprite/items/coin0.xpm");
	sl_img_load(mlx, imgs, "coin1", "sprite/items/coin1.xpm");
	sl_img_load(mlx, imgs, "coin2", "sprite/items/coin2.xpm");
	sl_img_load(mlx, imgs, "coin3", "sprite/items/coin3.xpm");
	sl_img_load(mlx, imgs, "coin4", "sprite/items/coin4.xpm");
	sl_img_load(mlx, imgs, "coin5", "sprite/items/coin5.xpm");
}

void	sl_item_load_anim_chest(t_chest *chest, t_img *imgs)
{
	sl_anim_add_frame(chest->open, sl_img_search("coin0", imgs));
	sl_anim_add_frame(chest->open, sl_img_search("coin1", imgs));
	sl_anim_add_frame(chest->open, sl_img_search("coin2", imgs));
	sl_anim_add_frame(chest->open, sl_img_search("coin3", imgs));
	sl_anim_add_frame(chest->open, sl_img_search("coin4", imgs));
	sl_anim_add_frame(chest->open, sl_img_search("coin5", imgs));
	sl_anim_add_frame(chest->close, sl_img_search("chest_close0", imgs));
	sl_anim_add_frame(chest->shine, sl_img_search("chest_close1", imgs));
	sl_anim_add_frame(chest->shine, sl_img_search("chest_close2", imgs));
	sl_anim_add_frame(chest->shine, sl_img_search("chest_close3", imgs));
	sl_anim_add_frame(chest->shine, sl_img_search("chest_close4", imgs));
	sl_anim_add_frame(chest->shine, sl_img_search("chest_close5", imgs));
	sl_anim_add_frame(chest->shine, sl_img_search("chest_close6", imgs));
	sl_anim_add_frame(chest->shine, sl_img_search("chest_close7", imgs));
}

void	sl_item_load_anim_chests(t_chest *chest, t_img *imgs)
{
	t_chest	*ptr_chest;

	ptr_chest = chest;
	while (ptr_chest)
	{
		sl_item_load_anim_chest(ptr_chest, imgs);
		ptr_chest = ptr_chest->next;
	}
}
