/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_map_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 11:05:08 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/10/08 16:29:33 by ntan-wan         ###   ########.fr       */
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
		sl_exit_free(game, "map_open_fd:", EXIT_SUCCESS);
		// sl_exit("map_open_fd: unable to read map\n", 2, EXIT_FAILURE);
	else if (ft_strncmp(".ber", ft_substr(path, ft_strlen(path) - 4, 4), 4))
		sl_exit("map_open_fd: wrong file extension\n", 2, EXIT_FAILURE);
	return (fd);
}

void	*sl_map_data_new(char *str)
{
	int		str_len;	
	void	*buffer;

	str_len = ft_strlen(str);
	buffer = malloc((str_len + 1) * sizeof(char));
	ft_memcpy(buffer, str, str_len + 1);
	return (buffer);
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


void	sl_map_get_data(t_game *game, char *path, t_map *map)
{
	int		fd;
	char	*buffer;

	fd = sl_map_open_fd(game, path);
	buffer = get_next_line(fd);
	while (buffer)
	{
		map->height++;
		ft_lstadd_back(&map->data, ft_lstnew(buffer));
		buffer = get_next_line(fd);
	}
	map->width = ft_strlen(map->data->content) - 1;
	close(fd);
}

void	sl_parse_map(t_game *g)
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
			sl_map_parse_character(g, ((char *)map_data->content)[x], x, y);
		map_data = map_data->next;
	}
}
