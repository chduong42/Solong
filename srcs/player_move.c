/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chduong <chduong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 14:28:34 by chduong           #+#    #+#             */
/*   Updated: 2021/12/23 18:58:41 by chduong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	erase_oldplayer(char player, t_dim loc, char **map)
{
	if (map[loc.y][loc.x] == player)
		map[loc.y][loc.x] = '0';
	else if (map[loc.y][loc.x] == '2')
		map[loc.y][loc.x] = 'E';
}

int	p1_up_down(int dir, t_data *data)
{
	t_dim	p;
	char	**map;
	int		count;

	count = 0;
	p = data->map.ploc;
	map = data->map.tab;
	if (map[p.y + dir][p.x] == '0' || map[p.y + dir][p.x] == 'C')
	{
		if (map[p.y + dir][p.x] == 'C')
			data->map.collect -= 1;
		map[p.y + dir][p.x] = 'P';
		++count;
	}
	else if (map[p.y + dir][p.x] == 'E')
	{
		map[p.y + dir][p.x] = '2';
		++count;
	}
	if (count > 0)
		erase_oldplayer('P', p, map);
	data->count_move += count;
	return (count);
}

int	p1_left_right(int dir, t_data *data)
{
	t_dim	p;
	char	**map;
	int		count;

	count = 0;
	p = data->map.ploc;
	map = data->map.tab;
	if (map[p.y][p.x + dir] == '0' || map[p.y][p.x + dir] == 'C')
	{
		if (map[p.y][p.x + dir] == 'C')
			data->map.collect -= 1;
		map[p.y][p.x + dir] = 'P';
		++count;
	}
	else if (map[p.y][p.x + dir] == 'E')
	{
		map[p.y][p.x + dir] = '2';
		++count;
	}
	if (count > 0)
		erase_oldplayer('P', p, map);
	data->count_move += count;
	return (count);
}

int	p2_up_down(int dir, t_data *data)
{
	t_dim	c;
	char	**map;
	int		count;

	count = 0;
	c = data->map.cloc;
	map = data->map.tab;
	if (map[c.y + dir][c.x] == '0')
	{
		map[c.y + dir][c.x] = 'C';
		++count;
	}
	if (count > 0)
		erase_oldplayer('C', c, map);
	return (count);
}

int	p2_left_right(int dir, t_data *data)
{
	t_dim	c;
	char	**map;
	int		count;

	count = 0;
	c = data->map.cloc;
	map = data->map.tab;
	if (map[c.y][c.x + dir] == '0')
	{
		map[c.y][c.x + dir] = 'C';
		++count;
	}
	if (count > 0)
		erase_oldplayer('C', c, map);
	return (count);
}
