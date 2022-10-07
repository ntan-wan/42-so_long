/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_map_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 11:05:08 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/10/07 15:34:39 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	sl_map_init(t_map **map)
{
	t_map   *new_map;

	new_map = (t_map *)malloc(sizeof(t_map));
	if (new_map)
	{
		new_map->data = NULL;
		new_map->width = 0;
		new_map->height = 0;
	}
	else
		ft_printf("map_init: init failed\n");
	*map = new_map;
}

int	sl_map_open_fd(char *path)
{
	int	fd;
	
	fd = open(path, O_RDONLY);
	if (fd == -1)
		sl_exit("map_open_fd: unable to read map\n", 2, EXIT_FAILURE);
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

void	sl_map_parse(t_map *map, char *path)
{
	int 	fd;
	char	*buffer;

   if (!map)
		return ;
	fd = sl_map_open_fd(path);
	printf("testing\n");
	buffer = get_next_line(fd);
	//buffer = NULL;
	while (buffer)
	{
		map->height++;
		//ft_lstadd_back(&map->data, ft_lstnew(sl_map_data_new(buffer)));
		free(buffer);
		buffer = get_next_line(fd);
	}
	close(fd);
	//map->width = ft_strlen(map->data->content);
	//ft_lstclear(&map->data, free);
}