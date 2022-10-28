/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_map_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 20:35:59 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/10/28 11:51:30 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	sl_map_copy_img(t_img *buffer, t_game *g)
{
	sl_copy_img(buffer, g->map->outline,
		(WINDOW_W - SPRITE_SIZE) / 2 - g->player->x,
		(WINDOW_H - SPRITE_SIZE) / 2 - g->player->y);
}

void	sl_map_load_imgs(void *mlx, t_img **imgs, t_map *map)
{	
	map->outline = sl_img_new(mlx, map->width * SPRITE_SIZE,
			map->height * SPRITE_SIZE);
	sl_img_load(mlx, &map->wall, "wall", "sprite/tiles/wall2.xpm");
	sl_img_load(mlx, &map->floor, "floor", "sprite/tiles/floor2.xpm");
	sl_img_add(imgs, map->wall);
	sl_img_add(imgs, map->floor);
}

void	sl_map_parse_character(t_game *g, char c, int x, int y)
{
	if (c == 'C')
		ft_lstadd_back(&g->chests,
			ft_lstnew(sl_item_chest_init(x * SPRITE_SIZE, y * SPRITE_SIZE)));
	else if (c == 'P')
		sl_player_set_coord(g->player, x * SPRITE_SIZE, y * SPRITE_SIZE);
	else if (c == 'E')
		sl_door_set_coord(g->door, x * SPRITE_SIZE, y * SPRITE_SIZE);
	else if (c == 'Y')
		ft_lstadd_back(&g->enemies,
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
	// else
		// sl_exit_free_msg(g, "map_parse_image: invalid char\n", EXIT_FAILURE);
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
