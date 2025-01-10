/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhuang <xhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 13:58:35 by junjun            #+#    #+#             */
/*   Updated: 2025/01/10 16:08:00 by xhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	check_file(int n, char *s)
{
	int	fd;
	int	len;

	len = ft_strlen(s);
	if (n != 2)
	{
		perror("Wrong arguments!\n");
		exit(EXIT_FAILURE);
	}
	if (len < 4 || ft_strncmp(s + len - 4, ".fdf", 4) != 0)
	{
		perror("File name incorrect!\n");
		exit(EXIT_FAILURE);
	}
	fd = open(s, O_RDONLY);
	if (fd < 0)
	{
		perror("Fail to open file!\n");
		exit(EXIT_FAILURE);
	}
	close(fd);
	return (0);
}

void	map_init(t_map *map)
{
	map->width = 0;
	map->height = 0;
	map->grid = NULL;
}

static void	img_init(t_fdf *fdf)
{
	fdf->img = malloc(sizeof(t_img));
	if (!fdf->img)
	{
		mlx_close_window(fdf->mlx);
		exit(EXIT_FAILURE);
	}
	fdf->img->mlx_img = mlx_new_image(fdf->mlx, WIN_WIDTH, WIN_HEIGHT);
	if (!fdf->img->mlx_img)
	{
		free(fdf->img);
		mlx_close_window(fdf->mlx);
		exit(EXIT_FAILURE);
	}
	fdf->img->zoom = 10.0;
	fdf->img->x_offset = 0;
	fdf->img->y_offset = 0;
	fdf->img->alpha = 0;
	fdf->img->beta = 0;
	fdf->img->z_scale = 1.0;
	fdf->img->mouse_pressed = false;
	fdf->img->pos.x = 0;
	fdf->img->pos.y = 0;
}

// void	check_leaks(void)
// {
// 	system("leaks fdf");
//	atexit(check_leaks);
// }

int	main(int ac, char **av)
{
	t_fdf	*fdf;

	if (check_file(ac, av[1]) != 0)
		return (EXIT_FAILURE);
	fdf = malloc(sizeof(t_fdf));
	if (!fdf)
		return (EXIT_FAILURE);
	fdf->mlx = mlx_init(WIN_WIDTH, WIN_HEIGHT, "My FDF", true);
	if (!fdf->mlx)
		return (free_fdf(fdf), EXIT_FAILURE);
	fdf->map = malloc(sizeof(t_map));
	if (!fdf->map || read_map(av[1], fdf->map) != 0)
		return (mlx_terminate(fdf->mlx), free_fdf(fdf), EXIT_FAILURE);
	img_init(fdf);
	draw_map(fdf);
	mlx_image_to_window(fdf->mlx, fdf->img->mlx_img, 0, 0);
	mlx_key_hook(fdf->mlx, handle_key, fdf);
	mlx_scroll_hook(fdf->mlx, mouse_scroll, fdf);
	mlx_loop(fdf->mlx);
	mlx_terminate(fdf->mlx);
	return (free_fdf(fdf), EXIT_SUCCESS);
}
