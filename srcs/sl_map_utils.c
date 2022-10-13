/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_map_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 11:05:08 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/10/13 14:21:53 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	sl_map_open_fd(t_game *g, char *path)
{
	int		fd;
	char	*file_extension;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		sl_exit_free_msg(g, "open_fd: unable to read map\n", EXIT_FAILURE);
	file_extension = ft_substr(path, ft_strlen(path)- 4, 4);
	if (ft_strncmp(".ber", file_extension, 4))
		sl_exit_free_msg(g, "open_fd: wrong file extension\n", EXIT_FAILURE);
	free(file_extension);
	return (fd);
}

static int	sl_map_get_data(t_map *map, int fd)
{
	char	*buffer;

	buffer = get_next_line(fd);
	if (!buffer)
		return (0);
	while (buffer)
	{
		map->height++;
		ft_lstadd_back(&map->data, ft_lstnew(buffer));
		buffer = get_next_line(fd);
	}
	map->width = ft_strlen(map->data->content) - 1;
	return (1);
}

/* 
	- return (y) instead of return (1).
	If map_data is null, y will remain as 0 and become 'false'.
	If map_data is not null, y will be manipulated and become 'true'.	
 */
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
	return (y);
}

/*
	- rect = rectangle
	- return (width) instead of return (1).
	If map_data is null, width will remain as 0 and become 'false'.
	If map_data is not null, width will be manipulated and become 'true'.	
  */
static int	sl_map_is_rect(t_map *map)
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

void	sl_map_setup(t_game *g, char *path)
{
	int		fd;

	fd = sl_map_open_fd(g, path);
	if (!sl_map_get_data(g->map, fd))
		sl_exit_free_msg(g, "map_setup: map is empty\n", EXIT_FAILURE);
	else if (!sl_map_is_rect(g->map))
		sl_exit_free_msg(g, "map_setup: map is not rectangular\n", EXIT_FAILURE);
	else if (!sl_map_is_surrounded(g->map))
		sl_exit_free_msg(g, "map_setup: not surrounded by wall\n", EXIT_FAILURE);
	g->map->outline = sl_img_new(g->mlx, g->map->width * SPRITE_SIZE,
			g->map->height * SPRITE_SIZE);
	sl_img_load(g->mlx, &g->map->wall, "wall", "sprite/tiles/wall2.xpm");
	sl_img_load(g->mlx, &g->map->floor, "floor", "sprite/tiles/floor2.xpm");
	sl_map_parse_data(g, sl_map_parse_character);
	close(fd);
}
