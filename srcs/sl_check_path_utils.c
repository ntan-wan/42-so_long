/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_check_path_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 13:32:18 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/10/26 14:07:27 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#define VISITED 'X'

void	sl_print_grid(t_grid **grid, int map_width, int map_height)
{
	int	i;
	int	j;

	i = -1;
	while (++i < map_height)
	{
		j = -1;
		while (++j < map_width)
			ft_printf("%c %d| ", grid[i][j].content, grid[i][j].visited);
		ft_printf("\n");
	}
}

void	sl_grid_reset(t_grid **grid, int map_width, int map_height)
{
	int	i;
	int	j;

	i = -1;
	while (++i < map_height)
	{
		j = -1;
		while (++j < map_width)
		{
			if (grid[i][j].visited)
				grid[i][j].visited = 0;
		}
	}
}

t_grid	**sl_map_data_to_grid(t_map *map)
{
	int		i;
	int		j;
	t_grid	**grid;
	t_list	*map_data;
	
	map_data = map->data;
	grid = (t_grid **)malloc(sizeof(t_grid *) * (map->height + 1));
	grid[map->height] = NULL;
	i = -1;
	while (++i < map->height)
	{
		j = -1;
		grid[i] = (t_grid *)malloc(sizeof(t_grid) * (map->width + 1));
		while (++j < map->width)
		{
			grid[i][j].content = ((char *)map_data->content)[j];
			grid[i][j].visited = 0;
		}
		grid[i][map->width] = (t_grid){.content = '\0', .visited = 0};
		map_data = map_data->next;
	}
	return (grid);
}

int	sl_is_valid_path(t_grid **grid, int p_x, int p_y, int o_x, int o_y)
{
	int 		x_index;
	int			y_index;
	static int	valid = 0;

	x_index = p_x / SPRITE_SIZE;
	y_index = p_y / SPRITE_SIZE;
	if (p_x == o_x && p_y == o_y)
		return (valid += 1);
	else if (grid[y_index][x_index].content == '1' || grid[y_index][x_index].visited == 1)
		return (valid);
	else if (grid[y_index][x_index].visited != 1)
		grid[y_index][x_index].visited = 1;
	sl_is_valid_path(grid, p_x + SPRITE_SIZE, p_y, o_x, o_y);
	sl_is_valid_path(grid, p_x - SPRITE_SIZE, p_y, o_x, o_y);
	sl_is_valid_path(grid, p_x, p_y + SPRITE_SIZE, o_x, o_y);
	sl_is_valid_path(grid, p_x, p_y - SPRITE_SIZE, o_x, o_y);
	return (valid);
}

void	sl_check_exit_path(t_map *map, t_player *p, t_door *d)
{
	t_grid **grid;

	grid = sl_map_data_to_grid(map);
	if(!sl_is_valid_path(grid, p->x, p->y, d->x, d->y))
		sl_exit_msg("check_exit_path: invalid path\n", EXIT_FAILURE);
	sl_free_map_data_grid(grid);
}