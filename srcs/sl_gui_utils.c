/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_gui_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 10:40:09 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/10/22 19:00:28 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	sl_gui_put_movecount(t_img *buffer, t_img *imgs, int n, int flag)
{
	static int	x;
	char		*number_key;

	if (flag)
		x = 0;
	if (n >= 10)
		sl_gui_put_movecount(buffer, imgs, n / 10, 0);
	number_key = ft_itoa(n % 10);
	sl_copy_img(buffer, sl_img_search(number_key, imgs),
		x * (SPRITE_SIZE - IMG_GAP_X), SPRITE_SIZE - IMG_GAP_Y);
	free(number_key);
	x++;
}

static void	sl_gui_put_collcount(t_img *buffer, t_img *imgs, int n, int flag)
{
	static int	x;

	if (flag)
		x = 0;
	if (n >= 10)
		sl_gui_put_collcount(buffer, imgs, n / 10, 0);
	sl_copy_img(buffer, sl_gui_get_gold_num(n % 10, imgs),
		x * (SPRITE_SIZE - IMG_GAP_X), 0);
	x++;
}

static void	sl_gui_put_escape(t_img *buffer, t_img *imgs)
{
	sl_copy_img(buffer, sl_img_search("E", imgs), 0, 0);
	sl_copy_img(buffer, sl_img_search("S", imgs),
		1 * (SPRITE_SIZE - IMG_GAP_X), 0);
	sl_copy_img(buffer, sl_img_search("C", imgs),
		2 * (SPRITE_SIZE - IMG_GAP_X), 0);
	sl_copy_img(buffer, sl_img_search("A", imgs),
		3 * (SPRITE_SIZE - IMG_GAP_X), 0);
	sl_copy_img(buffer, sl_img_search("P", imgs),
		4 * (SPRITE_SIZE - IMG_GAP_X), 0);
	sl_copy_img(buffer, sl_img_search("E", imgs),
		5 * (SPRITE_SIZE - IMG_GAP_X), 0);
	sl_copy_img(buffer, sl_img_search("!", imgs),
		7 * (SPRITE_SIZE - IMG_GAP_X), 0);
}

void	sl_gui_copy_imgs(t_img *buffer, t_game *g)
{
	int	chest_remaining;

	chest_remaining = ft_lstsize(g->chests) - g->player->collected;
	if (chest_remaining)
		sl_gui_put_collcount(buffer, g->imgs, chest_remaining, 1);
	else
		sl_gui_put_escape(buffer, g->imgs);
	sl_gui_put_movecount(buffer, g->imgs, g->player->move_count, 1);
}
