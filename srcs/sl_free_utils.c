/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_free_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 16:53:24 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/10/07 09:03:51 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	sl_free_imgs(void *mlx, t_img **head)
{
	t_img	*ptr_img;
	t_img	*next;

	ptr_img = *head;
	while (ptr_img)
	{
		next = ptr_img->next;
		mlx_destroy_image(mlx, ptr_img->img);
		free(ptr_img);
		ptr_img = next;
	}
	*head = NULL;
}


static void	sl_free_anim(t_anim **anim)
{
	ft_lstclear(&(*anim)->frames, free);
	free(*anim);
	*anim = NULL;
}

static void	sl_free_door(t_door **door)
{
	if (*door)
	{
		sl_free_anim(&(*door)->closed);
		sl_free_anim(&(*door)->open);
		sl_free_anim(&(*door)->opened);
		free(*door);
	}
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

static void	sl_free_item_chest(t_chest **chest)
{
	t_chest	*ptr_chest;
	t_chest	*next;

	ptr_chest = *chest;
	while (ptr_chest)
	{
		next = ptr_chest->next;
		sl_free_anim(&ptr_chest->open);
		sl_free_anim(&ptr_chest->shine);
		sl_free_anim(&ptr_chest->close);
		free(ptr_chest);
		ptr_chest = next;
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
		sl_free_door(&game->door);
		free(game->mlx);
		game->mlx = NULL;
	}
}
