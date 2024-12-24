/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_initi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhuang <xhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 13:58:26 by junjun            #+#    #+#             */
/*   Updated: 2024/12/24 23:26:19 by xhuang           ###   ########.fr       */
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

static int	read_map(const int fd, t_map *map)
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

static int	put_value(const int fd, t_map *map)
{
	char	*line;
	char	**points;
	int		x;
	int		y;

	map->value = malloc(sizeof(int *) * map->height);
	if (!map->value)
		return (-1);
	y = 0;
	while (line = get_next_line(fd))
	{
		points = ft_split(line, ' ');
		free(line);
		if (!points)
			return (close(fd), -1);
		map->value[y] = malloc(sizeof(int) * map->width);
		if (!map->value[y])
			return (free_arr(points), free_arr(map->value[y]), -1);
		x = 0;
		while (points[x] && x < map->width)
		{
			map->value[y][x] = ft_atoi(points[x]);
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

void	map_init(char *file, t_map *map)
{
	int	fd;

	map->width = 0;
	map->height = 0;
	map->value = NULL;
	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Fail to open file.\n");
		exit(EXIT_FAILURE);
	}
	if (read_map(fd, &map) != 0)
		map_error(map);
	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Fail to re-open file.\n");
		map_error(map);
	}
	if (put_value(fd, &map) != 0)
		map_error(map);
}
