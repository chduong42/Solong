/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chduong <chduong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 17:16:32 by chduong           #+#    #+#             */
/*   Updated: 2021/12/24 13:33:30 by chduong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	destroy_wall_exit(t_data *data)
{
	if (data->exit)
		mlx_destroy_image(data->mlx, data->exit);
	if (data->wall)
		mlx_destroy_image(data->mlx, data->wall);
	if (data->wfloor)
		mlx_destroy_image(data->mlx, data->wfloor);
	if (data->wroof1)
		mlx_destroy_image(data->mlx, data->wroof1);
	if (data->wroof2)
		mlx_destroy_image(data->mlx, data->wroof2);
}

static void	destroy_player(t_data *data)
{
	if (data->player)
		mlx_destroy_image(data->mlx, data->player);
	if (data->pexit)
		mlx_destroy_image(data->mlx, data->pexit);
	if (data->proof1)
		mlx_destroy_image(data->mlx, data->proof1);
	if (data->proof2)
		mlx_destroy_image(data->mlx, data->proof2);
	if (data->pfloor)
		mlx_destroy_image(data->mlx, data->pfloor);
}

static void	destroy_collectible(t_data *data)
{
	if (data->collect)
		mlx_destroy_image(data->mlx, data->collect);
	if (data->croof1)
		mlx_destroy_image(data->mlx, data->croof1);
	if (data->croof2)
		mlx_destroy_image(data->mlx, data->croof2);
	if (data->croof3)
		mlx_destroy_image(data->mlx, data->croof3);
}

static void	destroy_ground(t_data *data)
{
	if (data->ground)
		mlx_destroy_image(data->mlx, data->ground);
	if (data->groof1)
		mlx_destroy_image(data->mlx, data->groof1);
	if (data->groof2)
		mlx_destroy_image(data->mlx, data->groof2);
	if (data->gfloor)
		mlx_destroy_image(data->mlx, data->gfloor);
}

void	clear_data(t_data *data)
{
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	destroy_ground(data);
	destroy_player(data);
	destroy_wall_exit(data);
	destroy_collectible(data);
	if (data->mlx)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
	if (data->map.tab)
		free_map(data->map.tab, data->map.dim.y);
	exit(EXIT_SUCCESS);
}
