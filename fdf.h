/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhuang <xhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 13:49:41 by junjun            #+#    #+#             */
/*   Updated: 2025/01/10 16:18:00 by xhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "lib/MLX42/include/MLX42/MLX42.h"
# include "lib/libft/libft.h"
# include <fcntl.h>
# include <limits.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>

// define window size
# define WIN_WIDTH 800
# define WIN_HEIGHT 600

// color
# define RED 0xFF0000FF
# define PURPLE 0x800080FF
# define BLUE 0x0000FFFF
# define GREEN 0x00FF00FF
# define WHITE 0xFFFFFFFF
# define BLACK 0x000000FF
# define YELLOW 0xFFFF00FF

typedef struct s_point
{
	int			x;
	int			y;
	int			z;
	int			color;
}				t_point;

typedef struct s_map
{
	int			width;
	int			height;
	t_point		**grid;
}				t_map;

typedef struct s_line
{
	t_point		cur;
	int			delta_x;
	int			delta_y;
	int			step_x;
	int			step_y;
	int			err;
}				t_line;

typedef struct s_img
{
	mlx_image_t	*mlx_img;
	double		zoom;
	int			x_offset;
	int			y_offset;
	double		alpha;
	double		beta;
	double		z_scale;
	bool		mouse_pressed;
	t_point		pos;
}				t_img;

typedef struct s_fdf
{
	mlx_t		*mlx;
	void		*window;
	t_map		*map;
	t_img		*img;
}				t_fdf;

// parsing file
void			map_init(t_map *map);
int				read_map(char *file, t_map *map);
int				get_color(int fd, t_map *map, char *s);

// set color
// t_point	find_top(t_map *map);
// t_point	find_bottom(t_map *map);
// int	interpolate_color(int color1, int color2, double ratio);

// draw 3d
void			set_zoom(t_map *map, t_img *img);
void			center_map(t_map *map, t_img *img);
void			draw_map(t_fdf *fdf);

// User events
void			handle_key(mlx_key_data_t key, void *param);
void			mouse_scroll(double xdelta, double ydelta, void *param);

// error and free
void			free_arr(char **arr);
void			free_map(t_map *map);
void			free_fdf(t_fdf *fdf);
void			error_handle(int fd, t_map *map, char *msg);

#endif
