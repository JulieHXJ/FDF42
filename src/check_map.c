/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junjun <junjun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 00:33:28 by junjun            #+#    #+#             */
/*   Updated: 2025/01/01 23:16:41 by junjun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_map(t_map *map)
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

int	check_filename(const char *s)
{
	int len;
	
	len = ft_strlen(s);
	if (ft_strncmp(s + len - 4, ".fdf", 4) == 0)
		return (0);
	return (ft_printf("File name incorrect!\n"), 1);
}

int	check_width_height(int fd)
{
	
}

int	check_color(char *str)
{
	if (ft_strncmp(str, "0x", 2) == 0 || ft_strncmp(str, "0X", 2) == 0)
		return (0);
	return (ft_printf("Color incorrect!\n"), 1);
}

void map_error(int fd, t_map *map)
{
	close(fd);
	if (map)
		free_map(&map);
	free_map(map);	
	perror("Invalid map!\n");
	exit(EXIT_FAILURE);
}