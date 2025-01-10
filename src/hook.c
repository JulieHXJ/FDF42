/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhuang <xhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 15:05:42 by xhuang            #+#    #+#             */
/*   Updated: 2025/01/10 16:04:50 by xhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/* handle keypress like: exit, zoom in/out and moving the map
mouse events: Rotation: Adjust angles for x, y, z rotation.
*/

void	handle_key(mlx_key_data_t key, void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)param;
	if (key.action != MLX_PRESS)
		return ;
	if (key.key == MLX_KEY_ESCAPE)
	{
		printf("Esc pressed\n");
		mlx_close_window(fdf->mlx);
		return ;
	}
	if (key.key == MLX_KEY_UP)
	{
		fdf->img->alpha += 0.05;
	}
	else if (key.key == MLX_KEY_DOWN)
	{
		fdf->img->alpha -= 0.05;
	}
	else if (key.key == MLX_KEY_LEFT)
		fdf->img->beta -= 0.05;
	else if (key.key == MLX_KEY_RIGHT)
		fdf->img->beta += 0.05;
}

void	mouse_scroll(double xdelta, double ydelta, void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)param;
	(void)xdelta;
	if (ydelta < 0)
	{
		fdf->img->zoom += 1;
		printf("Scrolling down\n");
	}
	else if (ydelta > 0)
	{
		printf("Scrolling up\n");
		fdf->img->zoom -= 1;
	}
}

// void	loop_hook_function(void *param)
// {
// 	t_fdf *fdf = (t_fdf *)param;

	//for rendering
	// if (fdf->img->mlx_img)
	// 		mlx_delete_image(fdf->mlx, fdf->img->mlx_img);
	// 	fdf->img->mlx_img = mlx_new_image(fdf->mlx, WIN_WIDTH, WIN_HEIGHT);
	// 	if (!fdf->img->mlx_img)
	// 	{
	// 		printf("Failed to create new image\n");
	// 		return ;
	// 	}
	// 	draw_map(fdf);
	// 	mlx_image_to_window(fdf->mlx, fdf->img->mlx_img, 0, 0);
// }
