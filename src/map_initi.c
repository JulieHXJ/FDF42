/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_initi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhuang <xhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 13:58:26 by junjun            #+#    #+#             */
/*   Updated: 2024/12/18 18:24:47 by xhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	map_init(t_map *map);
{
	map->width = 0;
	map->height = 0;
}


int read_map(const int fd, t_map *map)
{
	char *line_str;
	char **line_arr;
	int i = 0;
	
	//malloc how many lines
	while (line_str = get_next_line(fd))
	{
		line_arr = ft_split(line_str, ' ');
		if (!line_arr)
		{
			//error and free
		}
		while (line_arr[i++])
		{
			map->width++;
		}
		free(line_arr);
		free(line_str);
		map->height++;
	}
	free(line_str);
	close(fd);
	return(0);
}


//get value of map
int  value = ft_atoi(line_arr[i]);














void map_error()
{
	//empty map
	//Map not rectangular 
}