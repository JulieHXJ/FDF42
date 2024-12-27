/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junjun <junjun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 13:58:26 by junjun            #+#    #+#             */
/*   Updated: 2024/12/27 17:24:52 by junjun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	free_arr(char **arr)
{
	int	i;

	i = 0;
	if (!arr)
		return ;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void map_init(t_map *map)
{
	map->width = 0;
	map->height = 0;
	map->spot = NULL;
}

static int	map_size(const int fd, t_map *map)
{
	char	*line;
	char	**points;

	while (line = get_next_line(fd))
	{
		points = ft_split(line, ' ');
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
	}
	close(fd);
	return (0);
}

int	parse_color(int fd, )
{
	
}

static int	put_value(const int fd, t_map *map)
{
	char	*line;
	char	**points;
	int		x;
	int		y;

	map->spot = malloc(sizeof(int *) * map->height);
	if (!map->spot)
		return (-1);
	y = 0;
	while (line = get_next_line(fd))
	{
		points = ft_split(line, ' ');
		free(line);
		if (!points)
			return (close(fd), -1);
		map->spot[y] = malloc(sizeof(t_point) * map->width);
		if (!map->spot[y])
			return (free_arr(points), free_map(map), -1);
		x = 0;
		while (x < map->width)
		{
			map->spot[y][x].x = (x - (map->width / 2)) * map->interval;
            map->spot[y][x].y = (y - (map->height / 2)) * map->interval;
            map->spot[y][x].z = ft_atoi(points[x]);
            map->spot[y][x].color = parse_color(fd, map, points[x]);;
			x++;
		}
		free_arr(points);
		y++;
	}
	return (close(fd), 0);
}

static void	map_error(t_map *map)
{
	if (map)
		free_map(&map);
	ft_printf("Invalid map!\n");
	exit(EXIT_FAILURE);
}

void	parse_map(char *file)
{
	int	fd;
	t_map *map;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Fail to open file.\n");
		exit(EXIT_FAILURE);
	}
	map = malloc(sizeof(t_map));
	if (!map)
	{
		/* code */
	}
	
	if (map_size(fd, &map) != 0)
		map_error(map);
	map->interval = find_min(WIN_WIDTH / map->width, WIN_HEIGHT / map->height) / 2;
	map->interval = find_max(2, map->interval);
	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Fail to re-open file.\n");
		map_error(map);
	}
	if (put_value(fd, &map) != 0)
		map_error(map);
}



void get_value(int fd, t_point *p)
{
	
}