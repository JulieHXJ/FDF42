/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junjun <junjun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 13:58:35 by junjun            #+#    #+#             */
/*   Updated: 2025/01/02 01:56:52 by junjun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_init(char *file, t_fdf *fdf)
{
	fdf->map = malloc(sizeof(t_map));
	if (!fdf->map)
	{
		// close(fd);
		// handle_error(MALLOC);
	}
	parse_map(file, fdf->map);
	fdf->mlx = mlx_init(WIN_WIDTH, WIN_HEIGHT, "fdf", true);
	if (fdf->mlx == NULL)
	{
		free_map(fdf->map);
		error_handle;
	}
	fdf->window = mlx_new_window(fdf->mlx, WIN_WIDTH, WIN_HEIGHT, "fdf");
	if (fdf->window == NULL)
	{
		free_map(fdf->map);
		mlx_clear_window(fdf->mlx, fdf->window);
		error_handle;
	}
	
}


int main(int ac, char **av)
{
	int fd;
	t_fdf	fdf;
	
	//check
	if (check_file(ac, av[1]) != 0)
		return (0);
	//initi fdf
	fdf.map = malloc(sizeof(t_map));
	if (/* condition */)
	{
		/* code */
	}
	//parsing
	fdf_init(av[1], &fdf);
	

	//reder
	
	// void	*mlx;
	// void	*mlx_win;
	// t_data	img;

	// mlx = mlx_init();
	// mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	// img.img = mlx_new_image(mlx, 1920, 1080);
	// img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
	// 							&img.endian);
	// ft_put_pixel(&img, WINDOW_WIDTH/2, WINDOW_HEIGHT/2, 0xFF0000);
	// mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	// mlx_loop(mlx);


	
	mlx_loop(mlx);
	mlx_destroy_window(mlx, mlx_win);
	mlx_destroy_display();
	free(mlx);

	free_map(fdf.map);
	return(0);
	
}
