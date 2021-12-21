/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chduong <chduong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 13:24:32 by chduong           #+#    #+#             */
/*   Updated: 2021/12/21 17:01:54 by chduong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <stdio.h>
# include <errno.h>
# include <string.h>
# include <mlx.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include "libft.h"
# include "get_next_line.h"

//	MACRO
# define TITLE "Fuji hunts mouses"
# define PIX 80

//	Key Code
# define A 97
# define D 100
# define S 115
# define W 119

//	IMAGE PATH
# define EXIT "image/xpm/house.xpm"
# define WALL "image/xpm/bush.xpm"
# define PLAYER "image/xpm/fuji.xpm"
# define GROUND "image/xpm/grass1.xpm"
# define COLLECT "image/xpm/mouse.xpm"

//	Type Definition
typedef int				t_bool;
typedef unsigned int	t_uint;

typedef struct s_dim
{
	int		x;
	int		y;
}			t_dim;

typedef struct s_map
{
	char	**tab;
	int		exit;
	int		player;
	int		collect;
	t_dim	dim;
}			t_map;

typedef struct s_data
{
	int		width;
	int		height;
	void	*mlx;
	void	*win;
	void	*exit;
	void	*wall;
	void	*ground;
	void	*player;
	void	*collect;
	t_map	map;
	t_bool	can_exit;
}			t_data;

void	load_img(t_data *data);
void	clear_data(t_data *data);

//	ERROR UTILS
void	print_error(const char *msg);
void    check_ptr(void *ptr);

//	MAP FUNCTIONS
void	free_map(char **map, int y);
void	check_map(t_map *map);
t_map	get_map(const char *path_file);

//  DISPLAY
void	parse_display(t_data *data, int x, int y);
int		handle_display(t_data *data);

//	HANDLER FUNCTIONS
int		handle_keypress(int keysym, t_data *data);
int		handle_crossbtn(t_data *data);

#endif