/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_map_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 20:35:59 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/10/18 19:44:53 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	sl_map_init(t_map **map)
{
	t_map	*new_map;

	new_map = (t_map *)malloc(sizeof(t_map));
	if (new_map)
	{
		new_map->width = 0;
		new_map->height = 0;
		new_map->outline = NULL;
		new_map->wall = NULL;
		new_map->floor = NULL;
		new_map->data = NULL;
	}
	else
		ft_printf("map_init: init failed\n");
	*map = new_map;
}

void	sl_map_copy_img(t_img *buffer, t_game *g)
{
	sl_copy_img(buffer, g->map->outline,
		(WINDOW_W - SPRITE_SIZE) / 2 - g->player->x,
		(WINDOW_H - SPRITE_SIZE) / 2 - g->player->y);
}

void	sl_map_parse_character(t_game *g, char c, int x, int y)
{
	if (c == 'C')
	 	sl_chest_add(&g->chests,
			ft_lstnew(sl_chest_init(x * SPRITE_SIZE, y * SPRITE_SIZE)));
		// sl_item_chest_add(&g->chest,
			// sl_item_chest_new(x * SPRITE_SIZE, y * SPRITE_SIZE));
	else if (c == 'P')
		sl_player_set_coord(g->player, x * SPRITE_SIZE, y * SPRITE_SIZE);
	else if (c == 'E')
		sl_door_set_coord(g->door, x * SPRITE_SIZE, y * SPRITE_SIZE);
	else if (c == 'Y')
		sl_enemy_add(&g->enemies,
			ft_lstnew(sl_enemy_init(x * SPRITE_SIZE, y * SPRITE_SIZE)));
}

void	sl_map_parse_image(t_game *g, char c, int x, int y)
{
	if (c == '1')
		sl_copy_img(g->map->outline, sl_img_search("wall", g->imgs),
			x * SPRITE_SIZE, y * SPRITE_SIZE);
	else if (ft_strchr("0CPEY\n", c))
		sl_copy_img(g->map->outline, sl_img_search("floor", g->imgs),
			x * SPRITE_SIZE, y * SPRITE_SIZE);
	else
		sl_exit_free_msg(g, "map_parse_image: invalid char\n", EXIT_FAILURE);
}

void	sl_map_parse_data(t_game *g, void (*f)(t_game *, char, int, int))
{
	int		x;
	int		y;
	t_list	*map_data;

	y = -1;
	map_data = g->map->data;
	while (map_data)
	{
		++y;
		x = -1;
		while (((char *)map_data->content)[++x])
			f(g, ((char *)map_data->content)[x], x, y);
		map_data = map_data->next;
	}
}
