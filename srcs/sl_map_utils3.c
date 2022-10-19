/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_map_utils3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 19:06:13 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/10/19 13:23:19 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/* 
	- return (y) instead of return (1).
	If map_data is null, y will remain as 0 and become 'false'.
	If map_data is not null, y will be manipulated and become 'true'.	
 */
int	sl_map_is_surrounded(t_map *map)
{
	int		x;
	int		y;
	char	c;
	t_list	*map_data;
	char	*data;

	y = -1;
	map_data = map->data;
	while (map_data)
	{
		++y;
		x = -1;
		data = (char *)map_data->content;
		while (data[++x])
		{
			c = data[x];
			if ((y == 0 || y == map->height - 1) && (c != '1' && c != '\n'))
				return (0);
			else if ((x == 0 || x == (int)ft_strlen(data) - 2)
				&& c != '1')
				return (0);
		}
		map_data = map_data->next;
	}
	return (y);
}

/*
	- rect = rectangle
	- return (width) instead of return (1).
	If map_data is null, width will remain as 0 and become 'false'.
	If map_data is not null, width will be manipulated and become 'true'.	
  */
int	sl_map_is_rect(t_map *map)
{
	int		width;
	t_list	*map_data;

	width = 0;
	map_data = map->data;
	while (map_data)
	{
		if (ft_strchr((char *)map_data->content, '\n'))
				width = ft_strlen((char *)map_data->content) - 1;
		else
			width = ft_strlen((char *)map_data->content);
		if (width != map->width || map->width == map->height)
			return (0);
		map_data = map_data->next;
	}
	return (width);
}

int	sl_map_is_dup_char(t_map *map)
{
	int		x;
	int		count;
	t_list	*map_data;

	count = 0;
	map_data = map->data;
	while (map_data)
	{
		x = -1;
		while (((char *)map_data->content)[++x])
			if (((char *)map_data->content)[x] == 'P'
				|| ((char *)map_data->content)[x] == 'E')
				count++;
		map_data = map_data->next;
	}
	return (count > 2);
}

void	sl_map_check_missing_char(t_game *g)
{
	if (g->player->x == 0 || g->player->y == 0)
		sl_exit_free_msg(g, "'P' is missing\n", EXIT_FAILURE);
	else if (g->door->x == 0 || g->player->y == 0)
		sl_exit_free_msg(g, "'E' is missing\n", EXIT_FAILURE);
	else if (g->chests == NULL)
		sl_exit_free_msg(g, "'C' is missing\n", EXIT_FAILURE);
}
