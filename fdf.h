/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junjun <junjun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 13:49:41 by junjun            #+#    #+#             */
/*   Updated: 2025/01/02 02:22:40 by junjun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/libft.h"
# include "../minilibx/mlx.h"
//# include <MLX42/MLX42.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>

# ifndef WIN_WIDTH
#  define WIN_WIDTH 1000
# endif

# ifndef WIN_HEIGHT
#  define WIN_HEIGHT 800
# endif

# define RED			0xFF2222
# define GREEN			0x22FF22
# define BLUE			0x2222FF
# define PURPLE			0xFF22FF
# define WHITE			0xFFFFFF
# define BLACK			0x000000
# define GREY			0xAAAAAA
# define DGREY			0x444444

typedef struct s_map
{
	int		width;
	int		height;
	// double	interval;
	t_point	**grid;
}			t_map;

typedef struct s_point
{
	int		x;
	int		y;
	int		z;
	int		color;
}			t_point;

typedef struct s_line
{
	int		x1;
	int		y1;
	int		x2;
	int		y2;
	int		color;
	int		dx;
	int		dy;
	int		sx;
	int		sy;
	int		direc;
}			t_line;

typedef struct s_img
{
    void    *img;
    int     pbits;
    int     lbytes;
    int     endian;
    char    *buffer;
    int     width;
    int     height;
    t_point pos;
} t_img;

typedef struct s_fdf
{
	void	*mlx;
	void	*window;
	t_map	*map;
}t_fdf;

//check
int	check_file(int n, char *s);



//parsing file
void map_init(t_map *map);
int	check_color(char *str);
void	parse_map(char *file, t_map *map);

//draw line

//to 3d


//User events



//error and free
void	free_arr(char **arr);
void	map_error(int fd, t_map *map, char *msg);


int	ft_atoi_base(const char *str, int str_base);
void	to_lower(char *c);
void	malloc_grid(t_map *map);

#endif
