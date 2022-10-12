/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_map_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 11:05:08 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/10/12 19:40:00 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	sl_map_open_fd(t_game *g, char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		sl_exit_free_msg(g, "open_fd: unable to read map\n", EXIT_FAILURE);
	else if (ft_strncmp(".ber", ft_substr(path, ft_strlen(path) - 4, 4), 4))
		sl_exit_free_msg(g, "open_fd: wrong file extension", EXIT_FAILURE);
	return (fd);
}

static void	sl_map_get_data(t_map *map, int fd)
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

static int	sl_map_is_surrounded(t_map *map)
{
	int		x;
	int		y;
	char	c;
	t_list	*map_data;

	y = 0;
	map_data = map->data;
	while (map_data)
	{
		x = 0;
		while (((char *)map_data->content)[x])
		{
			c = ((char *)map_data->content)[x];
			if ((y == 0 || y == map->height - 1) && (c != '1' && c != '\n'))
				return (0);
			else if ((x == 0 || x == ft_strlen((char *)map_data->content) - 2)
				&& c != '1')
				return (0);
			x++;
		}
		map_data = map_data->next;
		y++;
	}
	return (1);
}

/*
	rect = rectangle
  */
static int	sl_map_is_rect(t_map *map)
{
	int		width;
	t_list	*map_data;

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
	return (1);
}

void	sl_map_setup(t_game *g, char *path)
{
	int		fd;
	char	*buffer;

	fd = sl_map_open_fd(g, path);
	sl_map_get_data(g->map, fd);
	if (!sl_map_is_surrounded(g->map))
		sl_exit_free_msg(g, "map_setup: map not surrounded\n", EXIT_FAILURE);
	else if (!sl_map_is_rect(g->map))
		sl_exit_free_msg(g, "map_setup: map is not rectangular\n", EXIT_FAILURE);
	g->map->img = sl_img_new(g->mlx, g->map->width * SPRITE_SIZE,
			g->map->height * SPRITE_SIZE);
	sl_map_parse_data(g, sl_map_parse_character);
	close(fd);
}
