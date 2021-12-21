/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chduong <chduong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 15:30:54 by chduong           #+#    #+#             */
/*   Updated: 2021/12/21 18:01:37 by chduong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_display(t_data *data)
{
	if(data)
		printf("OK\n");
	return (0);
}

int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		{
			mlx_destroy_window(data->mlx, data->win);
			data->win = NULL;
		}
			// clear_data(data);
	return (0);
}

int	handle_crossbtn(t_data *data)
{
	clear_data(data);
	return (0);
}
