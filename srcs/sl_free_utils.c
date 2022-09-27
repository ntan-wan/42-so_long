/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_free_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 16:53:24 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/09/26 19:36:04 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	sl_free_img(void *mlx, t_img *frame)
{
	mlx_destroy_image(mlx, frame->img);
	free(frame);
}

static void	sl_free_imgs(void *mlx, t_imgs **head)
{
	t_imgs	*ptr_imgs;
	t_imgs	*tmp;

	ptr_imgs = *head;
	while (ptr_imgs)
	{
		tmp = ptr_imgs->next;
		sl_free_img(mlx, ptr_imgs->frame);
		free(ptr_imgs->key);
		free(ptr_imgs);
		ptr_imgs = tmp;
	}
	*head = NULL;
}
void	sl_free_content(t_game *game)
{
	mlx_destroy_display(game->mlx);
	sl_free_imgs(game->mlx, &game->player->idle);
	mlx_destroy_window(game->mlx, game->win);
	free(game->mlx);
	game->mlx = NULL;
}
