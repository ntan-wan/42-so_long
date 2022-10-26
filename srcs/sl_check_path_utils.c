/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_check_path_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 13:32:18 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/10/27 07:28:40 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	sl_is_valid_path_door(t_grid **grid, int p_x, int p_y, t_door *d)
{
	int			x_index;
	int			y_index;
	static int	valid;

	x_index = p_x / SPRITE_SIZE;
	y_index = p_y / SPRITE_SIZE;
	if (p_x == d->x && p_y == d->y)
		return (valid += 1);
	else if (grid[y_index][x_index].content == '1'
		|| grid[y_index][x_index].visited)
		return (valid);
	else if (grid[y_index][x_index].visited != 1)
		grid[y_index][x_index].visited = 1;
	sl_is_valid_path_door(grid, p_x + SPRITE_SIZE, p_y, d);
	sl_is_valid_path_door(grid, p_x - SPRITE_SIZE, p_y, d);
	sl_is_valid_path_door(grid, p_x, p_y + SPRITE_SIZE, d);
	sl_is_valid_path_door(grid, p_x, p_y - SPRITE_SIZE, d);
	return (valid);
}

void	sl_check_path_chest(t_grid **grid, int p_x, int p_y, t_chest *c, int *res)
{
	int	x_index;
	int	y_index;
	
	x_index = p_x / SPRITE_SIZE;
	y_index = p_y / SPRITE_SIZE;
	if (p_x == c->x && p_y == c->y)
		*res = 1;
	else if (grid[y_index][x_index].content == '1'
		|| grid[y_index][x_index].content == 'E'
		|| grid[y_index][x_index].visited)
		return ;
	else if (grid[y_index][x_index].visited != 1)
		grid[y_index][x_index].visited = 1;
	sl_check_path_chest(grid, p_x + SPRITE_SIZE, p_y, c, res);
	sl_check_path_chest(grid, p_x - SPRITE_SIZE, p_y, c, res);
	sl_check_path_chest(grid, p_x, p_y + SPRITE_SIZE, c, res);
	sl_check_path_chest(grid, p_x, p_y - SPRITE_SIZE, c, res);
}

int	sl_get_valid_paths_total(t_grid **grid, int p_x, int p_y, t_chest *c)
{
	int	x_index;
	int	y_index;
	static int valid_path;
	
	x_index = p_x / SPRITE_SIZE;
	y_index = p_y / SPRITE_SIZE;
	// if (grid[y_index][x_index].content == 'C')
	if (grid[y_index][x_index].content == '1'
		|| grid[y_index][x_index].content == 'E'
		|| grid[y_index][x_index].visited)
		return (valid_path);
	if (grid[y_index][x_index].visited != 1)
		grid[y_index][x_index].visited = 1;
	if (p_x == c->x && p_y == c->y)
		return (valid_path += 1);
	sl_get_valid_paths_total(grid, p_x + SPRITE_SIZE, p_y, c);
	sl_get_valid_paths_total(grid, p_x - SPRITE_SIZE, p_y, c);
	sl_get_valid_paths_total(grid, p_x, p_y + SPRITE_SIZE, c);
	sl_get_valid_paths_total(grid, p_x, p_y - SPRITE_SIZE, c);
	return (valid_path);
}

void	sl_check_path_door(t_map *map, t_player *p, t_door *d)
{
	t_grid	**grid;

	grid = sl_map_data_to_grid(map);
	if (!sl_is_valid_path_door(grid, p->x, p->y, d))
		sl_exit_msg("check_path_door: invalid path\n", EXIT_FAILURE);
	// sl_print_grid(grid, map->width, map->height);
	sl_free_map_data_grid(grid);
}

void	sl_check_path_chests(t_map *map, t_player *p, t_list *chests)
{
	t_grid	**grid;
	t_chest	*chest;
	int		valid;

	grid = sl_map_data_to_grid(map);
	while (chests)
	{
		valid = 0;
		chest = (t_chest *)chests->content;
		sl_check_path_chest(grid, p->x, p->y, chest, &valid);
		if (!valid)
			sl_exit_msg("path_chest_check: invalid path\n", EXIT_FAILURE);
		sl_grid_reset(grid, map->width, map->height);
		chests = chests->next;
	}
	// sl_print_grid(grid, map->width, map->height);
	sl_free_map_data_grid(grid);
}

void	sl_check_path_chests2(t_map *map, t_player *p, t_list *chests)
{
	t_grid	**grid;
	t_chest	*chest;
	t_list	*ptr_chest;
	int	total;

	// (void)chests;
	grid = sl_map_data_to_grid(map);
	ptr_chest = chests;
	while (ptr_chest)
	{

		chest = (t_chest *)ptr_chest->content;
		total = sl_get_valid_paths_total(grid, p->x, p->y, chest);
		// printf("%d\n", sl_get_valid_paths_total(grid, p->x, p->y, chest));
			// sl_exit_msg("path_chest_check: invalid path\n", EXIT_FAILURE);
		sl_print_grid(grid, map->width, map->height);
		printf("\n");
		sl_grid_reset(grid, map->width, map->height);
		ptr_chest = ptr_chest->next;
	}
	printf("%d\n", total);
	// printf("%d\n", ft_lstsize(chests));
	// sl_print_grid(grid, map->width, map->height);
	if (ft_lstsize(chests) != total)
		sl_exit_msg("path_chest_check: invalid path\n", EXIT_FAILURE);
	sl_free_map_data_grid(grid);
}
