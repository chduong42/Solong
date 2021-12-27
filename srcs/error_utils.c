/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chduong <chduong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 14:34:41 by chduong           #+#    #+#             */
/*   Updated: 2021/12/24 15:14:35 by chduong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_error(t_data *data, const char *msg)
{
	printf("\n\e[0;31mError\n\e[0m");
	printf("\e[41m%s\e[0m\n", msg);
	clear_data(data);
}

void	check_ptr(void *ptr, t_data *data)
{
	if (!ptr)
	{
		printf("\e[0;31mError\n\e[0m");
		printf("\e[41mFail memory allocation\n\e[0m");
		clear_data(data);
	}
}
