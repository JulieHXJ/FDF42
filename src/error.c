/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhuang <xhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 23:13:58 by xhuang            #+#    #+#             */
/*   Updated: 2025/01/10 15:17:33 by xhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// Empty map (should not segfault if given to you)
// Map not rectangular (should not segfault if given to you)

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

void	free_map(t_map *map)
{
	int	i;

	i = 0;
	if (!map || !map->grid)
		return ;
	while (i < map->height)
	{
		free(map->grid[i]);
		i++;
	}
	free(map->grid);
	map->grid = NULL;
	free(map);
}

void	error_handle(int fd, t_map *map, char *msg)
{
	if (fd >= 0)
		close(fd);
	free_map(map);
	ft_putendl_fd(msg, 2);
	exit(EXIT_FAILURE);
}

void	free_fdf(t_fdf *fdf)
{
	if (!fdf)
		return ;
	if (fdf->img && fdf->img->mlx_img)
		mlx_delete_image(fdf->mlx, fdf->img->mlx_img);
	if (fdf->img)
		free(fdf->img);
	if (fdf->map)
		free_map(fdf->map);
	if (fdf->mlx)
		mlx_close_window(fdf->mlx);
	free(fdf);
}
