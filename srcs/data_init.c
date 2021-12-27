/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chduong <chduong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 20:33:24 by chduong           #+#    #+#             */
/*   Updated: 2021/12/24 15:17:37 by chduong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	img_init(t_data *data)
{
	data->exit = NULL;
	data->wall = NULL;
	data->wroof1 = NULL;
	data->wroof2 = NULL;
	data->wfloor = NULL;
	data->ground = NULL;
	data->groof1 = NULL;
	data->groof2 = NULL;
	data->gfloor = NULL;
	data->player = NULL;
	data->pexit = NULL;
	data->proof1 = NULL;
	data->proof2 = NULL;
	data->pfloor = NULL;
	data->collect = NULL;
	data->croof1 = NULL;
	data->croof2 = NULL;
	data->croof3 = NULL;
	data->move_display = NULL;
	data->map.tab = NULL;
}

void	data_init(t_data *data)
{
	printf("\e[1;33mData Initialization...\e[0m");
	img_init(data);
	data->width = 0;
	data->height = 0;
	data->count_move = 0;
	data->win = NULL;
	data->mlx = mlx_init();
	check_ptr(data->mlx, data);
	printf("\t✅\n");
}
