/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chduong <chduong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 15:30:54 by chduong           #+#    #+#             */
/*   Updated: 2021/12/24 15:37:03 by chduong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_display(t_data *data)
{
	t_dim	loc;
	char	**player;

	loc = data->map.ploc;
	player = data->map.tab;
	if (player[loc.y][loc.x] == '2' && data->map.collect == 0)
		clear_data(data);
	return (0);
}

int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		clear_data(data);
	else if (keysym == W)
		data->map.ploc.y -= p1_up_down(UP, data);
	else if (keysym == S)
		data->map.ploc.y += p1_up_down(DOWN, data);
	else if (keysym == A)
		data->map.ploc.x -= p1_left_right(LEFT, data);
	else if (keysym == D)
		data->map.ploc.x += p1_left_right(RIGHT, data);
	else if (keysym == ARROW_UP && data->map.collect > 0)
		data->map.cloc.y -= p2_up_down(UP, data);
	else if (keysym == ARROW_DOWN && data->map.collect > 0)
		data->map.cloc.y += p2_up_down(DOWN, data);
	else if (keysym == ARROW_LEFT && data->map.collect > 0)
		data->map.cloc.x -= p2_left_right(LEFT, data);
	else if (keysym == ARROW_RIGHT && data->map.collect > 0)
		data->map.cloc.x += p2_left_right(RIGHT, data);
	display_map(data);
	print_counter(data);
	return (0);
}

int	cross_btn(t_data *data)
{
	clear_data(data);
	return (0);
}
