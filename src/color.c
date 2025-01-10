/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhuang <xhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 15:08:11 by xhuang            #+#    #+#             */
/*   Updated: 2025/01/10 15:22:52 by xhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	ft_atoi_base(const char *str, int base)
{
	int	res;
	int	sign;
	int	i;
	int	c;

	res = 0;
	sign = 1;
	i = -1;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	while (str[++i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			c = str[i] - '0';
		else if (str[i] >= 'A' && str[i] <= 'F')
			c = str[i] - 'A' + 10;
		else
			break ;
		res = res * base + c;
	}
	return (res * sign);
}

static char	*to_upper(char *c)
{
	while (*c)
	{
		ft_toupper(*c);
		c++;
	}
	return (c);
}

int	check_color(char *str)
{
	if (ft_strncmp(str, "0x", 2) == 0 || ft_strncmp(str, "0X", 2) == 0)
		return (0);
	return (1);
}

int	get_color(int fd, t_map *map, char *s)
{
	int	i;

	i = ft_atoi(s);
	while (*s == '-')
		s++;
	while (ft_isdigit(*s))
		s++;
	if ((!*s || *s != ','))
	{
		if (i <= 0)
			return (WHITE);
		return (WHITE);
	}
	s++;
	if (check_color(s))
		return (error_handle(fd, map, "Color incorrect!"), -1);
	s = s + 2;
	to_upper(s);
	return (ft_atoi_base(s, 16) << 8 | 0xFF);
}

// int	interpolate_color(int color1, int color2, double ratio)
// {
// 	int	alpha;
// 	int	red;
// 	int	green;
// 	int	blue;

// 	if (color1 == color2)
// 		return (color1);
// 	alpha = (int)(((color2 >> 24) & 0xFF) * ratio + ((color1 >> 24) & 0xFF) * (1
// 				- ratio));
// 	red = (int)(((color2 >> 16) & 0xFF) * ratio + ((color1 >> 16) & 0xFF) * (1
// 				- ratio));
// 	green = (int)(((color2 >> 8) & 0xFF) * ratio + ((color1 >> 8) & 0xFF) * (1
// 				- ratio));
// 	blue = (int)((color2 & 0xFF) * ratio + (color1 & 0xFF) * (1 - ratio));
// 	return ((alpha << 24) | (red << 16) | (green << 8) | blue);
// }
