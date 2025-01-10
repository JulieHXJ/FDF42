/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iso_convert.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhuang <xhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 18:57:27 by xhuang            #+#    #+#             */
/*   Updated: 2025/01/10 15:55:42 by xhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_point	isometric_project_30(t_point src, t_img *img)
{
	t_point	dst;
	double	x;
	double	y;
	double	z;

	if (!img)
		exit(EXIT_FAILURE);
	if (img->zoom < 1)
		img->zoom = 1;
	x = src.x * img->zoom;
	y = src.y * img->zoom;
	z = src.z * img->zoom;
	x = x * cos(img->beta) - z * sin(img->beta);
	z = z * cos(img->beta) + src.x * sin(img->beta);
	y = y * cos(img->alpha) - z * sin(img->alpha);
	z = z * cos(img->alpha) + src.y * sin(img->alpha);
	dst.x = (x - y) * cos(M_PI / 6);
	dst.y = (x + y) * sin(M_PI / 6) - z;
	dst.z = 0;
	dst.color = src.color;
	return (dst);
}

static void	convert_3d(t_map *map, t_img *img)
{
	int	x;
	int	y;

	if (!map || !img)
		return ;
	y = -1;
	while (++y < map->height)
	{
		x = -1;
		while (++x < map->width)
			map->grid[y][x] = isometric_project_30(map->grid[y][x], img);
	}
}

static void	center_x(t_map *map, t_img *img)
{
	int	x;
	int	y;
	int	min_x;
	int	max_x;

	min_x = INT_MAX;
	max_x = INT_MIN;
	y = -1;
	while (++y < map->height)
	{
		x = -1;
		while (++x < map->width)
		{
			if (map->grid[y][x].x < min_x)
				min_x = map->grid[y][x].x;
			if (map->grid[y][x].x > max_x)
				max_x = map->grid[y][x].x;
		}
	}
	img->x_offset = (WIN_WIDTH / 2) - (min_x + max_x) / 2;
}

static void	center_y(t_map *map, t_img *img)
{
	int	x;
	int	y;
	int	min_y;
	int	max_y;

	min_y = INT_MAX;
	max_y = INT_MIN;
	y = -1;
	while (++y < map->height)
	{
		x = -1;
		while (++x < map->width)
		{
			if (map->grid[y][x].y < min_y)
				min_y = map->grid[y][x].y;
			if (map->grid[y][x].y > max_y)
				max_y = map->grid[y][x].y;
		}
	}
	img->y_offset = (WIN_HEIGHT / 2) - (min_y + max_y) / 2;
}

void	center_map(t_map *map, t_img *img)
{
	int	x;
	int	y;

	set_zoom(map, img);
	convert_3d(map, img);
	center_x(map, img);
	center_y(map, img);
	y = -1;
	while (++y < map->height)
	{
		x = -1;
		while (++x < map->width)
		{
			map->grid[y][x].x += img->x_offset;
			map->grid[y][x].y += img->y_offset;
		}
	}
}
