/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 17:07:36 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/09/23 13:32:48 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	mlx_hooks_setup(t_game *game)
{
	mlx_key_hook(game->win_ptr, handle_input, game);
	mlx_hook(game->win_ptr, 17, 0, end_program, game);
	mlx_loop_hook(game->mlx_ptr, render_next_frame, game);
}
