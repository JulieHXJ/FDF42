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


#endif