/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_gui_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 10:40:09 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/10/22 03:20:32 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#define WHITE 0xFFFFFF

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

void	sl_gui_display_collected(t_game *g)
{
	char	*collected;
	char	*chest_total;

	collected = ft_itoa(g->player->collected);
	chest_total = ft_itoa(ft_lstsize(g->chests));
	mlx_string_put(g->mlx, g->win, SPRITE_SIZE, 2 * SPRITE_SIZE, WHITE, "collect :");
	mlx_string_put(g->mlx, g->win, 2 * SPRITE_SIZE, 2 * SPRITE_SIZE, WHITE, collected);
	mlx_string_put(g->mlx, g->win, 3 * SPRITE_SIZE, 2 * SPRITE_SIZE, WHITE, "/");
	mlx_string_put(g->mlx, g->win, 4 * SPRITE_SIZE, 2 * SPRITE_SIZE, WHITE, chest_total);
	free(collected);
	free(chest_total);
}

void	sl_gui_put_movecount(t_img  *buffer, t_img *imgs, int n, int flag)
{
	static int	x;
	char		*number_key;
	
	if (flag)
		x = 0;
	if (n >= 10)
		sl_gui_put_movecount(buffer, imgs, n / 10, 0);
	number_key = ft_itoa(n % 10);
	sl_copy_img(buffer, sl_img_search(number_key, imgs), x * SPRITE_SIZE, 0);
	free(number_key);
	x++;
}

void	sl_gui_put_collcount(t_img  *buffer, t_img *imgs, int n, int flag)
{
	static int	x;
	char		*number_key;
	
	if (flag)
		x = 0;
	if (n >= 10)
		sl_gui_put_movecount(buffer, imgs, n / 10, 0);
	number_key = ft_itoa(n % 10);
	sl_copy_img(buffer, sl_img_search(number_key, imgs), x * SPRITE_SIZE, SPRITE_SIZE);
	free(number_key);
	x++;
}

void	sl_gui_copy_imgs(t_img *buffer, t_game *g)
{
	sl_gui_put_movecount(buffer, g->imgs, g->player->move_count, 1);
	sl_gui_put_collcount(buffer, g->imgs, g->player->collected, 1);
}

void	sl_gui_load_imgs(void *mlx, t_img **imgs)
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
}