/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junjun <junjun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 13:58:35 by junjun            #+#    #+#             */
/*   Updated: 2024/12/27 00:57:10 by junjun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void error_handle()
{
	//display mes
	//exit
}



int	check_file_name(char *s)
{
	int len;
	
	len = ft_strlen(s);
	if (ft_strncmp(s + len - 4, ".fdf", 4) == 0)
		return (ft_printf("File name correct.\n"), 0);
	return (ft_printf("File name incorrect!\n"), 1);
}



int main(int ac, char **av)
{
	int fd;
	t_fdf	fdf;
	
	//check
	if (ac != 2)
		return (ft_printf("Wrong arguments!\n"), 0);
	if (check_file_name(av[1]) != 0)
		return (0);

	//initi fdf
	map_init(av[1], fdf.map);
	fdf.mlx = mlx_init();
	if (fdf.mlx == NULL)
	{
		free_map(fdf.map);
		error_handle;
	}
	fdf.window = mlx_new_window(fdf.mlx, WIN_WIDTH, WIN_HEIGHT, "fdf");
	if (fdf.window == NULL)
	{
		free_map(fdf.map);
		mlx_clear_window(fdf.mlx, fdf.window);
		error_handle;
	}
	


	
	mlx_loop(mlx);
	mlx_destroy_window(mlx, mlx_win);
	mlx_destroy_display();
	free(mlx);

	free_map(&map);
	return(0);
	
}
