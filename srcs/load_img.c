/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chduong <chduong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 17:20:07 by chduong           #+#    #+#             */
/*   Updated: 2021/12/22 19:45:50 by chduong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_img(void *img)
{
	if (!img)
		return (1);
	else
		return (0);
}

static int	check_data(t_data *data)
{
	int	err;

	err = 0;
	err += check_img(data->exit);
	err += check_img(data->wall);
	err += check_img(data->wfloor);
	err += check_img(data->wroof1);
	err += check_img(data->wroof2);
	err += check_img(data->player);
	err += check_img(data->pexit);
	err += check_img(data->proof1);
	err += check_img(data->proof2);
	err += check_img(data->pfloor);
	err += check_img(data->ground);
	err += check_img(data->groof1);
	err += check_img(data->groof2);
	err += check_img(data->gfloor);
	err += check_img(data->collect);
	err += check_img(data->croof1);
	err += check_img(data->croof2);
	err += check_img(data->croof3);
	return (err);
}

static void	conv_xpm_to_img(t_data *data)
{
	int		w;
	int		h;

	w = data->width;
	h = data->height;
	data->exit = mlx_xpm_file_to_image(data->mlx, DOOR, &w, &h);
	data->wall = mlx_xpm_file_to_image(data->mlx, WALL, &w, &h);
	data->wfloor = mlx_xpm_file_to_image(data->mlx, WFLOOR, &w, &h);
	data->wroof1 = mlx_xpm_file_to_image(data->mlx, WROOF1, &w, &h);
	data->wroof2 = mlx_xpm_file_to_image(data->mlx, WROOF2, &w, &h);
	data->player = mlx_xpm_file_to_image(data->mlx, CAT, &w, &h);
	data->pexit = mlx_xpm_file_to_image(data->mlx, CEXIT, &w, &h);
	data->proof1 = mlx_xpm_file_to_image(data->mlx, CROOF1, &w, &h);
	data->proof2 = mlx_xpm_file_to_image(data->mlx, CROOF2, &w, &h);
	data->pfloor = mlx_xpm_file_to_image(data->mlx, CFLOOR, &w, &h);
	data->ground = mlx_xpm_file_to_image(data->mlx, GROUND, &w, &h);
	data->groof1 = mlx_xpm_file_to_image(data->mlx, GROOF1, &w, &h);
	data->groof2 = mlx_xpm_file_to_image(data->mlx, GROOF2, &w, &h);
	data->gfloor = mlx_xpm_file_to_image(data->mlx, GFLOOR, &w, &h);
	data->collect = mlx_xpm_file_to_image(data->mlx, MOUSE, &w, &h);
	data->croof1 = mlx_xpm_file_to_image(data->mlx, MROOF1, &w, &h);
	data->croof2 = mlx_xpm_file_to_image(data->mlx, MROOF2, &w, &h);
	data->croof3 = mlx_xpm_file_to_image(data->mlx, MROOF3, &w, &h);
}

void	load_img(t_data *data)
{
	printf("\e[1;33mLoading of graphics...\e[0m");
	conv_xpm_to_img(data);
	if (check_data(data) > 0)
	{
		printf("\t❌\n");
		clear_data(data);
	}
	else
		printf("\t✅\n");
}
