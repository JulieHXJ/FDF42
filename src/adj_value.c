/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adj_value.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhuang <xhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 01:22:27 by xhuang            #+#    #+#             */
/*   Updated: 2025/01/10 15:22:22 by xhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
set zoom value according to map size and window size
*/
#include "fdf.h"

int	z_range(t_map *map)
{
	int	max_z;
	int	min_z;
	int	x;
	int	y;

	max_z = INT_MIN;
	min_z = INT_MAX;
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->grid[y][x].z > max_z)
				max_z = map->grid[y][x].z;
			if (map->grid[y][x].z < min_z)
				min_z = map->grid[y][x].z;
			x++;
		}
		y++;
	}
	return (max_z - min_z);
}

void	set_zoom(t_map *map, t_img *img)
{
	double	zoom_width;
	double	zoom_height;
	double	project_width;
	double	project_height;

	project_width = (map->width + map->height) * cos(M_PI / 6);
	project_height = (map->width + map->height) * sin(M_PI / 6) + z_range(map);
	zoom_width = (WIN_WIDTH - 20) / project_width;
	zoom_height = (WIN_HEIGHT - 20) / project_height;
	if (zoom_width < zoom_height)
		img->zoom = zoom_width;
	else
		img->zoom = zoom_height;
	if (img->zoom < 1)
		img->zoom = 1;
}
