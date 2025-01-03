/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junjun <junjun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 14:12:27 by junjun            #+#    #+#             */
/*   Updated: 2025/01/03 01:23:12 by junjun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point iso_proj(t_point src, t_map *map, double zoom, int t_x, int t_y)
{
	t_point dst;
	double a; //a = angle

	a = M_PI / 4; //45 degree
	dst.x = (src.x - src.y) * cos(a) * zoom + t_x;
	dst.y = (src.x + src.y) * sin(a) *zoom - src.z * map. + t_y;
	dst.color = src.color;
	return(dst);
}


/*
Use Bresenham's line algorithm to draw lines between points.
Render horizontal and vertical lines connecting adjacent points.
Use color gradients for smooth transitions between points.
*/
void drow_line(t_point p1, t_point p2, t_img *img)
{
	t_line line;
	
	line.y1 = p1.y;
	line.x2 = p2.x;
	line.y2 = p2.y;
	line.color = p1.color;
	line.dx = abs(line.x2 - line.x1);
	line.dy = abs(line.y2 - line.y1);

	if(line.x1 < line.x2)
		line.sx = ;
	else
		step = dy;

	line.direc = line.dx - line.dy;
	while(1)
	{
		ft_put_pixel(img, line.x1, line.y1, line.color);
		if (line.x1 == line.x2 && line.y1 == line.y2)
			break;
		if (line.direc * 2 > -line.dy)
		{
			line.direc -= line.dy;
			line.x1 += line.sx;
		}
		if (line.direc * 2 < line.dx)
		{
			line.direc += line.dx;
			line.y1 += line.sy;
		}
	}
}

void draw_map(t_map *map, t_img *img, )
{
	iso_proj(map->grid,)
}