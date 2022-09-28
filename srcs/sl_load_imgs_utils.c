/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_load_imgs_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 08:50:04 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/09/28 12:54:19 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/* init + add imgs */
void	sl_load_img(void *mlx, t_img **head, char *key, char *path)
{
	sl_img_add(head, sl_img_init(mlx, key, path));
}

void	sl_load_imgs_player(void *mlx, t_player *player)
{
	sl_load_img(mlx, &player->move_right, "right0", "sprite/knight/run0.xpm");
	sl_load_img(mlx, &player->move_right, "right1", "sprite/knight/run1.xpm");
	sl_load_img(mlx, &player->move_right, "right2", "sprite/knight/run2.xpm");
	sl_load_img(mlx, &player->move_right, "right3", "sprite/knight/run3.xpm");
	sl_load_img(mlx, &player->move_right, "right4", "sprite/knight/run4.xpm");
	sl_load_img(mlx, &player->move_right, "right5", "sprite/knight/run5.xpm");
}