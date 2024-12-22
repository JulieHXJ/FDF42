/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhuang <xhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 13:49:41 by junjun            #+#    #+#             */
/*   Updated: 2024/12/18 18:05:36 by xhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
#define FDF_H

#include <stdlib.h>
#include <fcntl.h>
#include <mlx.h>
#include "libft/libft.h"

#ifndef WIN_WIDTH
# define WIN_WIDTH 800
# endif

#ifndef WIN_HEIGHT 
# define WIN_HEIGHT 800
#endif

typedef struct s_map
{
	int width;
	int height;
	int **value;
} t_map;

typedef struct s_point
{
	int x;
	int y;
	int z;
	int color;
} t_point;;

typedef struct s_draw
{
	int	x1;
	int	y1;
	int x2;
	int y2;
	int color;
	int dx;
	int dy;
	int sx;
	int sy;
	int direc;
} t_draw;

#endif
