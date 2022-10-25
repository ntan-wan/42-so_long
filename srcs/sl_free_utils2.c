/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_free_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 08:08:45 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/10/25 13:00:45 by ntan-wan         ###   ########.fr       */
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
		free(ptr_img);
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

void	sl_free_content(t_game *g)
{
	if (g)
	{
		sl_free_imgs(g->mlx, &g->imgs);
		mlx_destroy_window(g->mlx, g->win);
		// mlx_destroy_display(g->mlx);
		free(g->mlx);
		g->mlx = NULL;
	}
}
