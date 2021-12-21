/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chduong <chduong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 17:56:41 by chduong           #+#    #+#             */
/*   Updated: 2021/12/21 18:00:04 by chduong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_window(t_data *data, t_dim map)
{
	t_dim	res;

	res.x = map.x * PIX;
	res.y = map.y * PIX;
	data->mlx = mlx_init();
	check_ptr(data->mlx);
	data->win = mlx_new_window(data->mlx, res.x, res.y, TITLE);
	check_ptr(data->win);
}

void	load_img(t_data *data)
{
	int		w;
	int		h;
	
	w = data->width;
	h = data->height;
	data->exit = mlx_xpm_file_to_image(data->mlx, EXIT, &w, &h);
	check_ptr(data->exit);
	data->wall = mlx_xpm_file_to_image(data->mlx, WALL, &w, &h);
	check_ptr(data->wall);
	data->player = mlx_xpm_file_to_image(data->mlx, PLAYER, &w, &h);
	check_ptr(data->player);
	data->ground = mlx_xpm_file_to_image(data->mlx, GROUND, &w, &h);
	check_ptr(data->ground);
	data->collect = mlx_xpm_file_to_image(data->mlx, COLLECT, &w, &h);
	check_ptr(data->collect);
}

void    set_loop(t_data *data)
{
	mlx_loop_hook(data->mlx, &handle_display, &data);
	mlx_hook(data->win, KeyPress, KeyPressMask, &handle_keypress, &data);
	mlx_hook(data->win, ClientMessage, LeaveWindowMask, &handle_crossbtn, &data);
	mlx_loop(data->mlx);
}

void	clear_data(t_data *data)
{
	// mlx_destroy_image(data->mlx, data->exit);
	// mlx_destroy_image(data->mlx, data->wall);
	// mlx_destroy_image(data->mlx, data->player);
	// mlx_destroy_image(data->mlx, data->ground);
	// mlx_destroy_image(data->mlx, data->collect);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	free_map(data->map.tab, data->map.dim.y);
}

int	main(int ac, char **av)
{
	t_data	data;

	if(ac != 2)
		fprintf(stderr, "\e[1;37musage :\e[0m %s <mapfile.ber>\n", av[0]);
	else
	{
		data.map = get_map(av[1]);
		init_window(&data, data.map.dim);
		// load_img(&data);
		set_loop(&data);
		mlx_destroy_display(data.mlx);
		free(data.mlx);
		free_map(data.map.tab, data.map.dim.y);
	}
	return (0);
}
