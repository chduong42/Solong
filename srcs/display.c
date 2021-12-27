/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chduong <chduong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 13:12:47 by chduong           #+#    #+#             */
/*   Updated: 2021/12/24 13:43:09 by chduong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_counter(t_data *data)
{
	printf("\E[H\E[2J");
	if (data->map.collect == 0)
		printf("============= 🐱 \e[42mCAN BACK HOME\e[0m 🏠 ===============\n\n");
	else
		printf("============= 🐱 \e[41mRUN BABY RUN\e[0m 🐭 ===============\n\n");
	printf("🐭 to eat : %d\n\n", data->map.collect);
	printf("🐱 steps 🕹  : %d\n\n", data->count_move);
	if (data->map.collect == 0)
		printf("============= 🐱 \e[42mCAN BACK HOME\e[0m 🏠 ===============\n\n");
	else
		printf("============= 🐱 \e[41mRUN BABY RUN\e[0m 🐭 ===============\n\n");
}

static void	display_counter(t_data *data)
{
	int	color;

	color = 0xFFFFFFFF;
	mlx_string_put(data->mlx, data->win, 15, 35, color, "Moves :");
	data->move_display = ft_itoa(data->count_move);
	mlx_string_put(data->mlx, data->win, 80, 35, color, data->move_display);
	free(data->move_display);
}

void	display_map(t_data *data)
{
	int		i;
	int		j;
	char	**map;

	map = data->map.tab;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
			parse_display(data, j++, i);
		++i;
	}
	display_counter(data);
}
