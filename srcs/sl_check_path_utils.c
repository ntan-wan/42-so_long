/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_check_path_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 13:32:18 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/10/27 12:15:39 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static t_path_data	*path_data_init(t_grid **grid, int o_x, int o_y)
{
	t_path_data	*new_path_data;

	new_path_data = (t_path_data *)malloc(sizeof(t_path_data));
	if (new_path_data)
	{
		new_path_data->grid = grid;
		new_path_data->o_x = o_x;
		new_path_data->o_y = o_y;
		new_path_data->valid = 0;
	}
	return (new_path_data);
}

static void	sl_algo_check_path_door(t_path_data *path_data, int p_x, int p_y)
{
	int			x_index;
	int			y_index;
	t_grid		grid_item;

	x_index = p_x / SPRITE_SIZE;
	y_index = p_y / SPRITE_SIZE;
	grid_item = (path_data->grid)[y_index][x_index];
	if (p_x == path_data->o_x && p_y == path_data->o_y)
		path_data->valid = 1;
	else if (grid_item.content == '1' || grid_item.visited)
		return ;
	else if (grid_item.visited != 1)
		(path_data->grid)[y_index][x_index].visited = 1;
	sl_algo_check_path_door(path_data, p_x + SPRITE_SIZE, p_y);
	sl_algo_check_path_door(path_data, p_x - SPRITE_SIZE, p_y);
	sl_algo_check_path_door(path_data, p_x, p_y + SPRITE_SIZE);
	sl_algo_check_path_door(path_data, p_x, p_y - SPRITE_SIZE);
}

void	sl_check_path_door(t_map *map, t_player *p, t_door *d)
{
	t_grid		**grid;
	t_path_data	*path_data;

	grid = sl_map_data_to_grid(map);
	path_data = path_data_init(grid, d->x, d->y);
	sl_algo_check_path_door(path_data, p->x, p->y);
	if (!path_data->valid)
		sl_exit_msg("check_path_door: invalid path\n", EXIT_FAILURE);
	sl_free_map_data_grid(grid);
	free(path_data);
}

static void	sl_algo_check_path_chest(t_path_data *path_data, int p_x, int p_y)
{
	int		x_index;
	int		y_index;
	t_grid	grid_item;

	x_index = p_x / SPRITE_SIZE;
	y_index = p_y / SPRITE_SIZE;
	grid_item = (path_data->grid)[y_index][x_index];
	if (p_x == path_data->o_x && p_y == path_data->o_y)
		path_data->valid = 1;
	else if (grid_item.content == '1'
		|| grid_item.content == 'E' || grid_item.visited)
		return ;
	else if (grid_item.visited != 1)
		(path_data->grid)[y_index][x_index].visited = 1;
	sl_algo_check_path_chest(path_data, p_x + SPRITE_SIZE, p_y);
	sl_algo_check_path_chest(path_data, p_x - SPRITE_SIZE, p_y);
	sl_algo_check_path_chest(path_data, p_x, p_y + SPRITE_SIZE);
	sl_algo_check_path_chest(path_data, p_x, p_y - SPRITE_SIZE);
}

void	sl_check_path_chests(t_map *map, t_player *p, t_list *chests)
{
	t_chest			*c;
	t_grid			**grid;
	t_list			*chest;
	t_path_data		*path_data;

	chest = chests;
	grid = sl_map_data_to_grid(map);
	while (chest)
	{
		c = (t_chest *)chest->content;
		path_data = path_data_init(grid, c->x, c->y);
		sl_algo_check_path_chest(path_data, p->x, p->y);
		sl_grid_reset(grid, map->width, map->height);
		if (!path_data->valid)
		{
			ft_printf("x = %d, y = %d\n",
				c->x / SPRITE_SIZE, c->y / SPRITE_SIZE);
			sl_exit_msg("check_path_chests: invalid path\n", EXIT_FAILURE);
		}
		chest = chest->next;
		free(path_data);
	}
	sl_free_map_data_grid(grid);
}
