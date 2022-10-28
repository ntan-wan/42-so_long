/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_gui_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 08:54:16 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/10/28 18:33:52 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	sl_movecount_check(int curr_count, int prev_count, int *move_count)
{
	if (curr_count == 0 && curr_count != prev_count)
	{
		(*move_count)++;
		ft_printf("move_count: %d\n", *move_count);
	}
}

void	sl_gui_update_movecount(t_game *g)
{
	int			curr_count_x;	
	int			curr_count_y;
	static int	prev_count_x;
	static int	prev_count_y;

	curr_count_x = (g->player->x + (SPRITE_SIZE / 2)) % SPRITE_SIZE;
	curr_count_y = (g->player->y + (SPRITE_SIZE / 2)) % SPRITE_SIZE;
	sl_movecount_check(curr_count_x, prev_count_x, &g->player->move_count);
	sl_movecount_check(curr_count_y, prev_count_y, &g->player->move_count);
	prev_count_x = curr_count_x;
	prev_count_y = curr_count_y;
}

t_img	*sl_gui_get_gold_num(int n, t_img *imgs)
{
	if (n == 0)
		return (sl_img_search("0_gold", imgs));
	else if (n == 1)
		return (sl_img_search("1_gold", imgs));
	else if (n == 2)
		return (sl_img_search("2_gold", imgs));
	else if (n == 3)
		return (sl_img_search("3_gold", imgs));
	else if (n == 4)
		return (sl_img_search("4_gold", imgs));
	else if (n == 5)
		return (sl_img_search("5_gold", imgs));
	else if (n == 6)
		return (sl_img_search("6_gold", imgs));
	else if (n == 7)
		return (sl_img_search("7_gold", imgs));
	else if (n == 8)
		return (sl_img_search("8_gold", imgs));
	else
		return (sl_img_search("9_gold", imgs));
}

void	sl_gui_load_num_imgs(void *mlx, t_img **imgs)
{
	sl_img_load(mlx, imgs, "0", "sprite/nums/0.xpm");
	sl_img_load(mlx, imgs, "1", "sprite/nums/1.xpm");
	sl_img_load(mlx, imgs, "2", "sprite/nums/2.xpm");
	sl_img_load(mlx, imgs, "3", "sprite/nums/3.xpm");
	sl_img_load(mlx, imgs, "4", "sprite/nums/4.xpm");
	sl_img_load(mlx, imgs, "5", "sprite/nums/5.xpm");
	sl_img_load(mlx, imgs, "6", "sprite/nums/6.xpm");
	sl_img_load(mlx, imgs, "7", "sprite/nums/7.xpm");
	sl_img_load(mlx, imgs, "8", "sprite/nums/8.xpm");
	sl_img_load(mlx, imgs, "9", "sprite/nums/9.xpm");
	sl_img_load(mlx, imgs, "0_gold", "sprite/nums/0_gold.xpm");
	sl_img_load(mlx, imgs, "1_gold", "sprite/nums/1_gold.xpm");
	sl_img_load(mlx, imgs, "2_gold", "sprite/nums/2_gold.xpm");
	sl_img_load(mlx, imgs, "3_gold", "sprite/nums/3_gold.xpm");
	sl_img_load(mlx, imgs, "4_gold", "sprite/nums/4_gold.xpm");
	sl_img_load(mlx, imgs, "5_gold", "sprite/nums/5_gold.xpm");
	sl_img_load(mlx, imgs, "6_gold", "sprite/nums/6_gold.xpm");
	sl_img_load(mlx, imgs, "7_gold", "sprite/nums/7_gold.xpm");
	sl_img_load(mlx, imgs, "8_gold", "sprite/nums/8_gold.xpm");
	sl_img_load(mlx, imgs, "9_gold", "sprite/nums/9_gold.xpm");
}

void	sl_gui_load_char_imgs(void *mlx, t_img **imgs)
{
	sl_img_load(mlx, imgs, "E", "sprite/char/E.xpm");
	sl_img_load(mlx, imgs, "S", "sprite/char/S.xpm");
	sl_img_load(mlx, imgs, "C", "sprite/char/C.xpm");
	sl_img_load(mlx, imgs, "A", "sprite/char/A.xpm");
	sl_img_load(mlx, imgs, "P", "sprite/char/P.xpm");
	sl_img_load(mlx, imgs, "!", "sprite/char/exclamation.xpm");
	sl_img_load(mlx, imgs, "feet_icon", "sprite/icons/feet.xpm");
}
