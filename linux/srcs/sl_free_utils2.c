/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_free_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 08:08:45 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/10/28 18:51:48 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	sl_free_map_data_grid(t_grid **grid)
{
	int	i;

	i = -1;
	while (grid[++i])
		free(grid[i]);
	free(grid);
}

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
	t_list	*frame;
	t_list	*next;

	frame = (*anim)->frames;
	while (frame)
	{
		next = frame->next;
		free(frame);
		frame = next;
	}
	free(*anim);
	*anim = NULL;
}

/* 
	macOS = XCloseDisplay(((t_xvar *)g->mlx)->display);
	linux = mlx_destroy_display(g->mlx);
 */
void	sl_free_content(t_game *g)
{
	if (g)
	{
		sl_free_imgs(g->mlx, &g->imgs);
		mlx_destroy_window(g->mlx, g->win);
		sl_free_chests(&g->chests);
		sl_free_door(&g->door);
		sl_free_enemies(&g->enemies);
		sl_free_player(&g->player);
		sl_free_map(g->mlx, &g->map);
		mlx_destroy_display(g->mlx);
		free(g->mlx);
		g->mlx = NULL;
	}
}
