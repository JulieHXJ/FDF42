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

int	check_file_name(char *s)
{
	int len;
	len = ft_strlen(s);

	if (ft_strncmp(s + len - 4, ".fdf", 4) == 0)
	{
		return (ft_printf("File name correct.\n"), 0);
	}
	return (ft_printf("File name incorrect!\n"), 1);
}



int main(int ac, char **av)
{
	int fd;
	t_map *map;
	
	if (ac != 2)
		return (ft_printf("Wrong arguments!\n"), 0);
	if (check_file_name(av[1]) != 0)
	{
		return (0);
	}	
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
