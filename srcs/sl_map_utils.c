/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_map_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 11:05:08 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/10/28 13:27:51 by ntan-wan         ###   ########.fr       */
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

/* 
	- return (map->width + map->height) instead of return (1).
	If map_data is null, map->width + height will remain as 0 and become 'false'.
	If map_data is not null, map->width + height will be manipulated and become 'true'.	
 */
static int	sl_map_get_data(t_map *map, int fd)
{
	char	*buffer;

	buffer = get_next_line(fd);
	while (buffer)
	{
		map->height++;
		ft_lstadd_back(&map->data, ft_lstnew(buffer));
		buffer = get_next_line(fd);
	}
	if (map->data)
		map->width = ft_strlen(map->data->content) - 1;
	return (map->width + map->height);
}

static void	sl_map_open_fd(t_game *g, char *path)
{
	int		fd;
	char	*file_extension;

	fd = open(path, O_RDONLY);
	file_extension = ft_substr(path, ft_strlen(path)- 4, 4);
	if (ft_strncmp(".ber", file_extension, 4))
		sl_exit_free_msg(g, "open_fd: wrong file extension\n", EXIT_FAILURE);
	else if (fd == -1)
		sl_exit_free_msg(g, "open_fd: unable to read map\n", EXIT_FAILURE);
	else if (!sl_map_get_data(g->map, fd))
		sl_exit_free_msg(g, "map_check: map is empty\n", EXIT_FAILURE);
	free(file_extension);
	close(fd);
}

int	sl_is_invalid_char(t_map *map)
{
	int		x;
	int		y;
	char	*str;
	t_list	*map_data;

	y = -1;
	map_data = map->data;
	while (map_data)
	{
		++y;
		x = -1;
		str = (char *)map_data->content;
		while (str[++x])
		{
			if (!ft_strchr("10PECY\n", str[x]))	
				return (1);
		}
		map_data = map_data->next;
	}
	return (0);
}

static void	sl_map_error_check(t_game *g)
{
	if (!sl_map_is_rect(g->map))
		sl_exit_free_msg(g, "map_check: map is not rectangular\n", EXIT_FAILURE);
	else if (!sl_map_is_surrounded(g->map))
		sl_exit_free_msg(g, "map_check: not surrounded by wall\n", EXIT_FAILURE);
	else if (sl_map_is_dup_char(g->map))
		sl_exit_free_msg(g, "map_check: more than 1 start/exit\n", EXIT_FAILURE);
	else if (sl_is_invalid_char(g->map))
		sl_exit_free_msg(g, "map_check: invalid char\n", EXIT_FAILURE);
}

void	sl_map_setup(t_game *g, char *path)
{
	sl_map_open_fd(g, path);
	sl_map_error_check(g);
	sl_map_parse_data(g, sl_map_parse_character);
	sl_map_check_missing_char(g);
	sl_check_path_door(g);
	sl_check_path_chests(g);
}
