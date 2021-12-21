/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chduong <chduong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 14:34:41 by chduong           #+#    #+#             */
/*   Updated: 2021/12/18 18:21:29 by chduong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_error(const char *msg)
{
	printf("\n\e[0;31mError\n\e[0m");
	printf("\e[41m%s\n\e[0m", msg);
	exit(EXIT_FAILURE);
}

void    check_ptr(void *ptr)
{
	if (!ptr)
	{
		printf("\e[0;31mError\n\e[0m");
        printf("\e[41mFail memory allocation\n\e[0m");
		exit(EXIT_FAILURE);
	}
}