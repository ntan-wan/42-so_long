/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_free_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 16:53:24 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/10/28 13:58:42 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	sl_free_chests(t_list **chests)
{
	t_list	*ptr_list;
	t_list	*next;
	t_chest	*chest;

	ptr_list = *chests;
	while (ptr_list)
	{
		next = ptr_list->next;
		chest = (t_chest *)ptr_list->content;
		sl_free_anim(&chest->close);
		sl_free_anim(&chest->open);
		sl_free_anim(&chest->shine);
		free(chest);
		free(ptr_list);
		ptr_list = next;
	}
	*chests = NULL;
}

void	sl_free_enemies(t_list **enemies)
{
	t_list	*ptr_list;
	t_list	*next;
	t_enemy	*enemy;

	ptr_list = *enemies;
	while (ptr_list)
	{
		next = ptr_list->next;
		enemy = (t_enemy *)ptr_list->content;
		sl_free_anim(&enemy->idle_left);
		sl_free_anim(&enemy->idle_right);
		sl_free_anim(&enemy->move_left);
		sl_free_anim(&enemy->move_right);
		free(enemy);
		free(ptr_list);
		ptr_list = next;
	}
	*enemies = NULL;
}

void	sl_free_door(t_door **door)
{
	if (*door)
	{
		sl_free_anim(&(*door)->closed);
		sl_free_anim(&(*door)->open);
		sl_free_anim(&(*door)->opened);
		free(*door);
		*door = NULL;
	}
}

void	sl_free_player(t_player **player)
{
	if (*player)
	{
		sl_free_anim(&(*player)->move_right);
		sl_free_anim(&(*player)->move_left);
		sl_free_anim(&(*player)->idle_right);
		sl_free_anim(&(*player)->idle_left);
		free(*player);
		*player = NULL;
	}
}

void	sl_free_map(void *mlx, t_map **map)
{
	if ((*map)->width || (*map)->height)
	{
		ft_lstclear(&(*map)->data, free);
		(*map)->data = NULL;
	}
	if ((*map)->outline)
	{
		mlx_destroy_image(mlx, (*map)->outline->img);
		free((*map)->outline);
		(*map)->outline = NULL;
	}
	free(*map);
	*map = NULL;
}
