/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junjun <junjun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 13:58:26 by junjun            #+#    #+#             */
/*   Updated: 2025/01/01 23:19:58 by junjun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
parse the .fdf file and store the map data.
*/

#include "fdf.h"

static int	map_size(const int fd, t_map *map)
{
	char	*line;
	char	**points;

	while ((line = get_next_line(fd)))
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

static int	get_color(int fd, t_map *map, char *s)
{
	while (*s == '-')
		s++;
	while (ft_isdigit(*s))
		s++;
	if (*s == ',')
		s++;
	else
		return(0xFFFFFFFF);
	if (check_color(s))
        return (map_error(fd, map), -1);
	s = s + 2;
	to_lower(s);
	return (ft_atoi_base(s, "01234567890abcdef") << 8 | 0xFF);
}

static int	put_value(const int fd, t_map *map)
{
	char	*line;
	char	**points;
	int		x;
	int		y;

	map->spot = malloc(sizeof(t_point *) * map->height);
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
            map->spot[y][x].color = get_color(fd, map, points[x]);;
			x++;
		}
		free_arr(points);
		y++;
	}
	return (close(fd), 0);
}
void map_init(t_map *map)
{
	map->width = 0;
	map->height = 0;
	map->interval = 0;
	map->spot = NULL;
}
void	parse_map(char *file, t_map *map)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Fail to open file.\n");
		exit(EXIT_FAILURE);
	}
	map = malloc(sizeof(t_map));
	if (!map)
	{
		close(fd);
		ft_printf("Fail to allocate map.\n");
		exit(EXIT_FAILURE);
	}
	map_init(map);
	if (map_size(fd, map) != 0)
		map_error(fd, map);
	map->interval = find_min(WIN_WIDTH / map->width, WIN_HEIGHT / map->height) / 2;
	map->interval = find_max(2, map->interval);
	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Fail to re-open file.\n");
		map_error(fd, map);
	}
	if (put_value(fd, &map) != 0)
		map_error(fd, map);
}
