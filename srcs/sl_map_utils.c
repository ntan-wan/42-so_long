/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_map_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 11:05:08 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/10/11 11:22:49 by ntan-wan         ###   ########.fr       */
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
		new_map->img = (t_img *)malloc(sizeof(t_img));
		new_map->data = NULL;
	}
	else
		ft_printf("map_init: init failed\n");
	*map = new_map;
}

int	sl_map_open_fd(t_game *g, char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		sl_exit_msg(g, "open_fd: unable to read map\n", EXIT_FAILURE);
	else if (ft_strncmp(".ber", ft_substr(path, ft_strlen(path) - 4, 4), 4))
		sl_exit_msg(g, "open_fd: wrong file extension", EXIT_FAILURE);
	return (fd);
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

void	sl_map_copy_img(t_img *buffer, t_game *g)
{
	sl_copy_img(buffer, g->map->img,
		(WINDOW_W - SPRITE_SIZE) / 2 - g->player->x,
		(WINDOW_H - SPRITE_SIZE) / 2 - g->player->y);
}

void	sl_map_setup(t_game *g, char *path)
{
	int		fd;
	char	*buffer;

	fd = sl_map_open_fd(g, path);
	sl_map_get_data(g->map, fd);
	g->map->img = sl_img_new(g->mlx, g->map->width * SPRITE_SIZE,
			g->map->height * SPRITE_SIZE);
	sl_map_parse_data(g, sl_map_parse_character);
	close(fd);
}
