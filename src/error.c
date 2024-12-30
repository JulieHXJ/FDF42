/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhuang <xhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 23:13:58 by xhuang            #+#    #+#             */
/*   Updated: 2024/12/30 16:03:49 by xhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void free_map(t_map *map)
{
	int i;

	i = 0;
	if (!map->spot)
		return;
	while (i < map->height)
	{
		free(map->spot[i]);
		i++;
	}
	free(map->spot);
	map->spot = NULL;
}

perror