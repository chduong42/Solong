/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chduong <chduong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 15:24:34 by chduong           #+#    #+#             */
/*   Updated: 2021/12/21 16:21:06 by chduong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_file(const char *path_file)
{
	size_t	len;
	char	*ext;

	printf("Checking map file... ");
	len = ft_strlen(path_file);
	if (len < 4)
		print_error("No \".ber\" extension");
	ext = ft_strnstr(path_file, ".ber", len);
	len = ft_strlen(ext);
	if (len == 0 || len > 4)
		print_error("No \".ber\" extension");
	if (open(path_file, __O_DIRECTORY) > 0)
		print_error("Input is a directory, not a file.ber");
	printf("✅\n");
}

static t_dim	dim_map(const char *path_file)
{
	int		fd;
	char	*line;
	int		tmp;
	t_dim	dim;

	fd = open(path_file, O_RDONLY);
	line = NULL;
	dim.x = 0;
	dim.y = 0;
	while (get_next_line(fd, &line))
	{
		tmp = ft_strlen(line);
		if (dim.x == 0)
			dim.x = tmp;
		if (tmp != dim.x)
			print_error("Map is not rectangular");
		++dim.y;
	}	
	free(line);
	close(fd);
	return (dim);
}

void	free_map(char **map, int y)
{
	int i;

	i = 0;
	while (i < y)
		free(map[i++]);
	free(map);
	map = NULL;
}

static char	**malloc_map(t_dim dim)
{
	int		i;
	char	**map;

	map = malloc(sizeof(char **) * (dim.y + 1));
	if (!map)
		return (NULL);
	i = 0;
	while (i < dim.y)
	{
		map[i] = malloc(sizeof(char *) * (dim.x + 1));
		if (map[i] == NULL)
		{
			free_map(map, i);
			return (NULL);
		}
		++i;
	}
	map[i] = NULL;
	return (map);
}

t_map	get_map(const char *path_file)
{
	int		i;
	int		fd;
	char	*line;
	t_map	map;

	check_file(path_file);
	ft_putstr_fd("Parsing the map... ", 1);
	map.dim = dim_map(path_file);
	map.tab = malloc_map(map.dim);
	i = 0;
	line = NULL;
	fd = open(path_file, O_RDONLY);
	while (get_next_line(fd, &line))
		ft_strlcpy(map.tab[i++], line, map.dim.x + 1);
	close(fd);
	free(line);
	check_map(&map);
	printf("✅\n");
	return (map);
}
