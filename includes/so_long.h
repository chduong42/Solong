/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chduong <chduong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 13:24:32 by chduong           #+#    #+#             */
/*   Updated: 2021/12/24 15:08:05 by chduong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <stdio.h>
# include <string.h>
# include <mlx.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include "libft.h"
# include "get_next_line.h"

//	MACRO
# define TITLE "Fuji hunts mouses"
# define PIX 80
# define UP -1
# define DOWN 1
# define LEFT -1
# define RIGHT 1

//	Key Code
# define A 97
# define D 100
# define S 115
# define W 119
# define ARROW_UP 65362
# define ARROW_DOWN 65364
# define ARROW_LEFT 65361
# define ARROW_RIGHT 65363

//	IMAGE PATH
# define DOOR "image/house/floor_house1.xpm"
# define WALL "image/bush.xpm"
# define WFLOOR "image/house/bush_floor.xpm"
# define WROOF1 "image/house/bush_roof1.xpm"
# define WROOF2 "image/house/bush_roof2.xpm"
# define CAT "image/player/fuji.xpm"
# define CEXIT "image/player/fuji_exit.xpm"
# define CFLOOR "image/player/fuji_exit2.xpm"
# define CROOF1 "image/player/fuji_onroof1.xpm"
# define CROOF2 "image/player/fuji_onroof2.xpm"
# define GROUND "image/grass.xpm"
# define GFLOOR "image/house/floor_house2.xpm"
# define GROOF1 "image/house/roof1.xpm"
# define GROOF2 "image/house/roof2.xpm"
# define MOUSE "image/mouse/mouse.xpm"
# define MROOF1 "image/mouse/mroof1.xpm"
# define MROOF2 "image/mouse/mroof2.xpm"
# define MROOF3 "image/mouse/mroof3.xpm"

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
	t_dim	ploc;
	t_dim	cloc;
}			t_map;

typedef struct s_data
{
	int		width;
	int		height;
	void	*mlx;
	void	*win;
	void	*exit;
	void	*wall;
	void	*wfloor;
	void	*wroof1;
	void	*wroof2;
	void	*ground;
	void	*groof1;
	void	*groof2;
	void	*gfloor;
	void	*player;
	void	*pexit;
	void	*pfloor;
	void	*proof1;
	void	*proof2;
	void	*collect;
	void	*croof1;
	void	*croof2;
	void	*croof3;
	char	*move_display;
	t_map	map;
	t_uint	count_move;
}			t_data;

//	DATA UTILS
void	data_init(t_data *data);
void	load_img(t_data *data);
void	clear_data(t_data *data);

//	ERROR UTILS
void	print_error(t_data *data, const char *msg);
void	check_ptr(void *ptr, t_data *data);

//	MAP FUNCTIONS
void	free_map(char **map, int y);
void	check_map(t_data *data);
void	get_map(t_data *data, const char *path_file);

//	DISPLAY
void	parse_display(t_data *data, int y, int x);
void	print_counter(t_data *data);
void	display_map(t_data *data);

//	HANDLER FUNCTIONS
int		handle_display(t_data *data);
int		handle_keypress(int keysym, t_data *data);
int		cross_btn(t_data *data);

//	PLAYERS MOVE
int		p1_up_down(int dir, t_data *data);
int		p1_left_right(int dir, t_data *data);
int		p2_up_down(int dir, t_data *data);
int		p2_left_right(int dir, t_data *data);

#endif