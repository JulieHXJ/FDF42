/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhuang <xhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 13:58:35 by junjun            #+#    #+#             */
/*   Updated: 2024/12/24 23:23:10 by xhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void error_handle()
{
	//display mes
	//exit
}

void free_table()
{
	
}







int main(int ac, char **av)
{
	int fd;
	t_map *map;
	
	if (ac != 2)
		return (0);
		
	// fd = open(av[1], O_RDONLY);
	// if (fd < 0)
	// {
	// 	ft_printf("Fail to open the file.\n");
	// 	//read error
	// }
	map_init(av[1], &map);

	
	void *mlx;
	void *mlx_win;

	mlx = mlx_init();
	mlx_win = mlx_new_window();



	free_map(&map);
	return(0);
	
}