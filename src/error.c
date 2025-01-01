/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junjun <junjun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 23:13:58 by xhuang            #+#    #+#             */
/*   Updated: 2025/01/01 20:13:22 by junjun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_arr(char **arr)
{
	int	i;

	i = 0;
	if (!arr)
		return ;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

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

void error_handle(int fd, t_map *map, char *msg)
{
	close(fd);
	free_map(map);
	ft_putendl_fd(msg, 2);
	exit(EXIT_FAILURE);
}
