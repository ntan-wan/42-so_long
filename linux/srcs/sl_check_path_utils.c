/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_check_path_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 13:32:18 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/10/27 18:10:31 by ntan-wan         ###   ########.fr       */
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

void	sl_check_path_door(t_game *g)
{
	t_grid		**grid;
	t_path_data	*path_data;

	grid = sl_map_data_to_grid(g->map);
	path_data = path_data_init(grid, g->door->x, g->door->y);
	sl_algo_check_path_door(path_data, g->player->x, g->player->y);
	if (!path_data->valid)
	{
		free(path_data);
		sl_free_map_data_grid(grid);
		sl_exit_free_msg(g, "check_path_door: invalid_path\n", EXIT_FAILURE);
	}
	sl_free_map_data_grid(grid);
	free(path_data);
}

void	sl_check_path_chests(t_game *g)
{
	t_chest			*c;
	t_grid			**grid;
	t_list			*chest;
	t_path_data		*path_data;

	chest = g->chests;
	grid = sl_map_data_to_grid(g->map);
	while (chest)
	{
		c = (t_chest *)chest->content;
		path_data = path_data_init(grid, c->x, c->y);
		sl_algo_check_path_chest(path_data, g->player->x, g->player->y);
		sl_grid_reset(grid, g->map->width, g->map->height);
		if (!path_data->valid)
		{
			ft_printf("check_path_chests: invalid path to (%d, %d)\n",
				c->x / SPRITE_SIZE, c->y / SPRITE_SIZE);
			free(path_data);
			sl_free_map_data_grid(grid);
			sl_exit_free_msg(g, "", EXIT_FAILURE);
		}
		chest = chest->next;
		free(path_data);
	}
	sl_free_map_data_grid(grid);
}
