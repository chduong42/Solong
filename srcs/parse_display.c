/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_display.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chduong <chduong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 19:36:06 by chduong           #+#    #+#             */
/*   Updated: 2021/12/23 16:58:31 by chduong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	display_wall(t_data *d, char **map, int x, int y)
{
	t_bool	y_ismax;

	y_ismax = 0;
	if (y == d->map.dim.y - 1)
		y_ismax = 1;
	if (!y_ismax && (map[y + 1][x] == 'E' || map[y + 1][x] == '2'))
		mlx_put_image_to_window(d->mlx, d->win, d->wroof1, x * PIX, y * PIX);
	else if (!y_ismax && x > 0
		&& (map[y + 1][x - 1] == 'E' || map[y + 1][x - 1] == '2'))
		mlx_put_image_to_window(d->mlx, d->win, d->wroof2, x * PIX, y * PIX);
	else if (x && (map[y][x - 1] == 'E' || map[y][x - 1] == '2'))
		mlx_put_image_to_window(d->mlx, d->win, d->wfloor, x * PIX, y * PIX);
	else
		mlx_put_image_to_window(d->mlx, d->win, d->wall, x * PIX, y * PIX);
}

static void	display_ground(t_data *d, char **map, int x, int y)
{
	if (map[y + 1][x] == 'E' || map[y + 1][x] == '2')
		mlx_put_image_to_window(d->mlx, d->win, d->groof1, x * PIX, y * PIX);
	else if (map[y + 1][x - 1] == 'E' || map[y + 1][x - 1] == '2')
		mlx_put_image_to_window(d->mlx, d->win, d->groof2, x * PIX, y * PIX);
	else if (map[y][x - 1] == 'E' || map[y][x - 1] == '2')
		mlx_put_image_to_window(d->mlx, d->win, d->gfloor, x * PIX, y * PIX);
	else
		mlx_put_image_to_window(d->mlx, d->win, d->ground, x * PIX, y * PIX);
}

static void	display_collectible(t_data *d, char **map, int x, int y)
{
	if (map[y + 1][x] == 'E' || map[y + 1][x] == '2')
		mlx_put_image_to_window(d->mlx, d->win, d->croof1, x * PIX, y * PIX);
	else if (map[y + 1][x - 1] == 'E' || map[y + 1][x - 1] == '2')
		mlx_put_image_to_window(d->mlx, d->win, d->croof2, x * PIX, y * PIX);
	else if (map[y][x - 1] == 'E' || map[y][x - 1] == '2')
		mlx_put_image_to_window(d->mlx, d->win, d->croof3, x * PIX, y * PIX);
	else
		mlx_put_image_to_window(d->mlx, d->win, d->collect, x * PIX, y * PIX);
}

static void	display_player(t_data *d, char **map, int x, int y)
{
	if (map[y + 1][x] == 'E' || map[y + 1][x] == '2')
		mlx_put_image_to_window(d->mlx, d->win, d->proof1, x * PIX, y * PIX);
	else if (map[y + 1][x - 1] == 'E' || map[y + 1][x - 1] == '2')
		mlx_put_image_to_window(d->mlx, d->win, d->proof2, x * PIX, y * PIX);
	else if (map[y][x - 1] == 'E' || map[y][x - 1] == '2')
		mlx_put_image_to_window(d->mlx, d->win, d->pfloor, x * PIX, y * PIX);
	else
		mlx_put_image_to_window(d->mlx, d->win, d->player, x * PIX, y * PIX);
}

void	parse_display(t_data *d, int x, int y)
{
	char	**map;

	map = d->map.tab;
	if (map[y][x] == '1')
		display_wall(d, map, x, y);
	else if (map[y][x] == '0')
		display_ground(d, map, x, y);
	else if (map[y][x] == 'P')
		display_player(d, map, x, y);
	else if (map[y][x] == 'C')
		display_collectible(d, map, x, y);
	else if (map[y][x] == 'E')
		mlx_put_image_to_window(d->mlx, d->win, d->exit, x * PIX, y * PIX);
	else if (map[y][x] == '2')
		mlx_put_image_to_window(d->mlx, d->win, d->pexit, x * PIX, y * PIX);
}
