/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junjun <junjun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 14:12:27 by junjun            #+#    #+#             */
/*   Updated: 2025/01/02 01:59:50 by junjun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <graphics.h>
#include <conio.h>
#include <stdio.h>
#include <math.h>


/*
Use Bresenham's line algorithm to draw lines between points.
Render horizontal and vertical lines connecting adjacent points.
Use color gradients for smooth transitions between points.
*/
void drow_line(t_line )
{
	float x,y,x1,y1,x2,y2,dx,dy,step;
	int i,gd = DETECT, gm;
	
// Step 1: Read the input of the 2 end points of the line as (x1, y1) & (x2, y2) such that x1 != x2 and y1 != y2
	initgraph(&gd,&gm,"c:\\turboc3\\bgi");

	printf("Enter the value of x1 and y1 : ");
	scanf("%f%f",&x1,&y1);
	printf("Enter the value of x2 and y2: ");
	scanf("%f%f",&x2,&y2);

// Step 2: Calculate dx = x2 – x1 and dy = y2 – y1
	dx = abs(x2-x1);
	dy = abs(y2-y1);

// Step 3:
	if(dx>=dy)
		step = dx;
	else
		step = dy;

// Step 4: xin = dx / step & yin = dy / step
	dx=dx/step;
	dy=dy/step;

// Step 5: x = x1 + 0.5 & y = y1 + 0.5
	x = x1;
	y = y1;

// Step 6: 
	i = 0;
	while(i < step)
	{
		ft_put_pixel(x,y,5);
		x=x+dx;
		y=y+dy;
		i=i+1;
		delay(100);
	}
	closegraph();
}