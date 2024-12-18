/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junjun <junjun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 13:58:35 by junjun            #+#    #+#             */
/*   Updated: 2024/12/17 17:50:24 by junjun           ###   ########.fr       */
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
	if (ac != 2)
	{
		return (0);
	}
	
	void *mlx;
	void *mlx_win;

	mlx = mlx_init();
	mlx_win = mlx_new_window()
	
}