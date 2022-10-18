/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_map_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 11:05:08 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/10/18 19:07:34 by ntan-wan         ###   ########.fr       */
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

/* 
	- return (map->width) instead of return (1).
	If map_data is null, map->width will remain as 0 and become 'false'.
	If map_data is not null, map->width will be manipulated and become 'true'.	
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
	return (map->width);
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

void	sl_map_check_missing_char(t_game *g)
{
	if (g->player->x == 0 || g->player->y == 0)
		sl_exit_free_msg(g, "'P' is missing\n", EXIT_FAILURE);
	else if (g->door->x == 0 || g->player->y == 0)
		sl_exit_free_msg(g, "'E' is missing\n", EXIT_FAILURE);
	else if (g->chest == NULL)
		sl_exit_free_msg(g, "'C' is missing\n", EXIT_FAILURE);
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
	else if (sl_map_is_dup_char(g->map))
		sl_exit_free_msg(g, "map_setup: more than 1 start/exit\n", EXIT_FAILURE);
	sl_map_parse_data(g, sl_map_parse_character);
	sl_map_check_missing_char(g);
	close(fd);
}
