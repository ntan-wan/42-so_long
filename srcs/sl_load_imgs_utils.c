/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_load_imgs_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 13:44:17 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/09/26 14:27:24 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/* init and add imgs */
void	sl_load_imgs(void *mlx_ptr, t_imgs *head, char *key, char *path)
{
	sl_imgs_add(head, sl_imgs_init(mlx_ptr, key, path));
}

void	sl_load_player_imgs(void *mlx_ptr, t_player *player)
{
	sl_load_imgs(mlx_ptr, player->idle, "idle0", "sprite/knight/idle_0.xpm");
}
