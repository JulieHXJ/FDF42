/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhuang <xhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 13:58:26 by junjun            #+#    #+#             */
/*   Updated: 2025/01/10 16:04:33 by xhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
parse the .fdf file and store the map data.
*/

#include "fdf.h"

char	**get_arr(char *str)
{
	char	**points;
	char	*trimmed;

	trimmed = ft_strtrim(str, " \t\n");
	points = ft_split(trimmed, ' ');
	free(trimmed);
	if (!points)
		return (NULL);
	return (points);
}

static int	get_size(const int fd, t_map *map)
{
	char	*line;
	char	**points;

	line = get_next_line(fd);
	while ((line))
	{
		points = get_arr(line);
		free(line);
		if (!points)
			return (close(fd), -1);
		if (map->height == 0)
		{
			while (points[map->width])
				map->width++;
		}
		free_arr(points);
		map->height++;
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}

static int	malloc_grid(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	map->grid = malloc(sizeof(t_point *) * map->height);
	if (!map->grid)
		return (-1);
	while (i < map->height)
	{
		map->grid[i] = malloc(sizeof(t_point) * map->width);
		if (!map->grid[i])
			return (free_map(map), -1);
		j = 0;
		while (j < map->width)
		{
			map->grid[i][j].x = j;
			map->grid[i][j].y = i;
			j++;
		}
		i++;
	}
	return (0);
}

static int	put_value(const int fd, t_map *map)
{
	char	*line;
	char	**points;
	int		x;
	int		y;

	y = 0;
	line = get_next_line(fd);
	while ((line))
	{
		points = get_arr(line);
		free(line);
		if (!points)
			return (error_handle(fd, map, "malloc fail in put value"), -1);
		x = -1;
		while (++x < map->width)
		{
			map->grid[y][x].z = ft_atoi(points[x]);
			map->grid[y][x].color = get_color(fd, map, points[x]);
		}
		free_arr(points);
		y++;
		line = get_next_line(fd);
	}
	return (close(fd), 0);
}

int	read_map(char *file, t_map *map)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (error_handle(fd, map, "Failed to open file"), 1);
	map_init(map);
	if (get_size(fd, map) != 0)
		return (close(fd), 1);
	if (malloc_grid(map) < 0)
		return (1);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (error_handle(fd, map, "Failed to open file"), 1);
	if (put_value(fd, map) != 0)
		return (error_handle(fd, map, "put z value failed"), 1);
	close(fd);
	return (0);
}
