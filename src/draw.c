/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhuang <xhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 14:12:27 by junjun            #+#    #+#             */
/*   Updated: 2025/01/10 15:23:00 by xhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_line	line_value(t_point p1, t_point p2)
{
	t_line	line;

	line.delta_x = abs(p2.x - p1.x);
	line.delta_y = abs(p2.y - p1.y);
	if (p1.x < p2.x)
		line.step_x = 1;
	else
		line.step_x = -1;
	if (p1.y < p2.y)
		line.step_y = 1;
	else
		line.step_y = -1;
	line.err = line.delta_x - line.delta_y;
	line.cur = p1;
	return (line);
}

static void	draw_line(t_point p1, t_point p2, t_fdf *fdf)
{
	t_line	line;
	int		e2;

	line = line_value(p1, p2);
	while (1)
	{
		if (line.cur.x >= 0 && line.cur.x < WIN_WIDTH && line.cur.y >= 0
			&& line.cur.y < WIN_HEIGHT)
			mlx_put_pixel(fdf->img->mlx_img, line.cur.x, line.cur.y, p1.color);
		if (line.cur.x == p2.x && line.cur.y == p2.y)
			break ;
		e2 = line.err * 2;
		if (e2 >= -line.delta_y)
		{
			line.err -= line.delta_y;
			line.cur.x += line.step_x;
		}
		if (e2 <= line.delta_x)
		{
			line.err += line.delta_x;
			line.cur.y += line.step_y;
		}
	}
}

void	draw_map(t_fdf *fdf)
{
	int		x;
	int		y;
	t_point	p1;
	t_point	p2;

	center_map(fdf->map, fdf->img);
	y = -1;
	while (++y < fdf->map->height)
	{
		x = -1;
		while (++x < fdf->map->width)
		{
			p1 = fdf->map->grid[y][x];
			if (x + 1 < fdf->map->width)
			{
				p2 = fdf->map->grid[y][x + 1];
				draw_line(p1, p2, fdf);
			}
			if (y + 1 < fdf->map->height)
			{
				p2 = fdf->map->grid[y + 1][x];
				draw_line(p1, p2, fdf);
			}
		}
	}
}
