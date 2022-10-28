/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_grid_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 14:11:11 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/10/26 14:27:24 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	sl_print_grid(t_grid **grid, int map_width, int map_height)
{
	int	i;
	int	j;

	i = -1;
	while (++i < map_height)
	{
		j = -1;
		while (++j < map_width)
			ft_printf("%d| ", grid[i][j].visited);
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
