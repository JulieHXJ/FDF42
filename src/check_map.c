/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junjun <junjun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 00:33:28 by junjun            #+#    #+#             */
/*   Updated: 2025/01/02 02:19:07 by junjun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_map(t_map *map)
{
	int i;

	i = 0;
	if (!map->grid || !map)
		return;
	while (i < map->height)
	{
		free(map->grid[i]);
		i++;
	}
	free(map->grid);
	map->grid = NULL;
}

int	check_file(int n, char *s)
{
	int	fd;
	int len;
	
	len = ft_strlen(s);
	if (n != 2)
	{
		ft_putstr_fd("Wrong arguments!\n", 1);
		exit(EXIT_FAILURE);
	}
	fd = open(s, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("Fail to open file!\n", 1);
		exit(EXIT_FAILURE);
	}
	if (ft_strncmp(s + len - 4, ".fdf", 4) != 0)
	{
		ft_putstr_fd("File name incorrect!\n", 1);
		exit(EXIT_FAILURE);
	}
	return (0);
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