/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junjun <junjun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 13:49:41 by junjun            #+#    #+#             */
/*   Updated: 2024/12/17 17:17:46 by junjun           ###   ########.fr       */
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
} t_point;;


#endif