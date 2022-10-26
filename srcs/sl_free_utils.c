/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_free_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 16:53:24 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/10/26 14:01:15 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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
		sl_free_anim(&(*player)->idle_left);
		sl_free_anim(&(*player)->idle_right);
		sl_free_anim(&(*player)->move_left);
		sl_free_anim(&(*player)->move_right);
		free(*player);
		*player = NULL;
	}
}

void	sl_free_map(void *mlx, t_map **map)
{
	if ((*map)->outline)
		mlx_destroy_image(mlx, (*map)->outline->img);
	ft_lstclear(&(*map)->data, free);
	free((*map)->wall);
	free((*map)->floor);
	free((*map)->outline);
	free(*map);
	*map = NULL;
}

void	sl_free_map_data_grid(t_grid **grid)
{
	int	i;
	
	i = -1;
	while (grid[++i])
		free(grid[i]);
	free(grid);
}