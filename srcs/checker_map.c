/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chduong <chduong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 12:10:34 by chduong           #+#    #+#             */
/*   Updated: 2021/12/20 14:53:02 by chduong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_element(const char c, t_map *map)
{
	if (c == 'P')
	{
		map->player += 1;
		if (map->player > 1)
			print_error("There is more than one player");
	}
	else if (c == 'C')
		map->collect += 1;
	else if (c == 'E')
		map->exit += 1;
	else if (!(c == '1' || c == '0'))
	{
		printf("\e[0;31m\nError\n\e[0m ");
		printf("\e[41m\"%c\" invalid map element\n", c);
		exit(EXIT_FAILURE);
	}
}

static t_bool	is_edge(int y, int x, t_dim limit)
{
	if (y == 0 || y == limit.y - 1)
		return (1);
	else if (x == 0 || x == limit.x - 1)
		return (1);
	else
		return (0);
}

static void	check_mapset(t_map *map)
{
	if (map->exit < 1)
		print_error("There is no Exit");
	if (map->player < 1)
		print_error("There is no Player");
	if (map->collect < 1)
		print_error("There is no collectible");
}

void	check_map(t_map *map)
{
	int		i;
	int		j;
    char    **coord;

	i = 0;
    coord = map->tab;
	map->exit = 0;
	map->player = 0;
	map->collect = 0;
	while (i < map->dim.y)
	{
		j = 0;
		while (j < map->dim.x)
		{
			check_element(coord[i][j], map);
			if (is_edge(i, j, map->dim) && coord[i][j] != '1')
				print_error("Map is not surrounded by walls or rectangular");
			++j;
		}
		++i;
	}
	check_mapset(map);
}
