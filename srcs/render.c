/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 08:14:07 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/09/23 16:53:23 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void    render(t_game *game)
{
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->player.current_img, 0, 0);
}

int	render_next_frame(t_game *game)
{
	animate_player(&game->player);
	render(game);
	return (0);
}