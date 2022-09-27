/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_free_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 16:53:24 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/09/27 11:06:51 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	sl_free_img(void *mlx, t_img **head)
{
	t_img	*ptr_img;
	t_img	*tmp;

	ptr_img = *head;
	while (ptr_img)
	{
		tmp = ptr_img->next;
		mlx_destroy_image(mlx, ptr_img->img);
		free(ptr_img->key);
		free(ptr_img);
		ptr_img = tmp;
	}
	*head = NULL;
}
void	sl_free_content(t_game *game)
{
	mlx_destroy_display(game->mlx);
	mlx_destroy_window(game->mlx, game->win);
	sl_free_img(game->mlx, &game->player->idle);
	free(game->mlx);
	game->mlx = NULL;
}
