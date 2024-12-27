/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junjun <junjun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 00:33:28 by junjun            #+#    #+#             */
/*   Updated: 2024/12/27 17:28:05 by junjun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void map_init(t_map *map)
{
	map->width = 0;
	map->height = 0;
	map->spot = NULL;
}

void	map_error(t_map *map)
{
	if (map)
		free_map(&map);
	ft_printf("Invalid map!\n");
	exit(EXIT_FAILURE);
}