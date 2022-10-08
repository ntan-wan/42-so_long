/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_map_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 11:05:08 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/10/09 00:03:06 by ntan-wan         ###   ########.fr       */
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
		new_map->img = NULL;
		new_map->data = NULL;
	}
	else
		ft_printf("map_init: init failed\n");
	*map = new_map;
}

int	sl_map_open_fd(t_game *game, char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		sl_exit_msg(game, "open_fd: unable to read map\n", EXIT_FAILURE);
	else if (ft_strncmp(".ber", ft_substr(path, ft_strlen(path) - 4, 4), 4))
		sl_exit_msg(game, "open_fd: wrong file extension", EXIT_FAILURE);
	return (fd);
}

void	sl_map_parse_character(t_game *g, char c, int x, int y)
{
	if (c == 'C')
		sl_item_chest_add(&g->chest,
			sl_item_chest_new(x * SPRITE_SIZE, y * SPRITE_SIZE));
	else if (c == 'P')
		sl_player_set_coord(g->player, x * SPRITE_SIZE, y * SPRITE_SIZE);
	else if (c == 'E')
		sl_door_set_coord(g->door, x * SPRITE_SIZE, y * SPRITE_SIZE);
}

void	sl_map_get_data(t_map *map, int fd)
{
	char	*buffer;

	buffer = get_next_line(fd);
	while (buffer)
	{
		map->height++;
		ft_lstadd_back(&map->data, ft_lstnew(buffer));
		buffer = get_next_line(fd);
	}
	map->width = ft_strlen(map->data->content) - 1;
}

void	sl_map_parse_image(t_game *g, char c, int x, int y)
{
	if (c == '1')
		sl_copy_img(g->map->img, sl_img_search("wall", g->imgs),
		x * SPRITE_SIZE, y * SPRITE_SIZE);
	else if (ft_strchr("0CPE", c))
		sl_copy_img(g->map->img, sl_img_search("floor", g->imgs),
		x * SPRITE_SIZE, y * SPRITE_SIZE);
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

void	sl_parse_map(t_game *g, char *path)
{
	int	fd;

	fd = sl_map_open_fd(g, path);
	sl_map_get_data(g->map, fd);
	g->map->img = (t_img *)malloc(sizeof (t_img));
	g->map->img->next = NULL;
	g->map->img->height = g->map->height * SPRITE_SIZE;
	g->map->img->width = g->map->width * SPRITE_SIZE;
	g->map->img->key = "map";
	g->map->img->img = mlx_new_image(g->mlx, g->map->width * SPRITE_SIZE,
		g->map->height * SPRITE_SIZE);
	// printf("%d\n", g->map->width);
	// printf("%d\n", g->map->height);
	sl_map_parse_data(g, sl_map_parse_character);
	close(fd);
}
