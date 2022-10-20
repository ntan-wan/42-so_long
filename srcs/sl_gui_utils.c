/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_gui_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 10:40:09 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/10/20 11:12:12 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void    sl_gui_display(t_game *g)
{
    char    *count_c;
    static int     count;

    count_c = ft_itoa(count);
    if (g->player->action >= 2)
        count++;
    mlx_string_put(g->mlx, g->win, SPRITE_SIZE, SPRITE_SIZE, 0xFFFFFF, "move count: ");
    mlx_string_put(g->mlx, g->win, 2 * SPRITE_SIZE, SPRITE_SIZE, 0xFFFFFF, count_c);
    free(count_c);
}