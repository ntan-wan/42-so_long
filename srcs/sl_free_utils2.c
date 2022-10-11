/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_free_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 08:08:45 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/10/11 09:08:41 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	sl_free_imgs(void *mlx, t_img **head)
{
	t_img	*ptr_img;
	t_img	*next;

	ptr_img = *head;
	while (ptr_img)
	{
		next = ptr_img->next;
		mlx_destroy_image(mlx, ptr_img->img);
		ptr_img = next;
	}
	*head = NULL;
}

void	sl_free_anim(t_anim **anim)
{
	ft_lstclear(&(*anim)->frames, free);
	free(*anim);
	*anim = NULL;
}

void	sl_free_content(t_game *game)
{
	if (game)
	{
		sl_free_imgs(game->mlx, &game->imgs);
		mlx_destroy_window(game->mlx, game->win);
		mlx_destroy_display(game->mlx);
		sl_free_player(&game->player);
		sl_free_item_chest(&game->chest);
		sl_free_door(&game->door);
		sl_free_map(&game->map);
		free(game->mlx);
		game->mlx = NULL;
	}
}
