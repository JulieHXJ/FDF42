/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junjun <junjun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 13:58:35 by junjun            #+#    #+#             */
/*   Updated: 2025/01/01 23:18:13 by junjun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"



void	fdf_init(char *file, t_fdf *fdf)
{
	parse_map(file, fdf->map);
	
}







int main(int ac, char **av)
{
	int fd;
	t_fdf	fdf;
	
	//check
	if (ac != 2 || check_filename(av[1]) != 0)
		return (ft_printf("Wrong input!\n"), 0);
	//initi fdf
	map_init(fdf.map);
	fdf_init(av[1], fdf.map);
	
	//parsing

	//reder
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
