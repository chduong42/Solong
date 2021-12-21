/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_display.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chduong <chduong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 19:36:06 by chduong           #+#    #+#             */
/*   Updated: 2021/12/21 17:04:25 by chduong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	parse_display(t_data *d, int x, int y)
{
    char    **map;
    
	map = d->map.tab;
    if (map[y][x] == '1')
		mlx_put_image_to_window(d->mlx, d->win, d->wall, x, y * PIX);
	else if (map[y][x] == '0')
		mlx_put_image_to_window(d->mlx, d->win, d->ground, x, y * PIX);
	else if (map[y][x] == 'P')
		mlx_put_image_to_window(d->mlx, d->win, d->player, x, y * PIX);
	else if (map[y][x] == 'C')
		mlx_put_image_to_window(d->mlx, d->win, d->collect, x, y * PIX);
	else if (map[y][x] == 'E')
		mlx_put_image_to_window(d->mlx, d->win, d->exit, x, y * PIX);
}
