/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_player_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 08:48:45 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/09/28 21:24:26 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	sl_player_init(void *mlx, t_player *player)
{
	player->idle = NULL;
	player->move_right = NULL;
	//sl_load_imgs_player(mlx, player);
}
