/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_free_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 16:53:24 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/10/03 17:23:05 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	sl_free_imgs(void *mlx, t_img **head)
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

static void	sl_free_anim(t_anim **anim)
{
	ft_lstclear(&(*anim)->frames, free);
	free(*anim);
	*anim = NULL;
}

static void	sl_free_player(t_player **player)
{
	if (*player)
	{
		sl_free_anim(&(*player)->idle_left);
		sl_free_anim(&(*player)->idle_right);
		sl_free_anim(&(*player)->move_left);
		sl_free_anim(&(*player)->move_right);
		free(*player);
	}
	*player = NULL;
}

static void sl_free_item_chest(t_chest **chest)
{
	if (*chest)
	{
		sl_free_anim(&(*chest)->open);
		sl_free_anim(&(*chest)->close);
		ft_lstclear(&(*chest)->coords, free);
		free(*chest);
	}
	*chest = NULL;
}

void	sl_free_content(t_game *game)
{
	if (game)
	{
		mlx_destroy_display(game->mlx);
		mlx_destroy_window(game->mlx, game->win);
		sl_free_imgs(game->mlx, &game->imgs);
		sl_free_player(&game->player);
		sl_free_item_chest(&game->chest);
		free(game->mlx);
		game->mlx = NULL;
	}
}
