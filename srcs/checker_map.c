/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chduong <chduong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 12:10:34 by chduong           #+#    #+#             */
/*   Updated: 2021/12/24 15:48:31 by chduong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_bool	is_edge(int x, int y, t_dim limit)
{
	if (y == 0 || y == limit.y - 1)
		return (1);
	else if (x == 0 || x == limit.x - 1)
		return (1);
	else
		return (0);
}

static void	check_element(t_data *data, const char c, int x, int y)
{
	if (c == 'P')
	{
		data->map.player += 1;
		if (data->map.player > 1)
			print_error(data, "There is more than one player");
		data->map.ploc.x = x;
		data->map.ploc.y = y;
	}
	else if (c == 'C')
	{
		data->map.collect += 1;
		data->map.cloc.x = x;
		data->map.cloc.y = y;
	}
	else if (c == 'E')
		data->map.exit += 1;
	else if (is_edge(x, y, data->map.dim) && c != '1')
		print_error(data, "Map is not surrounded by walls or rectangular");
	else if (!(c == '0' || c == '1'))
	{
		printf("\e[0;31m\nError\n\e[0m");
		printf("\e[41m\"%c\" is an invalid map element\e[0m\n", c);
		clear_data(data);
	}
}

static void	check_mapset(t_data *data)
{
	if (data->map.exit < 1)
		print_error(data, "There is no Exit");
	if (data->map.player < 1)
		print_error(data, "There is no Player");
	if (data->map.collect < 1)
		print_error(data, "There is no collectible");
}

static void	init_mapdata(t_map *map)
{
	map->exit = 0;
	map->player = 0;
	map->collect = 0;
	map->ploc.x = 0;
	map->ploc.y = 0;
	map->cloc.x = 0;
	map->cloc.y = 0;
}

void	check_map(t_data *data)
{
	int		i;
	int		j;
	char	**coord;

	i = 0;
	coord = data->map.tab;
	init_mapdata(&data->map);
	while (i < data->map.dim.y)
	{
		j = 0;
		while (j < data->map.dim.x)
		{
			check_element(data, coord[i][j], j, i);
			++j;
		}
		++i;
	}
	check_mapset(data);
}
